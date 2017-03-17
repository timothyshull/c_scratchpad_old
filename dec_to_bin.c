//
// Created by Timothy Shull on 1/16/16.
//

#include <stddef.h>
#include <stdlib.h>
#include "dec_to_bin.h"

char* decimal_to_binary(int n) {
    int c, d, count;
    char* pointer;

    count = 0;
    pointer = (char*) malloc(32 + 1);

    if (pointer == NULL)
        exit(EXIT_FAILURE);

    for (c = 31; c >= 0; c--) {
        d = n >> c;

        if (d & 1)
            *(pointer + count) = 1 + '0';
        else
            *(pointer + count) = 0 + '0';

        count++;
    }

    *(pointer + count) = '\0';

    return pointer;
}
