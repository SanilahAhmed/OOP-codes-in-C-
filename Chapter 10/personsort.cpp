#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person() { 
        name = ""; 
    }

    ~Person() {
        // Destructor (nothing special)
    }

    void setName() {
        cout << "Enter name: ";
        cin >> name;
    }

    string getName() const {
        return name;
    }

    void show() const {
        cout << name << endl;
    }
};

// Bubble sort using POINTERS
void sortPersons(Person* arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if( (*arr[i]).getName() > (*arr[j]).getName() ) {
                Person* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    Person* persons[100];
    int n = 0;
    char choice;

    do {
        persons[n] = new Person;

        (*persons[n]).setName();
        n++;

        cout << "Enter another (y/n)? ";
        cin >> choice;

    } while(choice == 'y');

    cout << "\nUnsorted list:\n";
    for(int i = 0; i < n; i++)
        (*persons[i]).show();

    sortPersons(persons, n);

    cout << "\nSorted list:\n";
    for(int i = 0; i < n; i++)
        (*persons[i]).show();

    // Free memory
    for(int i = 0; i < n; i++)
        delete persons[i];

    return 0;
}
