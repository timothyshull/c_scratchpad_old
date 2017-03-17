#include <stdint.h>
#include <i386/endian.h>
#include <sys/socket.h>

int main() {
    uint32_t some_long = 10;
    uint16_t some_short = 20;
    uint32_t network_byte_order;
    // convert and send
    network_byte_order = htonl(some_long);
    int s;
    send(s, &network_byte_order, sizeof(uint32_t), 0);
    some_short == ntohs(htons(some_short)); // this expression is true
}