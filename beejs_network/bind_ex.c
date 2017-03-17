#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    // modern way of doing things with getaddrinfo()
    struct addrinfo hints, * res;
    int sockfd;
    // first, load up address structs with getaddrinfo():
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me
    getaddrinfo(NULL, "3490", &hints, &res);
    // make a socket:
    // (you should actually walk the "res" linked list and error-check!)
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    // bind it to the port we passed in to getaddrinfo():
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    // example of packing a struct by hand, IPv4
    struct sockaddr_in myaddr;
    int s;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(3490);
    // you can specify an IP address:
    inet_pton(AF_INET, "63.161.169.137", &(myaddr.sin_addr));
    // or you can let it automatically select one:
    myaddr.sin_addr.s_addr = INADDR_ANY;
    s = socket(PF_INET, SOCK_STREAM, 0);
    bind(s, (struct sockaddr*) &myaddr, sizeof myaddr);
}