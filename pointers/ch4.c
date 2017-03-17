#include <stdlib.h>
#include <stdio.h>

char *getLine();

// C++ guidelines advises against this but it is necessary in C
void displayArray(int arr[], size_t size);

void displayArrayInPtrArrNot(int *arr, size_t size);

void displayArrayInPtrPtrNot(int *arr, size_t size);

void displayArrayInArrPtrNot(int arr[], size_t size);

void display2DArray(int arr[][5], int rows);

void display3DArray(int (*arr)[2][4], int rows);

int main() {
    {
        int vector[5] = {1, 2, 3, 4, 5};
        printf("%d\n", sizeof(vector) / sizeof(int));

        int matrix[2][3] = {{1, 2, 3},
                            {4, 5, 6}};
        for (int i = 0; i < 2; i++) {
            printf("&matrix[%d]: %p sizeof(matrix[%d]): %d\n",
                   i, &matrix[i], i, sizeof(matrix[i]));
        }

        int arr3d[3][2][4] = {
                {{1,  2,  3,  4},  {5,  6,  7,  8}},
                {{9,  10, 11, 12}, {13, 14, 15, 16}},
                {{17, 18, 19, 20}, {21, 22, 23, 24}}
        };
    }

    {
        // pointer notation and arrays
        int vector[5] = {1, 2, 3, 4, 5};
        int *pv = vector;
        printf("%p\n", vector);
        printf("%p\n", &vector[0]);

        // vector[i] is effectively equivalent to *(pv + 1)
        for (int i = 0; i < sizeof(vector) / sizeof(int); i++) {
            printf("%d\n", vector[i]);
            printf("%d\n", *(pv + i));
        }
    }
    {
        // differences between arrays and pointers
        int vector[5] = {1, 2, 3, 4, 5};
        int *pv = vector;
        pv = pv + 1;
        // vector = vector + 1; // Syntax error
        pv = vector + 1; // ok
    }
    {
        int *pv = (int *) malloc(5 * sizeof(int));
        for (int i = 0; i < 5; i++) {
            pv[i] = i + 1;
        }
        // pointer notation is often harder to follow
        for (int i = 0; i < 5; i++) {
            *(pv + i) = i + 1;
        }
    }
    {
        int vector[5] = {1, 2, 3, 4, 5};
        displayArray(vector, sizeof(vector) / sizeof(int));
    }

    {
        int matrix[2][5] = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10}
        };

        display2DArray(matrix, 2);
    }
    {
        // When passing an array of more than two dimensions, specify the size for each
        // array but the first
        int arr3d[3][2][4] = {
                {{1,  2,  3,  4},  {5,  6,  7,  8}},
                {{9,  10, 11, 12}, {13, 14, 15, 16}},
                {{17, 18, 19, 20}, {21, 22, 23, 24}}
        };
        display3DArray(arr3d, 3);
    }
    {
        // allocate 2d array with potentially non-contiguous memory
        int rows = 2;
        int columns = 5;
        int **matrix = (int **) malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            matrix[i] = (int *) malloc(columns * sizeof(int));
        }
    }
    {
        // allocate 2d array with contiguous memory
        int rows = 2;
        int columns = 5;
        int **matrix = (int **) malloc(rows * sizeof(int *));
        matrix[0] = (int *) malloc(rows * columns * sizeof(int));
        for (int i = 1; i < rows; i++)
            matrix[i] = matrix[0] + i * columns;
    }

    {
        // compound literals
        // (const int) {100}
        // (int[3]) {10, 20, 30}
        int (*(arr1[])) = {
                (int[]) {0, 1, 2},
                (int[]) {3, 4, 5},
                (int[]) {6, 7, 8}
        };

        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                printf("arr1[%d][%d] Address: %p Value: %d\n", j, i, &arr1[j][i], arr1[j][i]);
            }
            printf("\n");
        }
    }

    {
        // Jagged array
        int (*(arr2[])) = {
                (int[]) {0, 1, 2, 3},
                (int[]) {4, 5},
                (int[]) {6, 7, 8}};
        int row = 0;
        for (int i = 0; i < 4; i++) {
            printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
        }
        printf("\n");
        row = 1;
        for (int i = 0; i < 2; i++) {
            printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
        }
        printf("\n");
        row = 2;
        for (int i = 0; i < 3; i++) {
            printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
        }
        printf("\n");
    }

    return 0;
}

char *getLine() {
    const size_t sizeIncrement = 10;
    char *buffer = malloc(sizeIncrement);
    char *currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;
    if (currentPosition == NULL) {
        return NULL;
    }
    while (1) {
        character = fgetc(stdin);
        if (character == '\n') { break; }
        if (++length >= maximumLength) {
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition++ = (char) character;
    }
    *currentPosition = '\0';
    return buffer;
}

void displayArray(int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

void displayArrayInPtrArrNot(int *arr, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

void displayArrayInPtrPtrNot(int *arr, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }
}

void displayArrayInArrPtrNot(int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }
}

void display2DArray(int arr[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void display3DArray(int (*arr)[2][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            printf("{");
            for (int k = 0; k < 4; k++) {
                printf("%d", arr[i][j][k]);
            }
            printf("}");
        }
        printf("\n");
    }
}
