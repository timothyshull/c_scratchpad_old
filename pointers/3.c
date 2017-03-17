#include <stdlib.h>
#include <stdio.h>

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int *allocate_inside() {
    return (int *) malloc(sizeof(int));
}

int *allocate_before(int *pi) {
    *pi = 11;
    return pi;
}

int f1(int i) {
    return i + 1;
}

int f2(int i) {
    return i + 2;
}

int f3(int i) {
    return i + 3;
}

int f4(int i) {
    return i + 4;
}

int f5(int i) {
    return i + 5;
}

int f6(int i) {
    return i + 6;
}

typedef int (*fptr)(int);

int main() {
    int a = 25;
    int b = 50;
    swap(&a, &b);

    printf("%d\n", a);
    printf("%d\n", b);

    int *pi = allocate_inside();
    printf("pi as full hex: %p\n", pi);
    free(pi);

    int *new_pi = (int *) malloc(sizeof(int));
    int *new_pi2 = allocate_before(new_pi);

    printf("new_pi as full hex: %p\n", new_pi);
    printf("new_pi2 as full hex: %p\n", new_pi2);
    printf("new_pi contents: %d\n", *new_pi);
    printf("new_pi2 contents: %d\n", *new_pi2);

    free(new_pi);

    fptr fptr_arr[6] = {f1, f2, f3, f4, f5, f6};

    const int fptr_in = 10;

    for (int i = 0; i < sizeof(fptr_arr) / sizeof(fptr); i++) {
        printf("f%d: %d\n", i + 1, fptr_arr[i](fptr_in));
    }

    return 0;
}