#include <stdio.h>
#include <stdlib.h>

size_t int_bits = sizeof(int) * 8;

size_t float_bits = sizeof(float) * 8;

size_t long_bits = sizeof(long) * 8;

size_t double_bits = sizeof(double) * 8;

// unsigned int y = (x << n) | (x >> (-n & 31)); -> used in C to help avoid erroneous rotation

char *int_to_binary(int bit_fld) {
    static int endian_test = 1;
    static int endianness; // little endian if true
    if (*(char *)&endian_test == 1) {
        endianness = 1;
    } else {
        endianness = 0;
    }

    // generally little endian should read left to right
    char *bit_str = (char *) malloc(int_bits + 1);
    unsigned i;
    for (i = 0; i < int_bits; i++) {
        int index = endianness ? i : int_bits - (i + 1);
        *(bit_str + index) = (char) (bit_fld & ((1 << i) | (1 >> (-i & 31))) ? '1' : '0');
    }
    *(bit_str + int_bits) = '\0';
    return bit_str;
}

int main() {
    char *bin_str = int_to_binary(23);
    printf("%d as binary: %s", 23, bin_str);
    free(bin_str);
    return 0;
}