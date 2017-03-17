//
// Created by Timothy Shull on 1/3/16.
//

#include "fill_files.h"
#include <sys/fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void fill_files(char* filename, char* text, int num_per_line, int num_lines) {
    int fd;
    const int len = (int) strlen(text) * num_per_line;
    char line[len];
    int open_flags = (O_WRONLY | O_CREAT | O_TRUNC);
    mode_t open_mode = (O_APPEND | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    strncpy(line, "", sizeof(line));

    if ((fd = open(filename, open_flags, open_mode)) < 0)
        fprintf(stderr, "Error opening file: %s\n", filename);

    for (int i = 0; i < num_per_line; i++)
        strcat(line, text);

    strcat(line, "\n");

    size_t sz = strlen(line);

    for (int i = 0; i < num_lines; i++) {
        if (write(fd, line, sz) != sz)
            fprintf(stderr, "Error writing buffer of size: %d\n", (int) sz);
    }

    close(fd);
}