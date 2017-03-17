#include <stdlib.h>
#include "libioP.h"
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

#define CLOSED_FILEBUF_FLAGS (0x2000 + 4 + 8 + 0x400)

typedef struct _IO_FILE {
    int _flags;        /* High-order word is _IO_MAGIC; rest is flags. */
    /* The following pointers correspond to the C++ streambuf protocol. */
    /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
    char *_IO_read_ptr;    /* Current read pointer */
    char *_IO_read_end;    /* End of get area. */
    char *_IO_read_base;    /* Start of putback+get area. */
    char *_IO_write_base;    /* Start of put area. */
    char *_IO_write_ptr;    /* Current put pointer. */
    char *_IO_write_end;    /* End of put area. */
    char *_IO_buf_base;    /* Start of reserve area. */
    char *_IO_buf_end;    /* End of reserve area. */
    /* The following fields are used to support backing up and undo. */
    char *_IO_save_base; /* Pointer to start of non-current get area. */
    char *_IO_backup_base;  /* Pointer to first valid character of backup area */
    char *_IO_save_end; /* Pointer to end of non-current get area. */

    struct _IO_marker *_markers;

    struct _IO_FILE *_chain;

    int _fileno;
    int _blksize;
    int _flags2;
    off_t _old_offset; /* This used to be _offset but it's too small.  */

    /* 1+column number of pbase(); 0 is unknown. */
    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];

    /*  char* _save_gptr;  char* _save_egptr; */

    pthread_rwlock_t *_lock; // pthread_mutex_t ?
    off_t _offset; // __off64_t
    /* Wide character stream stuff.  */
    struct _IO_codecvt *_codecvt;
    struct _IO_wide_data *_wide_data;
    struct _IO_FILE *_freeres_list;
    void *_freeres_buf;
    size_t __pad5;
    int _mode;
} IO_FILE;


typedef struct _FILE {
    unsigned char *_p;    /* current position in (some) buffer */
    int _r;        /* read space left for getc() */
    int _w;        /* write space left for putc() */
    short _flags;        /* flags, below; this FILE is free if 0 */
    short _file;        /* fileno, if Unix descriptor, else -1 */
    struct __sbuf _bf;    /* the buffer (at least 1 byte, if !NULL) */
    int _lbfsize;    /* 0 or -_bf._size, for inline putc */

    /* operations */
    void *_cookie;    /* cookie passed to io functions */
    int (*_close)(void *);

    int (*_read)(void *, char *, int);

    fpos_t (*_seek)(void *, fpos_t, int);

    int (*_write)(void *, const char *, int);

    /* separate buffer for long sequences of ungetc() */
    struct __sbuf _ub;    /* ungetc buffer */
    struct __sFILEX *_extra; /* additions to FILE to not break ABI */
    int _ur;        /* saved _r when _r is counting ungetc data */

    /* tricks to meet minimum requirements even when malloc() fails */
    unsigned char _ubuf[3];    /* guarantee an ungetc() buffer */
    unsigned char _nbuf[1];    /* guarantee a getc() buffer */

    /* separate buffer for fgetln() when line crosses buffer boundary */
    struct __sbuf _lb;    /* buffer for fgetln() */

    /* Unix stdio files get aligned to block boundaries on fseek() */
    int _blksize;    /* stat.st_blksize (may be != _bf._size) */
    fpos_t _offset;    /* current lseek offset (see WARNING) */
} FILE;


void IO_link_in(struct IO_FILE *fp) {
    if ((fp->file._flags & 0x80) == 0) {
        fp->file._flags |= 0x80;
        fp->file._chain = (IO_FILE *) _IO_list_all;
        _IO_list_all = fp;
        ++_IO_list_all_stamp;
    }
}

void IO_new_file_init_internal(struct IO_FILE *fp) {
    fp->file._offset = 0;
    fp->file._IO_file_flags |= CLOSED_FILEBUF_FLAGS;
    IO_link_in(fp);
    fp->file._fileno = -1;
}

ssize_t io_getdelim(char **lineptr, size_t *n, int delimiter, IO_FILE *fp) {
    ssize_t result;
    ssize_t cur_len = 0;
    ssize_t len;

    if (lineptr == NULL || n == NULL) {
        return -1;
    }

    int lock_result = pthread_rwlock_rdlock(&rwlock);
    if (lock_result != 0) {
        pthread_rwlock_unlock(&rwlock);
        return -1;
    }

    if (*lineptr == NULL || *n == 0) {
        *n = 120;
        *lineptr = (char *) malloc(*n);
        if (*lineptr == NULL) {
            pthread_rwlock_unlock(&rwlock);
            return -1;
        }
    }

    len = fp->_IO_read_end - fp->_IO_read_ptr;
    if (len <= 0) {
        len = fp->_IO_read_end - fp->_IO_read_ptr;
    }

    for (;;) {
        size_t needed;
        char *t;
        t = (char *) memchr((void *) fp->_IO_read_ptr, delimiter, (size_t) len);
        if (t != NULL)
            len = (t - fp->_IO_read_ptr) + 1;
        if (len >= SSIZE_MAX - cur_len) {
            errno = EOVERFLOW;
            pthread_rwlock_unlock(&rwlock);
            return -1;
        }
        /* Make enough space for len+1 (for final NUL) bytes.  */
        needed = (size_t) (cur_len + len + 1);
        if (needed > *n) {
            char *new_lineptr;

            if (needed < 2 * *n)
                needed = 2 * *n;  /* Be generous. */
            new_lineptr = (char *) realloc(*lineptr, needed);
            if (new_lineptr == NULL) {
                pthread_rwlock_unlock(&rwlock);
                return -1;
            }
            *lineptr = new_lineptr;
            *n = needed;
        }
        memcpy (*lineptr + cur_len, (void *) fp->_IO_read_ptr, len);
        fp->_IO_read_ptr += len;
        cur_len += len;
        if (t != NULL)
            break;
        len = fp->_IO_read_end - fp->_IO_read_ptr;
    }
    (*lineptr)[cur_len] = '\0';
    result = cur_len;

    pthread_rwlock_unlock(&rwlock);
    return result;
}
