#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person() : name(""), age(0) {}

    // Destructor
    ~Person() {}

    // Setter
    void setData(string n, int a) {
        name = n;
        age = a;
    }

    // Getter
    string getName() { return name; }
    int getAge() { return age; }

    // Display
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class PersonArray {
private:
    Person* arr;   // pointer to array of Person objects
    int size;

public:
    // Constructor
    PersonArray(int s) : size(s) {
        arr = new Person[size];   // allocate array of objects
    }

    // Destructor
    ~PersonArray() {
        delete[] arr;
    }

    // Setter for an object
    void setPerson(int index, string name, int age) {
        if (index >= 0 && index < size)
            (arr + index)->setData(name, age);   // pointer notation
    }

    // Getter
    Person* getPerson(int index) {
        if (index >= 0 && index < size)
            return (arr + index);               // pointer to that object
        else
            return NULL;
    }

    // Display all persons
    void displayAll() {
        for (int i = 0; i < size; i++) {
            (arr + i)->display();
        }
    }
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    PersonArray pa(n);

    // Input
    for (int i = 0; i < n; i++) {
        string name;
        int age;

        cout << "Enter name for person " << i + 1 << ": ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        pa.setPerson(i, name, age);
    }

    cout << "\nDisplaying All Persons:\n";
    pa.displayAll();

    return 0;
}
