#include <iostream>
using namespace std;

class Height {
private:
    int feet;
    int inches;

public:
    // Constructor
    Height(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        cout << "Constructor called!" << endl;
    }

    // Setter (SET statement)
    void setHeight(int f, int i) {
        feet = f;
        inches = i;
    }

    // Getter (GET statement)
    void getHeight(int &f, int &i) {
        f = feet;
        i = inches;
    }

    // Print function
    void printHeight() {
        cout << "Height: " << feet << " feet " << inches << " inches" << endl;
    }

    // Destructor
    ~Height() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    // Using constructor
    Height h1(5, 8);

    // Print height
    h1.printHeight();

    // Change height using set
    h1.setHeight(6, 2);

    // Print again
    h1.printHeight();

    // Get values using get
    int f, i;
    h1.getHeight(f, i);
    cout << "Using GET -> Feet: " << f << ", Inches: " << i << endl;

    // Destructor will be called automatically when object goes out of scope
    return 0;
}
