#include <stddef.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

#ifdef EINTR
# define IS_EINTR(x) ((x) == EINTR)
#else
# define IS_EINTR(x) 0
#endif

#undef const
#define const /* empty */

static void next_line_num(void) {
    char *endp = line_num_end;
    do {
        if ((*endp)++ < '9')
            return;
        *endp-- = '0';
    } while (endp >= line_num_start);
    if (line_num_start > line_buf)
        *--line_num_start = '1';
    else
        *line_buf = '>';
    if (line_num_start < line_num_print)
        line_num_print--;
}

/* Plain cat.  Copies the file behind `input_desc' to STDOUT_FILENO.
   Return true if successful.  */
/* char *buf - Pointer to the buffer, used by reads and writes. */
/* size_t bufsize - Number of characters preferably read or written by each read and write call. */
static bool simple_cat(char *buf, size_t bufsize) {
    /* Actual number of characters read, and therefore written.  */
    size_t n_read;

    /* Loop until the end of the file.  */

    while (true) {
        /* Read a block of input.  */

        n_read = safe_read(input_desc, buf, bufsize);
        if (n_read == SAFE_READ_ERROR) {
            error(0, errno, "%s", infile);
            return false;
        }

        /* End of this file?  */

        if (n_read == 0)
            return true;

        /* Write this block out.  */

        {
            /* The following is ok, since we know that 0 < n_read.  */
            size_t n = n_read;
            if (full_write(STDOUT_FILENO, buf, n) != n)
                error(EXIT_FAILURE, errno, _("write error"));
        }
    }
}


size_t safe_read(int fd, void const *buf, size_t count) {
    for (;;) {
        ssize_t result = read(fd, buf, count);

        if (0 <= result)
            return (size_t) result;
        else if (IS_EINTR (errno))
            continue;
        else
            return (size_t) result;
    }
}



