//
// Created by Sandro on 09.12.2024.
//

#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accountNumber, string holderName, double balance, double overdraftLimit): Account(accountNumber, holderName, balance), overdraftLimit(overdraftLimit) {};

    void withdraw(double amount) {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded!" << endl;
        } else {
            balance -= amount;
            cout << amount << " withdraw from " << holderName << "." << endl;
            cout << "Account balance after withdraw: " << balance << endl;
        }
    }

    void displayDetails() {
        Account::displayDetails();
        cout << "Account type: Current" << endl;
        cout << "Overdraft limit: " << overdraftLimit << endl;
    }
};

#endif //CURRENTACCOUNT_H
