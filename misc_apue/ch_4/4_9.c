//
// Created by Timothy Shull on 1/17/16.
//

#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void) {
    umask(0);
    if (creat("foo", RWRWRW) < 0)
        fprintf(stderr, "creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
        fprintf(stderr, "creat error for bar");
    exit(0);
}