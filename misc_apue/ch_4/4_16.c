//
// Created by Timothy Shull on 1/17/16.
//

#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    if (open("tempfile", O_RDWR) < 0)
        fprintf(stderr, "open error");
    if (unlink("tempfile") < 0)
        fprintf(stderr, "unlink error");

    fprintf(stdout, "file unlinked\n");
    sleep(15);
    fprintf(stdout, "done\n");
    exit(0);
}