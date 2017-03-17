#include <stdlib.h>
#include <printf.h>

void print_2d_array(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizeof(arr[0]) / sizeof(int); j++) {
            printf("md_array[%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }
}

int main() {
    int v1[2];
    v1[0] = 101;
    *(v1 + 1) = 102;

    for (int i = 0; i < sizeof(v1) / sizeof(int); i++) {
        printf("v1[%d]: %d\n", i, v1[i]);
    }

    int *m_array = (int *) malloc(5 * sizeof(int));
    printf("%u\n", (unsigned) sizeof(*m_array));  // prints 4 -> sizeof int
    printf("%u\n", (unsigned) sizeof(int));

    // multidimensional
    int md_array[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("md_array[%d][%d]: %d\n", i, j, md_array[i][j]);
        }
    }

    printf("printing:\n\n");
    print_2d_array(md_array, 3);

    int three_d_array[2][3][4] = {
            {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
            {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("three_d_array[%d][%d][%d]: %d\n", i, j, k, three_d_array[i][j][k]);
            }
        }
    }
    return 0;
}
