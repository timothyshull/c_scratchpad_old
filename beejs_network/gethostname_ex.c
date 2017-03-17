#include <unistd.h>
#include <printf.h>

int main() {
    char hostname[128];
    gethostname(hostname, sizeof hostname);
    printf("My hostname: %s\n", hostname);
}