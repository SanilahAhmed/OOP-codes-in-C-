
#include <iostream>
#include <string>
#include <cstdlib>   // for stold (string to long double)
#include <iomanip>   // for formatting
using namespace std;

class bMoney {
private:
    long double money;  // store the value as number

public:
    // Default constructor
    bMoney() : money(0.0) {}

    // Explicit constructor from long double
    explicit bMoney(long double m) : money(m) {}

    // Input money from string like "1234.56"
    void getMoney() {
        string s;
        cout << "Enter amount (e.g. 1234.56): ";
        cin >> s;
        money = stold(s);   // convert string to long double jese "1234.56" -> 1234.56  
    }

    // Display money
    void putMoney() const {
        cout << fixed << setprecision(2) << money;      //set precision to 2 decimal places "1234.56"
    }

    // Addition
    bMoney operator+(const bMoney& m) const {
        return bMoney(money + m.money);
    }

    // Subtraction
    bMoney operator-(const bMoney& m) const {
        return bMoney(money - m.money);
    }

    // Multiplication by long double
    bMoney operator*(long double n) const {
        return bMoney(money * n);
    }

    // Division: bMoney / bMoney  → gives long double
    long double operator/(const bMoney& m) const {
        return money / m.money;
    }

    // Division: bMoney / long double → gives bMoney
    bMoney operator/(long double n) const {
        return bMoney(money / n);
    }
};

int main() {
    bMoney m1, m2, result;
    long double num;

    while (true) {
        cout << "\n--- New Operation ---\n";
        cout << "Enter first money value: ";
        m1.getMoney();

        cout << "Enter second money value: ";
        m2.getMoney();

        cout << "Enter a floating-point number: ";
        cin >> num;

        // Perform operations
        result = m1 + m2;
        cout << "\nAddition: "; result.putMoney();

        result = m1 - m2;
        cout << "\nSubtraction: "; result.putMoney();

        result = m1 * num;
        cout << "\nMultiplication (m1 * num): "; result.putMoney();

        cout << "\nDivision (m1 / m2): " << (m1 / m2);

        result = m1 / num;
        cout << "\nDivision (m1 / num): "; result.putMoney();

        cout << "\nDo you want to continue? (y/n): ";
        char ch; cin >> ch;
        if (ch == 'n' || ch == 'N')
            break;
    }
    return 0;
}

