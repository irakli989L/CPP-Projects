#include <bits/stdc++.h>
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
    vector<Account*> accounts;

    int choice;
    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountType;
                string accountNumber;
                string holderName;
                double init_balance;

                cout << "Enter account number: ";
                cin >> accountNumber;
                cin.ignore();
                cout << "Enter account holder name: ";
                getline(cin, holderName);
                cout << "Enter initial balance: ";
                cin >> init_balance;

                cout << "Choose Account Type:\n";
                cout << "1. Savings Account\n";
                cout << "2. Current Account\n";
                cout << "Enter your choice: ";

                cin >> accountType;

                if (accountType == "1") {
                    double interestRate;
                    cout << "Enter interest rate: ";
                    cin >> interestRate;

                    Account* savingsAcc = new SavingsAccount(accountNumber, holderName, init_balance, interestRate);
                    accounts.push_back(savingsAcc);
                    cout << "Savings Account Created\n";
                }else if (accountType == "2") {
                    double overdraftLimit;
                    cout << "Enter overdraft limit: ";
                    cin >> overdraftLimit;

                    Account* currentAcc = new CurrentAccount(accountNumber, holderName, init_balance, overdraftLimit);
                    accounts.push_back(currentAcc);
                    cout << "Current Account Created\n";
                }else {
                    cout << "Invalid Input\n";
                }

                break;
            }
            case 2: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;

                bool found = false;

                for (Account* account : accounts) {
                    if (account->getAccountNumber() == accountNumber) {
                        double amount;

                        cout << "Enter amount: ";
                        cin >> amount;

                        account->deposit(amount);

                        found = true;
                    }
                }

                if (!found) {
                    cout << "Please enter a valid account number\n";
                }

                break;
            }
            case 3: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;

                bool found = false;

                for (Account* account : accounts) {
                    if (account->getAccountNumber() == accountNumber) {
                        double amount;

                        cout << "Enter amount: ";
                        cin >> amount;

                        account->withdraw(amount);

                        found = true;
                    }
                }

                if (!found) {
                    cout << "Please enter a valid account number\n";
                }

                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;

                bool found = false;

                for (Account* account : accounts) {
                    if (account->getAccountNumber() == accountNumber) {
                        account->displayDetails();

                        found = true;
                    }
                }

                if (!found) {
                    cout << "Please enter a valid account number\n";
                }
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    // Clean up
    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.