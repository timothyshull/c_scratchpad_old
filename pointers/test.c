#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// Use gcc -E to reun preprocessor

#define RAII_VARIABLE(vartype, varname, initval, dtor) \
        void _dtor_ ## varname (vartype * v) { dtor(*v); } \
        vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

void raiiExample() {
    RAII_VARIABLE(char*, name, (char *) malloc(32), free);
    strcpy(name, "RAII Example");
    printf("%s\n", name);
}

int main() {
    raiiExample();
    return 0;
}