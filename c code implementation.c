#include <stdio.h>

void check_balance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

void deposit_money(float *balance) {
    float amount;
    printf("Enter the amount to deposit: $");
    scanf("%f", &amount);
    if (amount > 0) {
        *balance += amount;
        printf("You have successfully deposited $%.2f\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw_money(float *balance) {
    float amount;
    printf("Enter the amount to withdraw: $");
    scanf("%f", &amount);
    if (amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("You have successfully withdrawn $%.2f\n", amount);
    } else if (amount > *balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

int main() {
    float balance = 1000.0;  // Starting balance
    int choice;

    printf("Welcome to the ATM!\n");
    printf("Your account balance is: $%.2f\n\n", balance);

    do {
        printf("ATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_balance(balance);
                break;
            case 2:
                deposit_money(&balance);
                break;
            case 3:
                withdraw_money(&balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
