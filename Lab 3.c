#include <stdio.h>

int main() {
    int n, i, j, spaces;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (spaces = 1; spaces <= n - i; spaces++) {
            printf("  "); // Two spaces for alignment
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
