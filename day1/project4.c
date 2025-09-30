#include <stdio.h>

void celsiusToFahrenheit() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("In Fahrenheit: %.1f\n", fahrenheit);
}

void fahrenheitToCelsius() {
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("In Celsius: %.1f\n", celsius);
}

int main() {
    int choice;
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        celsiusToFahrenheit();
    } else if (choice == 2) {
        fahrenheitToCelsius();
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
