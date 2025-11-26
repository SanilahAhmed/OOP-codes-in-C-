#include <iostream>
using namespace std;

class Fraction {
private:
    int num;    // numerator
    int den;    // denominator

public:
    // Constructor
    Fraction() {
        num = 0;
        den = 1;
    }

    // Setter
    void setFraction(int n, int d) {
        num = n;
        den = d;
    }

    // Input from user
    void getdata() {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;
    }

   
    void addFraction(Fraction f2) {
        num = num * f2.den + den * f2.num;   //  a/b + c/d = (ad + bc) / bd
        den = den * f2.den;
    }

    // Divide a fraction by an integer (for averaging)
    void divFraction(Fraction f, int n) {
        num = f.num;
        den = f.den * n;   // When you divide a fraction by a whole number,
                          //you multiply its denominator by that number.
    }

    // Display fraction
    void show() {
        cout << num << "/" << den << endl;
    }

    // Destructor
    ~Fraction() {
        // nothing required
    }
};

int main() {
    Fraction arr[100];   // array of fractions
    Fraction total;      // sum of fractions
    Fraction average;    // average fraction

    int n;

    cout << "How many fractions (max 100)? ";
    cin >> n;

    cout << endl;

    // Input fractions
    for (int i = 0; i < n; i++) {
        cout << "Fraction " << i + 1 << endl;
        arr[i].getdata();
        total.addFraction(arr[i]);
        cout << endl;
    }

    // Average = total / number_of_fractions
    average.divFraction(total, n);

    cout << "Average of all fractions = ";
    average.show();

    return 0;
}
