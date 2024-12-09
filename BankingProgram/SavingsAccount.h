//
// Created by Sandro on 09.12.2024.
//

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accountNumber, string holderName, double balance, double interestRate): Account(accountNumber, holderName, balance), interestRate(interestRate) {};

    void calculateInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;

        cout << "New balance: " << balance << endl;
    }

    void displayDetails() {
        Account::displayDetails();
        cout << "Account type: Savings" << endl;
        cout << "InterestRate: " << interestRate << endl;
    }
};

#endif //SAVINGSACCOUNT_H
