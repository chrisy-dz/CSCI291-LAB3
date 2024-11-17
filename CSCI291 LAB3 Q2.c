// Including library headers needed for the working of the code 
#include <stdio.h>

// Defined Constants for balance and transactions 
#define InitialBalance 1000
#define MaxTransactions 100

// Function to process transactions
void processTransactions(const int transactions[], int length) {
    int balance = InitialBalance;
    int tobeprocessed[MaxTransactions];
    int unprocessedTransactions = 0;

    // Printing initial balance of the bank account
    printf("Initial balance: %d AED\n", balance);
    
    // Using for loop to store transactions array
    for (int i = 0; i < length; i++) {
        int transaction = transactions[i];

        // Using if statement to check is balance is 0. If balance is 0, then no further transactions can be made
        if (balance == 0) {
            printf("Balance is 0. No further transactions can be processed.\n"); // Printing message to the user
            tobeprocessed[unprocessedTransactions++] = transaction;
            continue; // Continuing if balance is not 0
        }

        // Using nested if else statement to carry out the process of transactions 
        if (transaction < 0) {
            if (balance + transaction < 0) {
                printf("Transaction %d (withdrawal of AED %d) cannot be made due to insufficient balance.\n", i + 1, -transaction);
                tobeprocessed[unprocessedTransactions++] = transaction;
            } 
            else 
            {
                // For withdrawal, decrementing the withdrawn amount from balance
                balance += transaction;
                printf("Transaction %d processed: \n\tWithdrawal of AED %d. \n\tNew balance: AED %d\n", i + 1, -transaction, balance);
            }
        } 
        else 
        {  
            // For deposit, incrementing the deposited amount to balance
            balance += transaction;
            printf("Transaction %d processed: \n\tDeposit of AED %d. \n\tNew balance: AED %d\n", i + 1, transaction, balance);
        }
    }

    // Updating final balance after all the transactions are processed
    printf("\nFinal balance: %d AED\n", balance);

    // Storing all the unprocessed transactions in a separate array
    if (unprocessedTransactions > 0) {
        printf("Unprocessed transactions:\n");
        for (int i = 0; i < unprocessedTransactions; i++) {
            printf("%d ", tobeprocessed[i]);
        }
    } 
    else 
    {
        printf("All transactions were processed.\n"); // Printing a message after all transactions are processed
    }
    printf("\n");
}

int main() {
    // Test values for bank account transactions 
    int transactions[] = {200, -150, -500, -400, -50, -200, 300};
    int length = sizeof(transactions) / sizeof(transactions[0]);

    processTransactions(transactions, length);

    // Returning zero 
    return 0;
}