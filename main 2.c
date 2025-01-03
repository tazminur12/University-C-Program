#include <stdio.h>

int main() {
    int a = 0, b = 1, c = 0;
    printf("Fibonacci series up to 300:\n");
    printf("%d %d ", a, b);

    while ((c = a + b) <= 300) {
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}
