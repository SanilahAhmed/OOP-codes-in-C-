#include <iostream>
using namespace std;

class Money {
private:
    string moneyStr;   // original money string
    string cleanStr;   // only digits and decimal

public:
    // Constructor
    Money() {
        moneyStr = "";
        cleanStr = "";
    }

    // Setter
    void setMoney(string s) {
        moneyStr = s;
    }

    // Convert and clean the string
    void makeClean() {
        cleanStr = "";
        for (int i = 0; i < moneyStr.length(); i++) {
            char ch = moneyStr[i];

            if ((ch >= '0' && ch <= '9') || ch == '.') {
                cleanStr += ch;   // it keeps only numbers and dots from the input.
            }
        }
    }

    // Getter (returns clean string)
    string getClean() {
        return cleanStr;
    }

    // Convert clean string to long double (mstold)
    long double mstold() {
        makeClean();   // clean first

        long double value = 0;
        int i = 0;
        bool decimalFound = false;
        long double decimalPlace = 0.1;

        // Manual conversion (no extra library)
        while (i < cleanStr.length()) {
            char ch = cleanStr[i];

            if (ch == '.') {
                decimalFound = true;
            }
            else {
                int digit = ch - '0'; // convert char to int

                if (!decimalFound) {
                    value = value * 10 + digit; // for 123.45;   0*10+1=1;  1*10+2=12;  12*10+3=123;
                }
                else {
                    value = value + digit * decimalPlace; // value = 123 + 4 * 0.1 = 123.4
                    decimalPlace /= 10;  // decimalPlace becomes 0.01 for next digit
                }
            }
            i++;
        }

        return value;
    }

    // Show clean version
    void show() {
        cout << "Clean number: " << cleanStr << endl;
    }

    // Destructor
    ~Money() {
        // nothing to delete
    }
};

int main() {
    Money m;
    string s;

    cout << "Enter money string: ";
    cin >> s;

    m.setMoney(s);

    long double val = m.mstold();

    m.show();

    cout << "As long double: " << val << endl;

    return 0;
}
