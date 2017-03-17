/*#include<stdio.h>

int main(void) {
    printf("Minimum Signed Char %d\n", -(char) ((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n", (char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n", -(short) ((unsigned short) ~0 >> 1) - 1);
    printf("Maximum Signed Short %d\n", (short) ((unsigned short) ~0 >> 1));

    printf("Minimum Signed Int %d\n", -(int) ((unsigned int) ~0 >> 1) - 1);
    printf("Maximum Signed Int %d\n", (int) ((unsigned int) ~0 >> 1));

    printf("Minimum Signed Long %ld\n", -(long) ((unsigned long) ~0 >> 1) - 1);
    printf("Maximum signed Long %ld\n", (long) ((unsigned long) ~0 >> 1));

    *//* Unsigned Maximum Values *//*

    printf("Maximum Unsigned Char %d\n", (unsigned char) ~0);
    printf("Maximum Unsigned Short %d\n", (unsigned short) ~0);
    printf("Maximum Unsigned Int %u\n", (unsigned int) ~0);
    printf("Maximum Unsigned Long %lu\n", (unsigned long) ~0);

    return 0;
}*/

#include <float.h>
#include <limits.h>
#include <stdio.h>

main(void) {
    signed long int incr, uns_incr;

    signed char s_char_a, s_char_b;
    unsigned char u_char_a, u_char_b;

    signed short int s_short_int_a, s_short_int_b;
    unsigned short int u_short_int_a, u_short_int_b;

    signed int s_int_a, s_int_b;
    unsigned int u_int_a, u_int_b;

    signed long int s_long_int_a, s_long_int_b;
    unsigned long int u_long_int_a, u_long_int_b;

    float flt_a, flt_b, flt_c, flt_m;
    double dbl_a, dbl_b, dbl_c, dbl_m;

    /* SIGNED CHAR */
    printf("\nSIGNED CHAR MAX\n");
    printf("<limits.h> %d  ", SCHAR_MAX);

    s_char_a = s_char_b = 1;
    while (s_char_a > 0) {
        s_char_a = s_char_a * 2;
        if (s_char_a > 0)
            s_char_b = s_char_a;
    }
    s_char_b = s_char_b + (s_char_b - 1);
    printf("COMPUTED %d\n", s_char_b);

    printf("\nSIGNED CHAR MIN\n");
    printf("<limits.h> %d  ", SCHAR_MIN);

    s_char_a = s_char_b = -1;
    while (s_char_a < 0) {
        s_char_a = s_char_a * 2;
        if (s_char_a < 0)
            s_char_b = s_char_a;
    }
    printf("COMPUTED %d\n", s_char_b);

    /* UNSIGNED CHAR */
    printf("\nUNSIGNED CHAR MAX\n");
    printf("<limits.h> %d  ", UCHAR_MAX);

    u_char_a = u_char_b = 1;
    while (u_char_a > 0) {
        u_char_a = u_char_a * 2;
        if (u_char_a > 0)
            u_char_b = u_char_a;
    }
    u_char_b = u_char_b + (u_char_b - 1);
    printf("COMPUTED %d\n", u_char_b);

    /* SIGNED SHORT INT */
    printf("\nSIGNED SHORT INT MAX\n");
    printf("<limits.h> %hd  ", SHRT_MAX);

    s_short_int_a = s_short_int_b = 1;
    while (s_short_int_a > 0) {
        s_short_int_a = s_short_int_a * 2;
        if (s_short_int_a > 0)
            s_short_int_b = s_short_int_a;
    }
    s_short_int_b = s_short_int_b + (s_short_int_b - 1);
    printf("COMPUTED %hd\n", s_short_int_b);

    printf("\nSIGNED SHORT INT MIN\n");

    s_short_int_a = s_short_int_b = -1;
    while (s_short_int_a < 0) {
        s_short_int_a = s_short_int_a * 2;
        if (s_short_int_a < 0)
            s_short_int_b = s_short_int_a;
    }
    printf("<limits.h> %hd  ", SHRT_MIN);
    printf("COMPUTED %hd\n", s_short_int_b);

    /* UNSIGNED SHORT INT */
    printf("\nUNSIGNED SHORT INT MAX\n");
    printf("<limits.h> %hu  ", USHRT_MAX);

    u_short_int_a = u_short_int_b = 1;
    while (u_short_int_a > 0) {
        u_short_int_a = u_short_int_a * 2;
        if (u_short_int_a > 0)
            u_short_int_b = u_short_int_a;
    }
    u_short_int_b = u_short_int_b + (u_short_int_b - 1);
    printf("COMPUTED %hu\n", u_short_int_b);

    /* SIGNED INT */
    printf("\nSIGNED INT MAX\n");
    printf("<limits.h> %d  ", INT_MAX);

    s_int_a = s_int_b = 1;
    while (s_int_a > 0) {
        s_int_a = s_int_a * 2;
        if (s_int_a > 0)
            s_int_b = s_int_a;
    }
    s_int_b = s_int_b + (s_int_b - 1);
    printf("COMPUTED %d\n", s_int_b);

    printf("\nSIGNED INT MIN\n");

    s_int_a = s_int_b = -1;
    while (s_int_a < 0) {
        s_int_a = s_int_a * 2;
        if (s_int_a < 0)
            s_int_b = s_int_a;
    }
    printf("<limits.h> %d  ", INT_MIN);
    printf("COMPUTED %d\n", s_int_b);

    /* UNSIGNED INT */
    printf("\nUNSIGNED INT MAX\n");
    printf("<limits.h> %u  ", UINT_MAX);

    u_int_a = u_int_b = 1;
    while (u_int_a > 0) {
        u_int_a = u_int_a * 2;
        if (u_int_a > 0)
            u_int_b = u_int_a;
    }
    u_int_b = u_int_b + (u_int_b - 1);
    printf("COMPUTED %u\n", u_int_b);

    /* SIGNED LONG INT */
    printf("\nSIGNED LONG INT MAX\n");
    printf("<limits.h> %ld  ", LONG_MAX);

    s_long_int_a = s_long_int_b = 1;
    while (s_long_int_a > 0) {
        s_long_int_a = s_long_int_a * 2;
        if (s_long_int_a > 0)
            s_long_int_b = s_long_int_a;
    }
    s_long_int_b = s_long_int_b + (s_long_int_b - 1);
    printf("COMPUTED %ld\n", s_long_int_b);

    printf("\nSIGNED LONG INT MIN\n");

    s_long_int_a = s_long_int_b = -1;
    while (s_long_int_a < 0) {
        s_long_int_a = s_long_int_a * 2;
        if (s_long_int_a < 0)
            s_long_int_b = s_long_int_a;
    }
    printf("<limits.h> %ld  ", LONG_MIN);
    printf("COMPUTED %ld\n", s_long_int_b);

    /* UNSIGNED LONG INT */
    printf("\nUNSIGNED LONG INT MAX\n");
    printf("<limits.h> %lu  ", ULONG_MAX);

    u_long_int_a = u_long_int_b = 1;
    while (u_long_int_a > 0) {
        u_long_int_a = u_long_int_a * 2;
        if (u_long_int_a > 0)
            u_long_int_b = u_long_int_a;
    }
    u_long_int_b = u_long_int_b + (u_long_int_b - 1);
    printf("COMPUTED %lu\n", u_long_int_b);

    /* FLOAT */
    printf("\nFLOAT MAX\n");
    printf("<limits.h> %E  ", FLT_MAX);

    flt_a = 2.0;
    flt_b = 1.0;
    while (flt_a != flt_b) {
        flt_m = flt_b;           /* MAX POWER OF 2 IN MANTISSA */
        flt_a = flt_b = flt_b * 2.0;
        flt_a = flt_a + 1.0;
    }
    flt_m = flt_m + (flt_m - 1); /* MAX VALUE OF MANTISSA */

    flt_a = flt_b = flt_c = flt_m;
    while (flt_b == flt_c) {
        flt_c = flt_a;
        flt_a = flt_a * 2.0;
        flt_b = flt_a / 2.0;
    }
    printf("COMPUTED %E\n", flt_c);

    printf("\nFLOAT MIN\n");
    printf("<limits.h> %E  ", FLT_MIN);

    flt_a = flt_b = flt_c = 1.0;
    while (flt_b == flt_c) {
        flt_c = flt_a;
        flt_a = flt_a / 2.0;
        flt_b = flt_a * 2.0;
    }
    printf("COMPUTED %E\n", flt_c);

    /* DOUBLE */
    printf("\nDOUBLE MAX\n");
    printf("<limits.h> %E  ", DBL_MAX);

    dbl_a = 2.0;
    dbl_b = 1.0;
    while (dbl_a != dbl_b) {
        dbl_m = dbl_b;           /* MAX POWER OF 2 IN MANTISSA */
        dbl_a = dbl_b = dbl_b * 2.0;
        dbl_a = dbl_a + 1.0;
    }
    dbl_m = dbl_m + (dbl_m - 1); /* MAX VALUE OF MANTISSA */

    dbl_a = dbl_b = dbl_c = dbl_m;
    while (dbl_b == dbl_c) {
        dbl_c = dbl_a;
        dbl_a = dbl_a * 2.0;
        dbl_b = dbl_a / 2.0;
    }
    printf("COMPUTED %E\n", dbl_c);

    printf("\nDOUBLE MIN\n");
    printf("<limits.h> %E  ", DBL_MIN);

    dbl_a = dbl_b = dbl_c = 1.0;
    while (dbl_b == dbl_c) {
        dbl_c = dbl_a;
        dbl_a = dbl_a / 2.0;
        dbl_b = dbl_a * 2.0;
    }
    printf("COMPUTED %E\n", dbl_c);
}