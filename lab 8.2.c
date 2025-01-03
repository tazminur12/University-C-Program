#include <stdio.h>

void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the %dx%d array:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void findAndSumDivisible(int rows, int cols, int matrix[rows][cols]) {
    int sum = 0;
    printf("Numbers divisible by 4 or 7:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 4 == 0 || matrix[i][j] % 7 == 0) {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nSum of these numbers: %d\n", sum);
}

int main() {
    int rows, cols;

    printf("Enter dimensions of the array (rows and columns): ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    readMatrix(rows, cols, matrix);

    findAndSumDivisible(rows, cols, matrix);

    return 0;
}
