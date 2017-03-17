

#include <string.h>
#include <stdlib.h>

char *globalHeader = "Chapter";
char globalArrayHeader[] = "Chapter";

void displayHeader() {
    static char *staticHeader = "Chapter";
    char *localHeader = "Chapter";
    static char staticArrayHeader[] = "Chapter";
    char localArrayHeader[] = "Chapter";
    char *heapHeader = (char *) malloc(strlen("Chapter") + 1);
    strcpy(heapHeader, "Chapter");
}

// gcc -S -masm=intel test_asm.c
int main() {
    displayHeader();
    return 0;
}


// lipo libgcc.a -thin x86_64 -output libgcc.a
// lipo -info libgcc.a
// otool -tV libgcc.a
// ar x libgcc.a
// ls
// otool -tV libgcc.o