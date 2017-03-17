//
// Created by Timothy Shull on 1/17/16.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (chdir("/tmp") < 0)
        fprintf(stderr, "chdir failed");
    printf("chdir to /tmp succeeded\n");
    exit(0);
}