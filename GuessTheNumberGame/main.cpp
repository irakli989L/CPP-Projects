#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(0));

    int number = rand() % 101;
    int numberOfAttempts = 0;

    while (true) {
        int guess;

        cout << "Enter a number (0-100): ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, try again!" << endl;
            continue;
        }

        if (guess < 0 || guess > 100) {
            cout << "Invalid input, try again." << endl;
            continue;
        }

        numberOfAttempts++;

        if (guess == number) {
            cout << "You got it!\n";
            break;
        }else if (guess > number) {
            cout << "Number is too big!\n";
        }else {
            cout << "Number is too small!\n";
        }
    }

    cout << "You took " << numberOfAttempts << " attempts!\n";

    return 0;
}