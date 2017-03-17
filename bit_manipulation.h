#ifndef BIT_MANIPULATION_BIT_MANIPULATION_H
#define BIT_MANIPULATION_BIT_MANIPULATION_H

unsigned get_bits(unsigned x, int p, int n) {
    unsigned bits = x >> (p + 1 - n); // shift bits we are interested in to rightmost position
    unsigned mask = ~(~0 << n); // generate a mask that is 0000...11..1, i.e. n 1's on the right

    return bits & mask;
}

unsigned set_bits(unsigned x, int p, int n, unsigned y) {
    unsigned rightmost_y = ~(~0 << n) & y;
    unsigned shifted_y = rightmost_y << (p + 1 - n);
    unsigned mask = ~(~0 << n);
    unsigned positioned_mask = ~(mask << (p + 1 - n));
    return (x & positioned_mask) | shifted_y;
}

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << p + 1 - n);
}

unsigned right_rotate(unsigned x, int n) {
    return x >> n | ((x & (~(~0 << n))) << (8 - n));
}

#endif //BIT_MANIPULATION_BIT_MANIPULATION_H
