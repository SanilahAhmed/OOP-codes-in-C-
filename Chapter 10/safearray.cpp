#include <iostream>
using namespace std;

class SafeArray {
private:
    int size;
    int* arr;     // pointer to integer array

public:
    // Constructor
    SafeArray(int s = 10) : size(s) {
        arr = new int[size];
    }

    // Destructor
    ~SafeArray() {
        delete[] arr;
    }

    // Setter
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            *(arr + index) = value;
        } else {
            cout << "Error: Index out of range!\n";
        }
    }

    // Getter
    int getValue(int index) {
        if (index >= 0 && index < size) {
            return *(arr + index);
        } else {
            cout << "Error: Index out of range!\n";
            return -1;
        }
    }

    // Display function
    void display() {
        cout << "Array values: ";
        for (int i = 0; i < size; i++) {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    SafeArray obj(n);

    // Take input
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter value " << i + 1 << ": ";
        cin >> x;
        obj.setValue(i, x);
    }

    // Display
    obj.display();

    // Test getter
    cout << "Value at index 0 = " << obj.getValue(0) << endl;

    return 0;
}
