
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// ---------------- Sterling Class ----------------
class sterling {
private:
    long pounds;
    int shillings;
    int pence;

    void normalize() {
        if (pence >= 12) {
            shillings += pence / 12;
            pence %= 12;
        }
        if (shillings >= 20) {
            pounds += shillings / 20;
            shillings %= 20;
        }
    }

public:
    // Constructors
    sterling() : pounds(0), shillings(0), pence(0) {}
    sterling(double decPounds) {
        long totalPence = static_cast<long>(round(decPounds * 240));
        pounds = totalPence / 240;
        shillings = (totalPence % 240) / 12;
        pence = totalPence % 12;
    }
    sterling(long po, int sh, int pe) : pounds(po), shillings(sh), pence(pe) {
        normalize();
    }

    // I/O
    void getSterling() {
        char dummy;
        cout << "Enter amount (£p.s.d format, e.g. 9.19.11): £";
        cin >> pounds >> dummy >> shillings >> dummy >> pence;
        normalize();
    }
    void putSterling() const {
        cout << "£" << pounds << "." << shillings << "." << pence;
    }

    // Conversion to double (decimal pounds)
    operator double() const {
        return pounds + shillings / 20.0 + pence / 240.0;
    }
};

// ---------------- bMoney Class ----------------
class bMoney {
private:
    long double money;  // store value in dollars

public:
    // Constructors
    bMoney() : money(0.0) {}
    explicit bMoney(long double m) : money(m) {}

    void getMoney() {
        string s;
        cout << "Enter amount in dollars (e.g. 1234.56): $";
        cin >> s;
        money = stold(s);
    }
    void putMoney() const {
        cout << fixed << setprecision(2) << "$" << money;
    }

    operator long double() const { return money; }
};

// ---------------- Conversion Operators ----------------
const long double RATE = 50.0; // £1 = $50

// sterling → bMoney
inline bMoney sterlingToMoney(const sterling& s) {
    long double dollars = static_cast<double>(s) * RATE;
    return bMoney(dollars);
}

// bMoney → sterling
inline sterling moneyToSterling(const bMoney& m) {
    long double pounds = static_cast<long double>(m) / RATE;
    return sterling(static_cast<double>(pounds));
}

// ---------------- Main ----------------
int main() {
    char choice;
    cout << "Convert (s)terling or (m)oney? ";
    cin >> choice;

    if (choice == 's' || choice == 'S') {
        sterling s;
        s.getSterling();
        bMoney m = sterlingToMoney(s);
        cout << "\nEquivalent in dollars: ";
        m.putMoney();
    } 
    else if (choice == 'm' || choice == 'M') {
        bMoney m;
        m.getMoney();
        sterling s = moneyToSterling(m);
        cout << "\nEquivalent in sterling: ";
        s.putSterling();
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    cout << endl;
    return 0;
}

