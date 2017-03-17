//
// Created by Timothy Shull on 1/4/16.
//

#include <stdio.h>
#include <sys/fcntl.h>
#include "3_10.h"

void print_flags_for_fd(int i) {
    int val;

    if ((val = fcntl(i, F_GETFL, 0) < 0))
        fprintf(stderr, "fcntl error for fd: %d", i);

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            fprintf(stdout, "read only");
            break;
        case O_WRONLY:
            fprintf(stdout, "write only");
            break;
        case O_RDWR:
            fprintf(stdout, "read write");
            break;
        default:
            fprintf(stderr, "unknown access mode");
    }

    if (val & O_APPEND)
        fprintf(stdout, ", append");
    if (val & O_NONBLOCK)
        fprintf(stdout, ", nonblocking");
#if defined(O_SYNC)
    if (val & O_SYNC)
        fprintf(stdout, ", synchronous writes");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if (val & O_FSYNC)
        fprintf(stdout, ", synchronous writes");
#endif
    fprintf(stdout, "\n");
}
