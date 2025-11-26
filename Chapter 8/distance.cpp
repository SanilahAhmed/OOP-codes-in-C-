#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor (default + parameterized)
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        normalize();
    }

    // Destructor
    ~Distance() {
        // nothing to clean, but required by question
    }

    // Setter
    void setDistance(int f, int i) {
        feet = f;
        inches = i;
        normalize();
    }

    // Getter
    void getDistance(int &f, int &i) const {
        f = feet;
        i = inches;
    }

    // Display Function
    void display() const {
        cout << feet << " feet " << inches << " inches";
    }

    // Normalize inches to feet if >= 12
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // Overloaded - operator
    Distance operator-(const Distance& d) const {
        Distance temp;

        int total1 = feet * 12 + inches;
        int total2 = d.feet * 12 + d.inches;

        int diff = total1 - total2;   // assume diff >= 0 (as question says)

        temp.feet = diff / 12;
        temp.inches = diff % 12;

        return temp;
    }
};

int main() {
    Distance dist1(5, 8);   // 5 feet 8 inches
    Distance dist2(2, 10);  // 2 feet 10 inches

    Distance dist3 = dist1 - dist2;  // subtraction

    cout << "Distance 1: ";
    dist1.display();
    cout << "\n";

    cout << "Distance 2: ";
    dist2.display();
    cout << "\n";

    cout << "Result (dist1 - dist2): ";
    dist3.display();
    cout << "\n";

    return 0;
}
