#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <printf.h>

int main()
{
    // stream sockets and recv()
    struct addrinfo hints, * res;
    int sockfd;
    char buf[512];
    int byte_count;
    // get host info, make socket, and connect it
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo("www.example.com", "3490", &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(sockfd, res->ai_addr, res->ai_addrlen);
    // all right!  now that we're connected, we can receive some data!
    byte_count = recv(sockfd, buf, sizeof buf, 0);
    printf("recv()'d %d bytes of data in buf\n", byte_count);
}