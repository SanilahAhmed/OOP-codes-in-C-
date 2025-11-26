#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class bMoney {
private:
    long double money;

public:
    // Default constructor
    bMoney() { money = 0; }

    // Function to input money from user
    void getmoney() {
        cout << "Enter money amount: ";
        string s;
        cin >> s;
        money = stold(s);  // convert string to long double
    }

    // Function to display money nicely
    void putmoney() {
        cout << fixed << setprecision(2) << money;
    }

    // Add two bMoney objects
    void madd(bMoney m1, bMoney m2) {
        money = m1.money + m2.money;
    }
};

int main() {
    bMoney m1, m2, m3;
    char ch;

    do {
        cout << "\n--- Money Addition ---\n";
        m1.getmoney();
        m2.getmoney();

        m3.madd(m1, m2);
        cout << "Sum = $";
        m3.putmoney();
        cout << endl;

        cout << "Do you want to add more amounts? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
