#include <sys/socket.h>

int main() {
    int s = socket(PF_INET, SOCK_STREAM, 0);
    // ...do some send()s and stuff in here...
    // and now that we're done, don't allow any more sends()s:
    shutdown(s, SHUT_WR);
}