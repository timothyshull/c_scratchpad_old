#include <stdio.h>
#include <stdlib.h>

#define safeFree(p) saferFree((void**)&(p))

void swapWithPointers(int *pnum1, int *pnum2) {
    int tmp;
    tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;
}

void swap(int num1, int num2) {
    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void passingAddressOfConstants(const int *num1, int *num2) {
    *num2 = *num1;
}

int *allocateArray(int size, int value) {
    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

void saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

int square(int num) {
    return num * num;
}

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int noop(int num1, int num2) {
    return 0;
}

// It is convenient to use typedefs for function pointers
typedef int (*fptrOperation)(int, int);

int compute(fptrOperation operation, int num1, int num2) {
    return operation(num1, num2);
}

int computeWithoutTypedef(int (*operation)(int, int), int num1, int num2) {
    return operation(num1, num2);
}

fptrOperation select(char opcode) {
    switch (opcode) {
        case '+':
            return add;
        case '-':
            return subtract;
        default:
            return noop;
    }
}

int evaluate(char opcode, int num1, int num2) {
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}


int main() {
    {
        // Passing data using pointers
        int n1 = 5;
        int n2 = 10;
        swapWithPointers(&n1, &n2);
        printf("%d\n", n1);
        printf("%d\n", n2);
    }
    {
        // Pass by value -> does not work
        int n1 = 5;
        int n2 = 10;
        swap(n1, n2);
        printf("%d\n", n1);
        printf("%d\n", n2);
    }
    {
        // Passing pointer to constant
        const int limit = 100;
        int result = 5;
        passingAddressOfConstants(&limit, &result);
        printf("%d\n", limit);
        printf("%d\n", result);
    }
    {
        // Returning a pointer -> allocate using malloc and return address if created in function
        // Pass an object (by pointer) to the function to modify it -> passes allocation and deallocation to caller
        int *vector = allocateArray(5, 45);
        for (int i = 0; i < 5; i++) {
            printf("%d\n", vector[i]);
        }
    }
    {
        int *pi;
        pi = (int *) malloc(sizeof(int));
        *pi = 5;
        printf("Before: %p\n", pi);
        safeFree(pi);
        printf("After: %p\n", pi);
        safeFree(pi);
    }
    {
        // Function pointers
        int (*fptr1)(int);
        int n = 5;
        fptr1 = square;
        printf("%d squared is %d\n", n, fptr1(n));
    }
    {
        // Passing function pointers
        printf("%d\n", compute(add, 5, 6));
        printf("%d\n", compute(subtract, 5, 6));
    }
    {
        // Returning function pointers
        printf("%d\n", evaluate('+', 5, 6));
        printf("%d\n", evaluate('-', 5, 6));
    }

    return 0;
}