#include <stdio.h>

// Function prototypes
void addNumbers();
void subtractNumbers();
void multiplyNumbers();
void divideNumbers();
void calculatePercentage();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addNumbers(); break;
            case 2: subtractNumbers(); break;
            case 3: multiplyNumbers(); break;
            case 4: divideNumbers(); break;
            case 5: calculatePercentage(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Percentage\n");
    printf("6. Exit\n");
}

// Function to add numbers
void addNumbers() {
    int n, i;
    double sum = 0, num;
    printf("How many numbers do you want to add? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &num);
        sum += num;
    }
    printf("Result: %.2lf\n", sum);
}

// Function to subtract numbers
void subtractNumbers() {
    double num1, num2;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Result: %.2lf\n", num1 - num2);
}

// Function to multiply numbers
void multiplyNumbers() {
    int n, i;
    double product = 1, num;
    printf("How many numbers do you want to multiply? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &num);
        product *= num;
    }
    printf("Result: %.2lf\n", product);
}

// Function to divide numbers
void divideNumbers() {
    double num1, num2;
    printf("Enter the numerator: ");
    scanf("%lf", &num1);
    printf("Enter the denominator: ");
    scanf("%lf", &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2lf\n", num1 / num2);
    }
}

// Function to calculate percentage
void calculatePercentage() {
    double number, total;
    printf("Enter the number: ");
    scanf("%lf", &number);
    printf("Enter the total: ");
    scanf("%lf", &total);
    if (total == 0) {
        printf("Error: Total cannot be zero.\n");
    } else {
        printf("Result: %.2lf%%\n", (number / total) * 100);
    }
}
