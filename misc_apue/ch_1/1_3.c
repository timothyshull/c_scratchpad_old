//
// Created by Timothy Shull on 1/2/16.
//

#include "1_3.h"
#include <stddef.h>
#include <apue.h>

void my_ls(char* dir) {
    DIR* dp;
    struct dirent* dirp;

    if ((dp = opendir(dir)) == NULL)
        err_sys("Unable to open %s", dir);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
}
