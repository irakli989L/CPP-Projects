//
// Created by Sandro on 09.12.2024.
//
#include <bits/stdc++.h>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
protected:
    string accountNumber;
    string holderName;
    double balance;

public:
    Account(string accountNumber, string holderName, double balance) {
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
    }

    virtual void deposit(int amount) {
        if (amount <= 0) {
            cout << "Please enter valid amount." << endl;
        }else {
            balance += amount;
            cout << amount << " deposited from " << holderName << "." << endl;
            cout << "Account balance after deposit: " << balance << endl;
        }
    }

    virtual void withdraw(int amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        }else {
            balance -= amount;
            cout << amount << " withdraw from " << holderName << "." << endl;
            cout << "Account balance after withdraw: " << balance << endl;
        }
    }

    virtual string getAccountNumber() {
        return accountNumber;
    }

    virtual void displayDetails() {
        cout << "AccountNumber: " << accountNumber << endl;
        cout << "HolderName: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

#endif //ACCOUNT_H
