#include <iostream>
#include <cstdlib>   // for exit()
#include <cmath>     // for abs()
using namespace std;

class fraction {
private:
    int num, den;   // numerator and denominator

public:
    // default + parameterized constructor
    fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        lowterms();
    }

    // input from user
    void getFraction() {
        char slash;
        cout << "Enter fraction (n/d): ";
        cin >> num >> slash >> den;
        lowterms();
    }

    // ✨ set function
    void setFraction(int n, int d) {
        num = n;
        den = d;
        lowterms();   // reduce automatically
    }

    // display fraction
    void showFraction() const {
        cout << num << "/" << den;
    }

    // add two fractions
    fraction add(fraction f) {
        return fraction(num * f.den + den * f.num, den * f.den);
    }

    // reduce to lowest terms
    void lowterms() {
        int tnum = abs(num);
        int tden = abs(den);
        if (tden == 0) {
            cout << "Illegal fraction: division by 0" << endl;
            exit(1);
        } else if (tnum == 0) {
            num = 0; den = 1; return;
        }

        while (tnum != 0) {
            if (tnum < tden)
                swap(tnum, tden);
            tnum = tnum - tden;
        }
        int gcd = tden;
        num = num / gcd;
        den = den / gcd;
    }
};

int main() {
    fraction f1, f2, result;

    // abhi sirf input + addition dikhaya hai
    f1.getFraction();
    f2.getFraction();

    result = f1.add(f2);

    cout << "Result = ";
    result.showFraction();
    cout << endl;

    return 0;
}
