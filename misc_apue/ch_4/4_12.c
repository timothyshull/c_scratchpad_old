//
// Created by Timothy Shull on 1/17/16.
//

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0)
        fprintf(stderr, "stat error for foo");

    if (chmod("foo", (mode_t) ((statbuf.st_mode & ~S_IXGRP) | S_ISGID)) < 0)
        fprintf(stderr, "chmod error for foo");

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        fprintf(stderr, "chmod error for bar");

    exit(0);
}