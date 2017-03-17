#include <stdio.h>

int main() {
    int num = 100;
    int *pi = &num;

    printf("pi as minimal hex: %x\n", (unsigned int) pi);
    printf("pi as octal: %o\n", (unsigned int) pi);
    printf("pi as full hex: %p\n", pi);
    printf("pi's value: %d\n", *pi);

    const int limit = 500;
    const int *pci = &limit;
    const int const *cpci = &limit;

    int limit2 = 1000;
    int const *cpi = &limit2;

    printf("pci as full hex: %p\n", pci);
    printf("cpci as full hex: %p\n", cpci);
    printf("cpi as full hex: %p\n", cpi);

    return 0;
}