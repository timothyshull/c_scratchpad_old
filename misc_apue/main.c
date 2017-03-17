#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    char resolved_path[100];
    realpath("./myfile.txt", resolved_path);
    printf("%s\n",resolved_path);

    int filedesc = creat(resolved_path, O_APPEND);
    if (filedesc < 0)
        return 1;

    if (write(filedesc, "This will be output to testfile.txt\n", 36) != 36) {
        write(2, "There was an error writing to testfile.txt\n", 36);
        return 1;
    }

    printf("%d\n", filedesc);

    return 0;
}