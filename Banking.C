#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_TRANSACTIONS 100
#define MAX_ACCOUNTS 10

typedef struct {
    int id;
    char name[50];
    char email[50];
    float balance[MAX_ACCOUNTS];
    char transactions[MAX_TRANSACTIONS][100];
    int transactionCount;
    int accountCount;
} User;

User users[MAX_USERS];
int userCount = 0;
int currentUserId = -1;

void registerUser();
void login();
void deposit();
void withdraw();
void checkBalance();
void transactionHistory();
void mainMenu();
void startMenu();
void addAccount();
void displayAccounts();

int main() {
    startMenu();
    return 0;
}

void startMenu() {
    int choice;
    while (1) {
        printf("S.H. BANKING SYSTEM \n");
        printf("1. Register\n");
        printf("2. Login\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum users reached!\n");
        return;
    }

    User newUser;
    newUser.id = userCount + 1;
    newUser.transactionCount = 0;
    newUser.accountCount = 0;

    printf("Enter your name: ");
    scanf("%49s", newUser.name);

    int choice;
    printf("Choose registration method:\n1. ID\n2. Email\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter your ID: ");
        scanf("%49s", newUser.email);
    } else if (choice == 2) {
        printf("Enter your email: ");
        scanf("%49s", newUser.email);
    }

    users[userCount++] = newUser;
    printf("Registration successful! Your user ID is %d\n", newUser.id);
    currentUserId = newUser.id;
    mainMenu();
}

void login() {
    int id;
    printf("Enter your user ID: ");
    scanf("%d", &id);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            currentUserId = id;
            printf("Login successful!\n");
            mainMenu();
            return;
        }
    }

    printf("User not found!\n");
    startMenu();
}

void mainMenu() {
    int choice;
    while (1) {
        printf("\nFUTURE IN STYLE\n");
        printf("1. Add account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw\n");
        printf("4. Check balance\n");
        printf("5. Details of transaction and date\n");
        printf("6. Logout\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                transactionHistory();
                break;
            case 6:
                currentUserId = -1;
                startMenu();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

void addAccount() {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            if (users[i].accountCount >= MAX_ACCOUNTS) {
                printf("Maximum accounts reached!\n");
                return;
            }

            users[i].balance[users[i].accountCount] = 0;
            printf("Account %d created successfully!\n", users[i].accountCount + 1);
            users[i].accountCount++;
            return;
        }
    }
}

void displayAccounts() {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            printf("Your accounts:\n");
            for (int j = 0; j < users[i].accountCount; j++) {
                printf("%d. Account %d - Balance: %.2f\n", j + 1, j + 1, users[i].balance[j]);
            }
            return;
        }
    }
}

void deposit() {
    displayAccounts();
    int accountNumber;
    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            if (accountNumber > 0 && accountNumber <= users[i].accountCount) {
                float amount;
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                users[i].balance[accountNumber - 1] += amount;
                time_t now = time(NULL);
                char* date = ctime(&now);
                date[strlen(date) - 1] = '\0';
                char transaction[100];
                sprintf(transaction, "Deposited %.2f on %s", amount, date);
                strcpy(users[i].transactions[users[i].transactionCount++], transaction);
                printf("Deposit successful!\n");
                return;
            } else {
                printf("Invalid account number!\n");
                return;
            }
        }
    }
}

void withdraw() {
    displayAccounts();
    int accountNumber;
    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            if (accountNumber > 0 && accountNumber <= users[i].accountCount) {
                float amount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (users[i].balance[accountNumber - 1] >= amount) {
                    users[i].balance[accountNumber - 1] -= amount;
                    time_t now = time(NULL);
                    char* date = ctime(&now);
                    date[strlen(date) - 1] = '\0';
                    char transaction[100];
                    sprintf(transaction, "Withdrew %.2f on %s", amount, date);
                    strcpy(users[i].transactions[users[i].transactionCount++], transaction);
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient balance!\n");
                }
                return;
            } else {
                printf("Invalid account number!\n");
                return;
            }
        }
    }
}

void checkBalance() {
    displayAccounts();
    int accountNumber;
    printf("Enter account number to check balance: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            if (accountNumber > 0 && accountNumber <= users[i].accountCount) {
                printf("Your balance is %.2f\n", users[i].balance[accountNumber - 1]);
                return;
            } else {
                printf("Invalid account number!\n");
                return;
            }
        }
    }
}

void transactionHistory() {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == currentUserId) {
            printf("Transaction history:\n");
            for (int j = 0; j < users[i].transactionCount; j++) {
                printf("%s\n", users[i].transactions[j]);
            }
            return;
        }
    }
}
