#include <iostream>

// OK according to MSDN -> https://msdn.microsoft.com/en-us/library/1sf8shae.aspx
// should prefer over ** in C++

void mod_a(int *&ptr) {
    *ptr = 10;
}

int main() {
    int a{1};
    int *addr_a{&a};
    mod_a(addr_a);
    std::cout << *addr_a << "\n";
    return 0;
}