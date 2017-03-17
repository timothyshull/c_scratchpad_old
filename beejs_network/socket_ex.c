#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
    struct addrinfo hints, * res;
    int sockfd;
    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;     // AF_INET, AF_INET6, or AF_UNSPEC
    hints.ai_socktype = SOCK_STREAM; // SOCK_STREAM or SOCK_DGRAM
    getaddrinfo("www.example.com", "3490", &hints, &res);
    // make a socket using the information gleaned from getaddrinfo():
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
}