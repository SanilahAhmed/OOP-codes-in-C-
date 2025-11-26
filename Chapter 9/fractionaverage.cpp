#include <iostream>
using namespace std;

class Fraction {
private:
    int num; // numerator
    int den; // denominator

public:
    // Input function
    void getdata() {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;
    }

    // Convert to decimal
    double toDecimal() {
        return (double)num / den;
    }
};

int main() {
    int n;
    cout << "How many fractions? ";
    cin >> n;

    Fraction f[100];
    double sum = 0;

    // Input and sum fractions
    for (int i = 0; i < n; i++) {
        cout << "\nFraction " << i + 1 << ":\n";
        f[i].getdata();
        sum += f[i].toDecimal();
    }

    // Calculate and display average
    cout << "\nAverage (in decimal) = " << sum / n << endl;

    return 0;
}
