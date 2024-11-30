include <stdio.h>

void metersToKilometers();
void gramsToKilograms();
void celsiusToFahrenheit();
void litersToMilliliters();

int main() {
    int choice;

    do {
        
        printf("\nUnit Converter\n");
        printf("-------------------\n");
        printf("1. Meters to Kilometers\n");
        printf("2. Grams to Kilograms\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Liters to Milliliters\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                metersToKilometers();
                break;
            case 2:
                gramsToKilograms();
                break;
            case 3:
                celsiusToFahrenheit();
                break;
            case 4:
                litersToMilliliters();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void metersToKilometers() {
    float meters, kilometers;
    printf("Enter the value in meters: ");
    scanf("%f", &meters);
    kilometers = meters / 1000;
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);
}

void gramsToKilograms() {
    float grams, kilograms;
    printf("Enter the value in grams: ");
    scanf("%f", &grams);
    kilograms = grams / 1000;
    printf("%.2f grams is equal to %.2f kilograms.\n", grams, kilograms);
}

void celsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("Enter the value in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

void litersToMilliliters() {
    float liters, milliliters;
    printf("Enter the value in liters: ");
    scanf("%f", &liters);
    milliliters = liters * 1000;
    printf("%.2f liters is equal to %.2f milliliters.\n", liters, milliliters);
}
