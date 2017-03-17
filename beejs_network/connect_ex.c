#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

int main() {
    // connect to www.example.com port 80 (http)
    struct addrinfo hints, *res;
    int sockfd;
    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    // we could put "80" instead on "http" on the next line:
    getaddrinfo("www.example.com", "http", &hints, &res);
    // make a socket:
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    // connect it to the address and port we passed in to getaddrinfo():
    connect(sockfd, res->ai_addr, res->ai_addrlen);
}