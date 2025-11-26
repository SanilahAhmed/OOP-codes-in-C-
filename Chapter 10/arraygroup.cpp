#include <iostream>
using namespace std;

class ArrayGroup {
private:
    int* arr[10];     // array of 10 int pointers
    int maxSize;

public:
    // Constructor
    ArrayGroup(int size) {
        maxSize = size;
        for (int i = 0; i < 10; i++) {
            arr[i] = new int[maxSize];  // allocate each array
        }
    }

    // Setter: set value in array i, index j
    void setValue(int arrayNum, int index, int value) {
        arr[arrayNum][index] = value;
    }

    // Getter
    int getValue(int arrayNum, int index) {
        return arr[arrayNum][index];
    }

    // Display all arrays
    void display() {
        for (int i = 0; i < 10; i++) {
            cout << "Array " << i << ": ";
            for (int j = 0; j < maxSize; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~ArrayGroup() {
        for (int i = 0; i < 10; i++) {
            delete[] arr[i];
        }
    }
};

// MAIN
int main() {
    ArrayGroup ag(5);

    // Fill arrays with sample values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            ag.setValue(i, j, i + j);
        }
    }

    ag.display();
}
