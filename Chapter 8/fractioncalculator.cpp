#include <iostream>
using namespace std;

// Function to calculate GCD
int gcd(int a, int b) { // a= 4, b= 8
    while (b != 0) { 
        int temp = b;  // temp = 8
        b = a % b; // b = 4 % 8 = 4
        a = temp; // a = 8
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        lowterms();
    }

    // Destructor
    ~Fraction() { }

    // Setter
    void set(int n, int d) {
        numerator = n;
        denominator = d;
        lowterms();
    }

    // Display function
    void display() const {
        cout << numerator << "/" << denominator;
    }

    // Reduce fraction to lowest terms
    void lowterms() {
        if (denominator < 0) {  // make denominator positive
            numerator = -numerator; // if num= 3,then num= -3
            denominator = -denominator; // if den= -4, then den= 4(make it positive)
        }
        int g = gcd(abs(numerator), denominator); // if num= -3, den= 4, then g=1
        numerator /= g; // if num= -3, g=1, then num= -3/1= -3
        denominator /= g; // if den= 4, g=1, then den= 4/1= 4
    }

    // Overloaded + operator
    Fraction operator+(const Fraction& f) const {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded - operator
    Fraction operator-(const Fraction& f) const {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded * operator
    Fraction operator*(const Fraction& f) const {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded / operator
    Fraction operator/(const Fraction& f) const {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }

    // Overloaded == operator
    bool operator==(const Fraction& f) const {
        return numerator == f.numerator && denominator == f.denominator;
    }

    // Overloaded != operator
    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }
};

int main() {
    while (true) {
        int n1, d1, n2, d2;
        cout << "Enter first fraction (numerator denominator): ";
        cin >> n1 >> d1;
        cout << "Enter second fraction (numerator denominator): ";
        cin >> n2 >> d2;

        Fraction f1(n1, d1), f2(n2, d2);

        // Exit condition if both fractions are 0/1
        Fraction zero(0, 1);
        if (f1 == zero && f2 == zero) {
            cout << "Both fractions are 0/1. Exiting.\n";
            break;
        }

        Fraction sum = f1 + f2;
        Fraction diff = f1 - f2;
        Fraction prod = f1 * f2;
        Fraction quot = f1 / f2;

        cout << "Sum: ";
        sum.display();
        cout << "\nDifference: ";
        diff.display();
        cout << "\nProduct: ";
        prod.display();
        cout << "\nQuotient: ";
        quot.display();
        cout << "\n\n";
    }

    return 0;
}
