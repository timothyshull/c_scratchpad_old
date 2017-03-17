#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
    if (filedesc < 0)
        return 1;

    if (write(filedesc, "This will be output to testfile.txt\n", 36) != 36) {
        write(2, "There was an error writing to testfile.txt\n", 36);
        return 1;
    }

    printf("%d\n", filedesc);

    return 0;
}