#include <stdio.h>
#include <stdlib.h>

static const size_t NUMBER_OF_DOUBLES = 10;

int main() {
    int *pi = (int *) malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    printf("pi as full hex: %p\n", pi);
    free(pi);


    double *pd = (double *) malloc(NUMBER_OF_DOUBLES * sizeof(double));

    for (int i = 0; i < NUMBER_OF_DOUBLES; i++) {
        *(pd + i) = (double) rand();
    }

    for (int i = 0; i < NUMBER_OF_DOUBLES; i++) {
        printf("%f\n", *(pd + i));
    }

    pd = (double *) calloc(NUMBER_OF_DOUBLES, sizeof(double));

    for (int i = 0; i < NUMBER_OF_DOUBLES; i++) {
        printf("%f\n", *(pd + i));
    }

    realloc(pd, NUMBER_OF_DOUBLES - 5 * sizeof(double));

    for (int i = 0; i < NUMBER_OF_DOUBLES - 5; i++) {
        *(pd + i) = (double) rand();
    }

    for (int i = 0; i < NUMBER_OF_DOUBLES - 5; i++) {
        printf("%f\n", *(pd + i));
    }

    printf("%lu\n", sizeof(pd));

    return 0;
}
