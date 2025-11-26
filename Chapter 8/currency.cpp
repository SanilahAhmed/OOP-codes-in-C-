
#include <iostream>
#include <cmath>
using namespace std;

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
    // no-argument constructor
    sterling() : pounds(0), shillings(0), pence(0) {}


    sterling(double decPounds) {
        long totalPence = static_cast<long>(round(decPounds * 240)); // 240 pence per pound
        pounds = totalPence / 240;                           // decpounds ko multiply kaarake round kara then
        shillings = (totalPence % 240) / 12;                 // long mein convert kara
        pence = totalPence % 12;
    }

    // three-argument constructor
    sterling(long po, int sh, int pe) : pounds(po), shillings(sh), pence(pe) {
        normalize();
    }

    // input
    int getSterling() {
        char dummy;
        cout << "Enter amount (£p.s.d format, e.g. 9.19.11): £";
        cin >> pounds >> dummy >> shillings >> dummy >> pence;
        normalize();
    }

    // output
    void putSterling() const {
        cout << "£" << pounds << "." << shillings << "." << pence;
    }

    // conversion operator to double (decimal pounds)
    operator double() const {
        return pounds + shillings / 20.0 + pence / 240.0;
    }

    // addition
    sterling operator+(const sterling& s2) const {
        return sterling(double(*this) + double(s2));
    }

    // subtraction
    sterling operator-(const sterling& s2) const {
        return sterling(double(*this) - double(s2));
    }

    // multiplication by double
    sterling operator*(double n) const {
        return sterling(double(*this) * n);
    }

    // division sterling / sterling (returns double)
    double operator/(const sterling& s2) const {
        return double(*this) / double(s2);
    }

    // division sterling / double
    sterling operator/(double n) const {
        return sterling(double(*this) / n);
    }
};

int main() {
    sterling s1, s2, s3;
    double num;

    cout << "Enter first sterling amount:\n";
    s1.getSterling();

    cout << "Enter second sterling amount:\n";
    s2.getSterling();

    cout << "Enter a decimal number: ";
    cin >> num;

    cout << "\nYou entered:\n";
    cout << "s1 = "; s1.putSterling(); cout << endl;
    cout << "s2 = "; s2.putSterling(); cout << endl;

    // test operations
    s3 = s1 + s2;
    cout << "\ns1 + s2 = "; s3.putSterling();

    s3 = s1 - s2;
    cout << "\ns1 - s2 = "; s3.putSterling();

    s3 = s1 * num;
    cout << "\ns1 * num = "; s3.putSterling();

    cout << "\ns1 / s2 = " << (s1 / s2);

    s3 = s1 / num;
    cout << "\ns1 / num = "; s3.putSterling();

    cout << endl;
    return 0;
}

