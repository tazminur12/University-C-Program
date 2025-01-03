#include <stdio.h>

void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int matrixA[rowsA][colsA], 
                      int rowsB, int colsB, int matrixB[rowsB][colsB],
                      int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter dimensions of the first matrix (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter dimensions of the second matrix (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int matrixA[rowsA][colsA], matrixB[rowsB][colsB], result[rowsA][colsB];

    readMatrix(rowsA, colsA, matrixA);
    readMatrix(rowsB, colsB, matrixB);

    multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, result);

    displayMatrix(rowsA, colsB, result);

    return 0;
}
