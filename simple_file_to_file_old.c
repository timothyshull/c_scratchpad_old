#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}


char *cp_getline(void) {
    const size_t size_increment = 10;
    char *buffer = malloc(size_increment);
    char *current_position = buffer;
    size_t maximum_length = size_increment;
    size_t length = 0;
    int character;
    if (current_position == NULL) { return NULL; }
    while (1) {
        character = fgetc(stdin);
        if (character == '\n') { break; }
        if (++length >= maximum_length) {
            char *new_buffer = realloc(buffer, maximum_length += size_increment);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            current_position = new_buffer + (current_position - buffer);
            buffer = new_buffer;
        }
        *current_position++ = (char) character;
    }
    *current_position = '\0';
    return buffer;
}


int copy_file(char *input_filename, char *output_filename) {
//    void *src, *dst;
//    size_t copysz;
    struct stat st_obj;
//    off_t fsz = 0;

    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        static char error_message[50];
        sprintf(error_message, "Unable to open %s for reading. Exiting ...", input_filename);
        perror(error_message);
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        static char error_message[50];
        sprintf(error_message, "Unable to create %s for writing. Exiting ...", output_filename);
        perror(error_message);
        exit(1);
    }

    // get the input file size
    if (fstat(input_file->_file, &st_obj) < 0) {
        perror("Unable to stat the input file. Exiting ...");
        exit(1);
    }

    // set the output file size
    if (ftruncate(output_file->_file, st_obj.st_size) < 0) {
        perror("Unable to set the output file size. Exiting ...");
        exit(1);
    }

    int character;
    for (;;) {
        character = fgetc(input_file);
        if (character == EOF) {
            break;
        }
        fputc(character, output_file);
    }
    printf("Successfully copied all characters from input file to output file.");
    return 0;
}


int main(int argc, char **argv) {
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;

    opterr = 0;

    static const struct option longopts[] = {
            {"input_file", required_argument, NULL, 'i'},
            {"outpu_file", required_argument, NULL, 'o'},
            {NULL,         0,                 NULL, 0}
    };


    while ((c = getopt_long(argc, argv, "i:o:", longopts, NULL)) != -1) {
        switch (c) {
            case 'i':
                if (optarg)
                    printf("a: %s\n", optarg);
                break;
            case 'o':
                if (optarg)
                    printf("b: %s\n", optarg);
                break;
            case '?':
                if (optopt == 'c')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                exit();
        }
    }

    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
    return 0;
}


//#include "apue.h"
//#include <fcntl.h>
//#include <sys/mman.h>

#define COPYINCR (1024*1024*1024)    /* 1 GB */

int other_main(int argc, char *argv[]) {
    int fdin, fdout;
    void *src, *dst;
    size_t copysz;
    struct stat sbuf;
    off_t fsz = 0;

    if (argc != 3)
        err_quit("usage: %s <fromfile> <tofile>", argv[0]);

    if ((fdin = open(argv[1], O_RDONLY)) < 0)
        err_sys("can't open %s for reading", argv[1]);

    if ((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
        err_sys("can't creat %s for writing", argv[2]);

    if (fstat(fdin, &sbuf) < 0)            /* need size of input file */
        err_sys("fstat error");

    if (ftruncate(fdout, sbuf.st_size) < 0)    /* set output file size */
        err_sys("ftruncate error");

    while (fsz < sbuf.st_size) {
        if ((sbuf.st_size - fsz) > COPYINCR)
            copysz = COPYINCR;
        else
            copysz = sbuf.st_size - fsz;

        if ((src = mmap(0, copysz, PROT_READ, MAP_SHARED,
                        fdin, fsz)) == MAP_FAILED)
            err_sys("mmap error for input");
        if ((dst = mmap(0, copysz, PROT_READ | PROT_WRITE,
                        MAP_SHARED, fdout, fsz)) == MAP_FAILED)
            err_sys("mmap error for output");

        memcpy(dst, src, copysz);    /* does the file copy */
        munmap(src, copysz);
        munmap(dst, copysz);
        fsz += copysz;
    }
    exit(0);
}
