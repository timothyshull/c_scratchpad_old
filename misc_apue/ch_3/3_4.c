//
// Created by Timothy Shull on 1/2/16.
//

//1
//2
//4
//8
//16
//32
//64
//128
//256
//512
//1024
//2048
//4096
//8192
//16384
//32768
//131072
//262144
//524288

#include "3_4.h"
#include "apue.h"


void copy_stdin_to_stdout() {
    size_t BUFFSIZE = 524288;
    ssize_t n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, (size_t)n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");
}
