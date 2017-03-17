#include "dec_to_bin.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    char* pointer;

    printf("Enter an integer in decimal number system\n");
    scanf("%d", &n);

    pointer = decimal_to_binary(n);
    printf("Binary string of %d is: %s\n", n, pointer);

    free(pointer);

    exit(0);
}