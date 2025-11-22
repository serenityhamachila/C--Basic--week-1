#include <stdio.h>

int main() {
    double num1, num2;
    char operation;

    // Ask the user to enter two numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Ask the user to choose an operation
    printf("Choose operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation and print the result
    switch (operation) {
        case '+':
            printf("Result = %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result = %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result = %.2lf\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result = %.2lf\n", num1 / num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;
        default:
            printf("Invalid operation. Please choose +, -, *, or /.\n");
    }

    return 0;
}
