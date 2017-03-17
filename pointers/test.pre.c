#include <stdio.h>
#include <stdlib.h>

void _dtor_name(char **v) {
    free(*v);
}

void raiiExample() {
    char *name __attribute__((cleanup(_dtor_name))) = ((char *) malloc(32));
    __builtin___strcpy_chk(name, "RAII Example", __builtin_object_size(name, 2 > 1 ? 1 : 0));
    printf("%s\n", name);
}

int main() {
    raiiExample();
    return 0;
}
