//
// Created by Timothy Shull on 1/17/16.
//

#include <sys/stat.h>
#include <stdio.h>
#include <utime.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, fd;
    struct stat statbuf;
    struct utimbuf timebuf;

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            fprintf(stderr, "%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
            fprintf(stderr, "%s: open error", argv[i]);
            continue;
        }
        close(fd);
        timebuf.actime = statbuf.st_atime;
        timebuf.modtime = statbuf.st_mtime;
        if (utime(argv[i], &timebuf) < 0) {
            fprintf(stderr, "%s: utime error", argv[i]);
            continue;
        }
    }
    exit(0);
}