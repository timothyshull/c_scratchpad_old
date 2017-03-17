//
// Created by Timothy Shull on 1/17/16.
//

#include <unistd.h>
#include <stdio.h>
#include <apue.h>

int
main(void) {
    char* ptr;
    size_t size;

    if (chdir("/usr/spool/uucppublic") < 0)
        fprintf(stderr, "chdir failed");

    ptr = path_alloc(&size);

    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
    exit(0);
}