#include <netdb.h>
#include <printf.h>

int main()
{
    struct sockaddr_in6 sa; // could be IPv4 if you want
    char host[1024];
    char service[20];
    // pretend sa is full of good information about the host and port...
    getnameinfo(&sa, sizeof sa, host, sizeof host, service, sizeof service, 0);
    printf("   host: %s\n", host);    // e.g. "www.example.com"
    printf("service: %s\n", service); // e.g. "http"
}