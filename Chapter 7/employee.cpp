#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    long number;

public:
    // Constructor
    Employee() {
        name = "";
        number = 0;
    }

    // Setter (optional, but included because OOP)
    void setName(string n) {
        name = n;
    }

    void setNumber(long num) {
        number = num;
    }

    // Getter
    string getName() {
        return name;
    }

    long getNumber() {
        return number;
    }

    // Get data from user
    void getdata() {
        cout << "Enter employee name (no spaces): ";
        cin >> name;

        cout << "Enter employee number: ";
        cin >> number;
    }

    // Show data
    void putdata() {
        cout << "Name: " << name << ", Number: " << number << endl;
    }

    // Destructor
    ~Employee() {
        // Optional message or cleanup
    }
};

int main() {
    Employee emp[100];
    int n;

    cout << "How many employees (max 100)? ";
    cin >> n;

    cout << endl;

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "Employee " << i + 1 << endl;
        emp[i].getdata();
        cout << endl;
    }

    // Output data
    cout << "\n----- Employee Data -----\n";
    for (int i = 0; i < n; i++) {
        emp[i].putdata();
    }

    return 0;
}
