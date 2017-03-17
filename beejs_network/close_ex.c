#include <unistd.h>
#include <sys/socket.h>

int main() {
    int s = socket(PF_INET, SOCK_DGRAM, 0);
    // a whole lotta stuff...*BRRRONNNN!*
    close(s);  // not much to it, really.
}