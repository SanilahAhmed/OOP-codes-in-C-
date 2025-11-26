#include <iostream>
#include <cstdlib>   // for exit()
using namespace std;

class Int {
private:
    int value;

    // Helper function to check 32-bit int range
    void checkOverflow(long double result) const {
        if (result > 2147483647 || result < -2147483648) {
            cout << "Error: Integer overflow detected!\n";
            exit(1);
        }
    }

public:
    // Constructor
    Int(int v = 0) {
        value = v;
    }

    // Destructor
    ~Int() { }

    // Setter
    void set(int v) {
        value = v;
    }

    // Getter
    int get() const {
        return value;
    }

    // Display
    void display() const {
        cout << value;
    }

    // Overloaded +
    Int operator+(const Int& obj) const {
        long double result = (long double)value + obj.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded -
    Int operator-(const Int& obj) const {
        long double result = (long double)value - obj.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded *
    Int operator*(const Int& obj) const {
        long double result = (long double)value * obj.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded /
    Int operator/(const Int& obj) const {
        if (obj.value == 0) {
            cout << "Error: Division by zero!\n";
            exit(1);
        }
        long double result = (long double)value / obj.value;
        checkOverflow(result);
        return Int((int)result);
    }
};

int main() {
    Int a(1000000);
    Int b(3000);

    Int c = a * b;   // multiplication
    cout << "a * b = ";
    c.display();
    cout << "\n";

    Int d = a + b;
    cout << "a + b = ";
    d.display();
    cout << "\n";

    Int e = a - b;
    cout << "a - b = ";
    e.display();
    cout << "\n";

    Int f = a / b;
    cout << "a / b = ";
    f.display();
    cout << "\n";

    // Uncomment to test overflow
    // Int big(2147483640);
    // Int x(10);
    // Int o = big + x;   // should trigger overflow

    return 0;
}
