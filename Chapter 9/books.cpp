#include <iostream>
#include <string>
using namespace std;

// Base class
class publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // clear buffer
    }

    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class
class disk : public publication {
private:
    char diskType; // 'C' for CD, 'D' for DVD

public:
    void getdata() {
        publication::getdata(); // get base data
        cout << "Enter disk type (C for CD / D for DVD): ";
        cin >> diskType;
    }

    void putdata() {
        publication::putdata();
        cout << "Disk Type: " << (diskType == 'C' ? "CD" : "DVD") << endl;
    }
};

// Main function
int main() {
    disk d1;

    cout << "--- Enter Disk Information ---\n";
    d1.getdata();

    cout << "\n--- Displaying Disk Information ---\n";
    d1.putdata();

    return 0;
}
