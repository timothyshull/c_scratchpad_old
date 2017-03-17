//
// Created by Timothy Shull on 1/2/16.
//

#include "1_3.h"
#include <apue.h>

int main(int argc, char* argv[]) {
    if (argc != 2)
        err_quit("Usage: ls directory_name");

    my_ls(argv[1]);

    exit(0);
}