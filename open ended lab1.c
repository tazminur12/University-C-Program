#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void addNumbers();
void subtractNumbers();
void multiplyNumbers();
void divideNumbers();
void calculatePercentage();
int getValidNumber();

int main() {
    int choice;
    do {
        // Display menu
        printf("\n--- Menu-Driven Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Percentage\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle choice
        switch (choice) {
            case 1: addNumbers(); break;
            case 2: subtractNumbers(); break;
            case 3: multiplyNumbers(); break;
            case 4: divideNumbers(); break;
            case 5: calculatePercentage(); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addNumbers() {
    int n, num, sum = 0;
    printf("How many numbers do you want to add? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        num = getValidNumber();
        sum += num;
    }
    printf("Result: %d\n", sum);
}

void subtractNumbers() {
    int num1, num2;
    printf("Enter first number: ");
    num1 = getValidNumber();
    printf("Enter second number: ");
    num2 = getValidNumber();
    printf("Result: %d\n", num1 - num2);
}

void multiplyNumbers() {
    int n, num, product = 1;
    printf("How many numbers do you want to multiply? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        num = getValidNumber();
        product *= num;
    }
    printf("Result: %d\n", product);
}

void divideNumbers() {
    int num1, num2;
    printf("Enter numerator: ");
    num1 = getValidNumber();
    printf("Enter denominator: ");
    num2 = getValidNumber();
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2f\n", (float) num1 / num2);
    }
}

void calculatePercentage() {
    float num, total;
    printf("Enter the number: ");
    num = getValidNumber();
    printf("Enter the total: ");
    total = getValidNumber();
    if (total == 0) {
        printf("Error: Total cannot be zero.\n");
    } else {
        printf("Percentage: %.2f%%\n", (num / total) * 100);
    }
}

int getValidNumber() {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) break;
        else {
            printf("Invalid input. Enter a valid number: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
    return num;
} 
