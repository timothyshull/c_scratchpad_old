#include <printf.h>
#include <sys/socket.h>

int main()
{
    int optval;
    int optlen;
    char* optval2;
    // set SO_REUSEADDR on a socket to true (1):
    optval = 1;
    int s1;
    setsockopt(s1, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
    // bind a socket to a device name (might not work on all systems):
    optval2 = "eth1"; // 4 bytes long, so 4, below:
    int s2;
    setsockopt(s2, SOL_SOCKET, SO_BINDTODEVICE, optval2, 4);
    // see if the SO_BROADCAST flag is set:
    int s3;
    getsockopt(s3, SOL_SOCKET, SO_BROADCAST, &optval, &optlen);
    if (optval != 0) {
        printf("SO_BROADCAST enabled on s3!\n");
    }
}