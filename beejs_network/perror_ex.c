#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    int s;
    s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1) { // some error has occurred
        // prints "socket error: " + the error message:
        perror("socket error");
    }
    // similarly:
    if (listen(s, 10) == -1) {
        // this prints "an error: " + the error message from errno:
        printf("an error: %s\n", strerror(errno));
    }
}