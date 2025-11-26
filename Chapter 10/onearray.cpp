#include <iostream>
using namespace std;

class OneArray {
private:
    int* data;
    int totalSize;

public:
    // Constructor
    OneArray(int arrayCount, int sizePerArray) {
        totalSize = arrayCount * sizePerArray;
        data = new int[totalSize];
    }

    // Setter
    void setValue(int index, int value) {
        data[index] = value;
    }

    // Getter
    int getValue(int index) {
        return data[index];
    }

    // Overloaded []
    int& operator[](int index) {
        return data[index];
    }

    // Display
    void display() {
        for (int i = 0; i < totalSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~OneArray() {
        delete[] data;
    }
};

// MAIN
int main() {
    OneArray arr(10, 5); // 10 arrays × 5 elements = 50 values

    for (int i = 0; i < 50; i++) {
        arr[i] = i * 2;
    }

    arr.display();
}
