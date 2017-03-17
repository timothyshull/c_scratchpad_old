//
// Created by Timothy Shull on 1/4/16.
//

#include "3_11.h"
#include <stdio.h>
#include <sys/fcntl.h>

void turn_on_flags(int fd, int flags) {
    int val;

    if ((val = fcntl(i, F_GETFL, 0) < 0))
        fprintf(stderr, "fcntl error: F_GETFL error");

    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0)
        fprintf(stderr, "fcntl error: F_SETFL error");
}
