//
// Created by Timothy Shull on 1/4/16.
//

#include "4_3.h"
#include <sys/stat.h>
#include <stdio.h>

void print_file_type(char* filename) {
    struct stat buf;
    char* ptr;

    fprintf(stdout, "%s: \n", filename);

    if (lstat(filename, &buf) < 0) {
        fprintf(stderr, "lstat error");
        return;
    }
    if (S_ISREG(buf.st_mode))
        ptr = "regular";
    else if (S_ISDIR(buf.st_mode))
        ptr = "directory";
    else if (S_ISCHR(buf.st_mode))
        ptr = "character special";
    else if (S_ISBLK(buf.st_mode))
        ptr = "block special";
    else if (S_ISFIFO(buf.st_mode))
        ptr = "fifo";
    else if (S_ISLNK(buf.st_mode))
        ptr = "symbolic link";
    else if (S_ISSOCK(buf.st_mode))
        ptr = "socket";
    else
        ptr = "** unknown mode **";
    fprintf(stdout, ("%s\n", ptr);
}
