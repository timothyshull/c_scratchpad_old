#include <sys/socket.h>
#include <netinet6/in6.h>
#include <arpa/inet.h>
#include <printf.h>

int main()
{
    // assume s is a connected socket
    socklen_t len;
    struct sockaddr_storage addr;
    char ipstr[INET6_ADDRSTRLEN];
    int port;
    len = sizeof addr;
    getpeername(s, (struct sockaddr*) &addr, &len);
    // deal with both IPv4 and IPv6:
    if (addr.ss_family == AF_INET) {
        struct sockaddr_in* s = (struct sockaddr_in*) &addr;
        port = ntohs(s->sin_port);
        inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
    } else { // AF_INET6
        struct sockaddr_in6* s = (struct sockaddr_in6*) &addr;
        port = ntohs(s->sin6_port);
        inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
    }
    printf("Peer IP address: %s\n", ipstr);
    printf("Peer port      : %d\n", port);
}