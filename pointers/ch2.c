#include <stdlib.h>
#include <printf.h>
#include <memory.h>

// Dynamic memory
int main() {
    {
        size_t sz = 4;
        int *pi = (int *) malloc(sz);

        // Causes an error
        // int *pi;
        // *pi = (int*) malloc(sizeof(int));
    }
    {
        size_t sz = 6;
        char *pc = (char *) malloc(sz);
        for (int i = 0; i < 8; i++) {
            pc[i] = 0;
        }
    }
    {
        // realloc with underssized error
        char *string1;
        char *string2;
        size_t sz = 2 * sizeof(long);
        string1 = (char *) malloc(sz);
        strcpy(string1, "0123456789AB");
        sz = sizeof(long);
        string2 = realloc(string1, sz);
        printf("string1 Value: %p [%s]\n", string1, string1);
        printf("string2 Value: %p [%s]\n", string2, string2);
        printf("%d\n", sizeof(string1));
        printf("%d\n", sizeof(string2));
    }
    {
        // realloc with oversized error
        char *string1;
        char *string2;
        size_t sz = 2 * sizeof(long);
        string1 = (char*) malloc(sz);
        strcpy(string1, "0123456789AB");
        sz = 8 * sizeof(long);
        string2 = realloc(string1, sz);
        printf("string1 Value: %p [%s]\n", string1, string1);
        printf("string2 Value: %p [%s]\n", string2, string2);
    }
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long));
    return 0;
}