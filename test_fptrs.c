#include <printf.h>

int add(int a, int b) {
    return a + b;
}

int operation(int (*fptr)(int, int), int a, int b) {
    return fptr(a, b);
}

typedef int (* c_fptr)(int, int);

c_fptr get_function() {
    return add;
}

int main() {
    int test_val = operation(get_function(), 3, 4);
    printf("The returned value is: %d", test_val);
    return 0;
}