#include <iostream>
#include <cstdlib>  // for atold() or strtold()
#include <cstring>  // for string handling
using namespace std;

long double mstold(const char moneyStr[]) {
    char pureStr[50];
    int j = 0;

    // Copy only digits and decimal point
    for (int i = 0; moneyStr[i] != '\0'; i++) {
        if ((moneyStr[i] >= '0' && moneyStr[i] <= '9') || moneyStr[i] == '.') {
            pureStr[j++] = moneyStr[i];
        }
    }
    pureStr[j] = '\0'; // end string

    // Convert pure string to long double
    return strtold(pureStr, nullptr);
}

int main() {
    char money[50];
    long double amount;

    cout << "Enter a money amount (like $1,234,567.89): ";

    while (cin.getline(money, 50)) {
        if (strlen(money) == 0) break; // stop if empty
        amount = mstold(money);
        cout << "Equivalent long double: " << amount << endl;
        cout << "\nEnter another amount (or press Enter to exit): ";
    }

    return 0;
}
