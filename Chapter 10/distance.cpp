#include <iostream>
using namespace std;

class Distance {
private:
    int* feet;
    int* inches;

public:
    // Constructor
    Distance() {
        feet = new int;
        inches = new int;
        *feet = 0;
        *inches = 0;
    }

    // Destructor
    ~Distance() {
        delete feet;
        delete inches;
    }

    // Setter
    void setDistance(int f, int i) {
        *feet = f;
        *inches = i;

        // auto adjustment
        while (*inches >= 12) {
            *inches -= 12;
            (*feet)++;
        }
    }

    // Getter - return feet
    int getFeet() {
        return *feet;
    }

    // Getter - return inches
    int getInches() {
        return *inches;
    }

    // Display
    void display() {
        cout << *feet << " feet " << *inches << " inches" << endl;
    }
};

int main() {
    Distance d;

    int f, i;
    cout << "Enter feet: ";
    cin >> f;
    cout << "Enter inches: ";
    cin >> i;

    d.setDistance(f, i);

    cout << "\nStored Distance: ";
    d.display();

    cout << "Feet (getter) = " << d.getFeet() << endl;
    cout << "Inches (getter) = " << d.getInches() << endl;

    return 0;
}
