#include <arpa/inet.h>
#include <printf.h>

int main() {
    struct sockaddr_in antelope;
    char *some_addr;
    inet_aton("10.0.0.1", &antelope.sin_addr); // store IP in antelope
    some_addr = inet_ntoa(antelope.sin_addr); // return the IP
    printf("%s\n", some_addr); // prints "10.0.0.1"
    // and this call is the same as the inet_aton() call, above:
    antelope.sin_addr.s_addr = inet_addr("10.0.0.1");
}