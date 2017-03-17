#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // IPv4:
    struct sockaddr_in ip4addr;
    int s;
    ip4addr.sin_family = AF_INET;
    ip4addr.sin_port = htons(3490);
    inet_pton(AF_INET, "10.0.0.1", &ip4addr.sin_addr);
    s = socket(PF_INET, SOCK_STREAM, 0);
    bind(s, (struct sockaddr*)&ip4addr, sizeof ip4addr);

    // IPv6:
    struct sockaddr_in6 ip6addr;
    int s;
    ip6addr.sin6_family = AF_INET6;
    ip6addr.sin6_port = htons(4950);
    inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &ip6addr.sin6_addr);
    s = socket(PF_INET6, SOCK_STREAM, 0);
    bind(s, (struct sockaddr*)&ip6addr, sizeof ip6addr);
}