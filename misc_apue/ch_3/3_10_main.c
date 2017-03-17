//
// Created by Timothy Shull on 1/4/16.
//

#include "3_10.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2)
        fprintf(stderr, "usage: 3_10 <descriptor#>");

    print_flags_for_fd(atoi(argv[1]));
    exit(0);
}