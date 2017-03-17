#include <stdio.h>

int main() {
    int vector[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(vector) / sizeof(int); i++) {
        printf("%d\n", vector[i]);
    }

    int matrix[2][3] = {{1, 2, 3},
                        {4, 5, 6}};

//    int (*mp)[3] = matrix;
//
//    for (int i = 0; i < sizeof(matrix) / sizeof(int); i++) {
//        printf("%d\n", **(matrix + i));
//    }

    for (int i = 0; i < 2; i++) {
        printf("&matrix[%d]: %p sizeof(matrix[%d]): %lu\n", i, &matrix[i], i, sizeof(matrix[i]));
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n", matrix[i][j]);
        }
    }

    int arr3d[3][2][4] = {
            {{1,  2,  3,  4},  {5,  6,  7,  8}},
            {{9,  10, 11, 12}, {13, 14, 15, 16}},
            {{17, 18, 19, 20}, {21, 22, 23, 24}}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%d\n", arr3d[i][j][k]);
            }
        }
    }

    return 0;
}