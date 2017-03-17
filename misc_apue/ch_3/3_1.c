//
// Created by Timothy Shull on 1/2/16.
//

#include <stdio.h>
#include <unistd.h>

int is_stdio_seekable() {
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("STDIN is not lseekable\n");
        return (0);
    } else {
        printf("STDIN is lseekable\n");
        return (1);
    }
}
