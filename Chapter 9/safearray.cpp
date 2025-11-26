#include <iostream>
using namespace std;

const int LIMIT = 10; // maximum array size

class safearay {
private:
    int arr[LIMIT];

public:
    // Insert element
    void putel(int index, int value) {
        if (index < 0 || index >= LIMIT) {
            cout << "Error: Index out of range!\n";
            return;
        }
        arr[index] = value;
    }

    // Get element
    int getel(int index) {
        if (index < 0 || index >= LIMIT) {
            cout << "Error: Index out of range!\n";
            return -1; // return invalid value
        }
        return arr[index];
    }
};

int main() {
    safearay sa1;
    int temp = 12345;

    sa1.putel(7, temp);       // store value at index 7
    cout << "Stored 12345 at index 7\n";

    temp = sa1.getel(7);      // retrieve it
    cout << "Value at index 7 = " << temp << endl;

    // Example of invalid index
    sa1.putel(12, 999); // should show error

    return 0;
}
