#include <netdb.h>
#include <string.h>
#include <printf.h>
#include <arpa/inet.h>

int main()
{
    // datagram sockets and recvfrom()
    struct addrinfo hints, * res;
    int sockfd;
    int byte_count;
    socklen_t fromlen;
    struct sockaddr_storage addr;
    char buf[512];
    char ipstr[INET6_ADDRSTRLEN];
    // get host info, make socket, bind it to port 4950
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, "4950", &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    // no need to accept(), just recvfrom():
    fromlen = sizeof addr;
    byte_count = recvfrom(sockfd, buf, sizeof buf, 0, &addr, &fromlen);
    printf("recv()'d %d bytes of data in buf\n", byte_count);
    printf("from IP address %s\n",
           inet_ntop(addr.ss_family,
                     addr.ss_family == AF_INET ?
                     ((struct sockadd_in*) &addr)->sin_addr :
                     ((struct sockadd_in6*) &addr)->sin6_addr,
                     ipstr, sizeof ipstr));
}