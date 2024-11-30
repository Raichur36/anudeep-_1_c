#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validatePassword(char password[]);

int main() {
    char password[100];
    int isValid;

    printf("Enter a password to validate: ");
    scanf("%s", password);

    isValid = validatePassword(password);

    if (isValid) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid. Please ensure it meets the criteria:\n");
        printf("1. At least 8 characters long\n");
        printf("2. Contains at least one uppercase letter\n");
        printf("3. Contains at least one lowercase letter\n");
        printf("4. Contains at least one digit\n");
        printf("5. Contains at least one special character (!, @, #, etc.)\n");
    }

    return 0;
}

int validatePassword(char password[]) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (strchr("!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~", password[i]))
            hasSpecial = 1;
    }

    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        return 1; 
    }

    return 0; 
}
