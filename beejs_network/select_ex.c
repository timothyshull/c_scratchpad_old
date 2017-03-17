#include <sys/select.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/socket.h>

int main()
{
    int s1, s2, n;
    fd_set readfds;
    struct timeval tv;
    char buf1[256], buf2[256];
    // pretend we've connected both to a server at this point
    //s1 = socket(...);
    //s2 = socket(...);
    //connect(s1, ...)...
    //connect(s2, ...)...
    // clear the set ahead of time
    FD_ZERO(&readfds);
    // add our descriptors to the set
    FD_SET(s1, &readfds);
    FD_SET(s2, &readfds);
    // since we got s2 second, it's the "greater", so we use that for
    // the n param in select()
    n = s2 + 1;
    // wait until either socket has data ready to be recv()d (timeout 10.5 secs)
    tv.tv_sec = 10;
    tv.tv_usec = 500000;
    int rv = select(n, &readfds, NULL, NULL, &tv);
    if (rv == -1) {
        perror("select"); // error occurred in select()
    } else if (rv == 0) {
        printf("Timeout occurred!  No data after 10.5 seconds.\n");
    } else {
        // one or both of the descriptors have data
        if (FD_ISSET(s1, &readfds)) {
            recv(s1, buf1, sizeof buf1, 0);
        }
        if (FD_ISSET(s2, &readfds)) {
            recv(s2, buf2, sizeof buf2, 0);
        }
    }
}