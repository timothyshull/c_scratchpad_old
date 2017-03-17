#include <stdlib.h>
#include <printf.h>

int main() {
    int *test = (int *)malloc(sizeof(int));
    free(test);
    // free(test); -> causes runtime exception
    printf("after double free");
    // *test = 10; -> causes the runtime exception
    return 0;
}
