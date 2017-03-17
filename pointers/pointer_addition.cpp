#include <iostream>

int main() {
    char a{'c'};
    char b{'d'};
    int e{1};
    int f{2};
    char *ap{&a};
    char *bp{ap + 1};
    int *ep{&e};
    int *fp{ep + 1};
    // no good
    // std::cout << *ap << "\n";
    // ap += 1;
    // std::cout << *ap << "\n";
    // std::cout << *ep << "\n";
    // ep += 1;
    // std::cout << *ep << "\n";
    // prints 1 and 4 -> pointer arithmetic really does manage the size
    std::cout << reinterpret_cast<uintptr_t>(bp) - reinterpret_cast<uintptr_t>(ap) << "\n";
    std::cout << reinterpret_cast<uintptr_t>(fp) - reinterpret_cast<uintptr_t>(ep) << "\n";

    return 0;
}
