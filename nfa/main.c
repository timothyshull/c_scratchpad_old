#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nfa.h"

int main(int argc, char *argv[]) {
    size_t regexp_len = strlen(argv[1]) + 3;
    char regexp[regexp_len];
    snprintf(regexp, regexp_len, "(%s)", argv[1]);
    char txt[strlen(argv[2]) + 1];
    strcpy(txt, argv[2]);
    NFA *nfa = (NFA *)malloc(sizeof(NFA));
    NFA_init(nfa);
    NFA_construct(nfa, regexp);
    printf("The NFA defined by the regexp %s %s %s", regexp, NFA_recognizes(nfa, txt) ? "recognizes" : "does not recognize", txt);

    return 0;
}