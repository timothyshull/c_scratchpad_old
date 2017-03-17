//
// Created by Timothy Shull on 1/17/16.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2)
        fprintf(stderr, "Usage: a.out <pathname>");
    if (access(argv[1], R_OK) < 0)
        fprintf(stderr, "Access error for %s", argv[1]);
    else
        fprintf(stdout, "read access OK\n");
    if (open(argv[1], O_RDONLY) < 0)
        fprintf(stderr, "Open error for %s", argv[1]);
    else
        fprintf(stdout, "Open for reading");
    exit(0);
}