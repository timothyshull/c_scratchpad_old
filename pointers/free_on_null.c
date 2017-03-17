#include <stdlib.h>
#include <printf.h>

int main() {
    int *test = NULL;
    free(NULL);
    printf("after free");
    // *test = 10; -> causes the runtime exception
    return 0;
}
