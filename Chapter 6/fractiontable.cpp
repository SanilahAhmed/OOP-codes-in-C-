#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class fraction {
private:
    int num, den;

public:
    // constructor
    fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        lowterms();
    }

    // display
    void showFraction() const {
        cout << num << "/" << den;
    }

    // multiplication
    fraction mul(const fraction& f) const {
        return fraction(num * f.num, den * f.den);
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
    int denom;
    cout << "Enter a denominator: ";
    cin >> denom;

    // Fractions between 0 and 1 with given denominator
    fraction fracs[100];
    int count = 0;

    for (int i = 1; i < denom; i++) {
        fracs[count++] = fraction(i, denom);
    }

    // print header row
    for (int i = 0; i < count; i++) {
        fracs[i].showFraction();
        cout << "\t";
    }
    cout << "\n---------------------------------------------\n";

    // multiplication table
    for (int i = 0; i < count; i++) {
        fracs[i].showFraction();   // first column
        cout << "\t";

        for (int j = 0; j < count; j++) {
            fraction result = fracs[i].mul(fracs[j]);
            result.showFraction();
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
