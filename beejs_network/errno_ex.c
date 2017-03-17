#include <sys/socket.h>
#include <stdio.h>
#include <sys/select.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        perror("socket"); // or use strerror()
    }
    tryagain:
    int n;
    fd_set readfds;
    if (select(n, &readfds, NULL, NULL, NULL) == -1) { // not sure if timeval can be NULL
        // an error has occurred!!
        // if we were only interrupted, just restart the select() call:
        if (errno == EINTR) { goto tryagain; }  // AAAA!  goto!!!
        // otherwise it's a more serious error:
        perror("select");
        exit(1);
    }
}