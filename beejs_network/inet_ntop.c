#include <arpa/inet.h>
#include <string.h>
#include <printf.h>

// Helper function you can use:
// Convert a struct sockaddr address to a string, IPv4 and IPv6:
char* get_ip_str(const struct sockaddr* sa, char* s, size_t maxlen)
{
    switch (sa->sa_family) {
        case AF_INET:
            inet_ntop(AF_INET, &(((struct sockaddr_in*) sa)->sin_addr), s, maxlen);
            break;
        case AF_INET6:
            inet_ntop(AF_INET6, &(((struct sockaddr_in6*) sa)->sin6_addr), s, maxlen);
            break;
        default:
            strncpy(s, "Unknown AF", maxlen);
            return NULL;
    }
    return s;
}

int main()
{
    // IPv4 demo of inet_ntop() and inet_pton()
    struct sockaddr_in sa;
    char str[INET_ADDRSTRLEN];
    // store this IP address in sa:
    inet_pton(AF_INET, "192.0.2.33", &(sa.sin_addr));
    // now get it back and print it
    inet_ntop(AF_INET, &(sa.sin_addr), str, INET_ADDRSTRLEN);
    printf("%s\n", str); // prints "192.0.2.33"

    // IPv6 demo of inet_ntop() and inet_pton()
    // (basically the same except with a bunch of 6s thrown around)
    struct sockaddr_in6 sa;
    char str[INET6_ADDRSTRLEN];
    // store this IP address in sa:
    inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &(sa.sin6_addr));
    // now get it back and print it
    inet_ntop(AF_INET6, &(sa.sin6_addr), str, INET6_ADDRSTRLEN);
    printf("%s\n", str); // prints "2001:db8:8714:3a90::12"
}