#include <i386/endian.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

int main() {
    int spatula_count = 3490;
    char *secret_message = "The Cheese is in The Toaster";
    int stream_socket, dgram_socket;
    struct sockaddr_in dest;
    int temp;
    // first with TCP stream sockets:
    // assume sockets are made and connected
    //stream_socket = socket(...
    //connect(stream_socket, ...
    // convert to network byte order
    temp = htonl(spatula_count);
    // send data normally:
    send(stream_socket, &temp, sizeof temp, 0);
    // send secret message out of band:
    send(stream_socket, secret_message, strlen(secret_message)+1, MSG_OOB);
    // now with UDP datagram sockets:
    //getaddrinfo(...
    //dest = ...  // assume "dest" holds the address of the destination
    //dgram_socket = socket(...
    // send secret message normally:
    sendto(dgram_socket, secret_message, strlen(secret_message)+1, 0, (struct sockaddr*)&dest, sizeof dest);
}