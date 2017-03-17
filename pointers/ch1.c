#include <stdlib.h>
#include <printf.h>

// Tip: read pointers backwards
int main() {
    int num;
    int *pi;
    const int *pci;
    num = 0;
    pi = &num;
    {
        int num;
        int *pi = &num;
        num = 0;
        // pi = num; -> error
        // cast int to pointer to int
    }
    {
        // initialize a pointer asap
        int num;
        int *pi;
        pi = &num;
    }
    {
        // printing pointers
        int num = 0;
        int *pi = &num;
        printf("Address of num: %d Value: %d\n", &num, num);
        printf("Address of pi: %d Value: %d\n", &pi, pi);
        printf("Address of pi: %d Value: %d\n", &pi, pi);
        printf("Address of pi: %x Value: %x\n", &pi, pi);
        printf("Address of pi: %o Value: %o\n", &pi, pi);
        printf("Address of pi: %p Value: %p\n", &pi, pi);
        printf("Value of pi: %p\n", (void *) pi);
    }
    {
        // dereferencing pointers
        int num = 5;
        int *pi = &num;
        printf("%p\n", *pi);
        // assign to pointed to var through pointer
        *pi = 200;
        printf("%d\n", num);
    }
    // function pointer
    void (*foo)();
    {
        int *pi = NULL;
        // same as on most systems
        int *pi2 = ((void *) 0);

        pi = 0;
        pi = NULL;
        // pi = 100; -> syntax error
        // pi = num; -> syntax error
        if (pi) {
            printf("pi is not null");
        } else {
            printf("pi is null");
        }
        // can also say
        if (pi == NULL) printf("null");
        if (pi != NULL) printf("not null");
    }
    // void pointer
    void *pv;
    // same repr and mem alignment as char
    // never equal to another pointer
    // two NULL assigned void pointers will be equal

    size_t size = sizeof(void *); // Legal
    // size_t size = sizeof(void); // Illegal

    // Memory
    // static and global variables are placed in the data segment
    // static non-global variables are only accessible within the scope in which they are defined

    size_t sizet = -5;
    printf("%d\n", sizet);
    printf("%zu\n", sizet);

    // intptr_t and uintptr_t
    {
        int num;
        intptr_t *pi2 = &num;
        // uintptr_t *pu = &num2; -> error
    }
    {
        intptr_t *pi = &num;
        uintptr_t *pu = (uintptr_t *) &num;
    }
    {
        // need to explicitly cast with unintptr_t and other types
        char c;
        uintptr_t *pc = (uintptr_t *) &c;
    }

    {
        int vector[] = {28, 41, 7};
        int *pi = vector;
        printf("%d\n", *pi);
        pi += 1;
        printf("%d\n", *pi);
        pi += 1;
        printf("%d\n", *pi);
        // no pointer addition with void *
    }

    {
        // pointer subtraction
        // use ptrdiff_t
        int vector[] = {28, 41, 7};
        int *p0 = vector;
        int *p1 = vector + 1;
        int *p2 = vector + 2;
        printf("p2-p0: %d\n", p2 - p0);
        printf("p2-p1: %d\n", p2 - p1);
        printf("p0-p1: %d\n", p0 - p1);
    }

    {
        // comparing pointers
        int vector[] = {28, 41, 7};
        int *p0 = vector;
        int *p1 = vector + 1;
        int *p2 = vector + 2;
        printf("p2>p0: %d\n", p2 > p0);
        printf("p2<p0: %d\n", p2 < p0);
        printf("p0>p1: %d\n", p0 > p1);
    }

    {
        // multiple indirection
        char *titles[] = {"A Tale of Two Cities", "Wuthering Heights", "Don Quixote", "Odyssey", "Moby-Dick", "Hamlet",
                          "Gulliver's Travels"};
        char **bestBooks[3];
        char **englishBooks[4];

        bestBooks[0] = &titles[0];
        bestBooks[1] = &titles[3];
        bestBooks[2] = &titles[5];
        englishBooks[0] = &titles[0];
        englishBooks[1] = &titles[1];
        englishBooks[2] = &titles[5];
        englishBooks[3] = &titles[6];
        printf("%s\n", *englishBooks[1]);
    }

    {
        // pointers to constants
        int num = 5;
        const int limit = 500;
        int *pi;
        const int *pci;
        pi = &num;
        pci = &limit;
    }
    {
        // constant pointer to non const value
        int num;
        int *const cpi = &num;
        // cpi must be initialized to a nonconstant variable
        // cpi cannot be modified
        // The data pointed to by cpi can be modified
    }
    {
        // const pointer to const value
        int num;
        const int * const cpci = &num;
        // neither can be modified
    }
    return 0;
}