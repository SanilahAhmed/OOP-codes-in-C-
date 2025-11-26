#include <iostream>
using namespace std;

class safearay {
private:
    static const int LIMIT = 10;  // fixed size
    int arr[LIMIT];

public:
    // Constructor
    safearay() {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }

    // Setter (putel)
    void putel(int index, int value) {
        if (index < 0 || index >= LIMIT) {
            cout << "Index out of bounds!\n";
            return;
        }
        arr[index] = value;
    }

    // Getter (getel)
    int getel(int index) {
        if (index < 0 || index >= LIMIT) {
            cout << "Index out of bounds!\n";
            return 0;
        }
        return arr[index];
    }

    // Show the array
    void show() {
        cout << "Array elements: ";
        for (int i = 0; i < LIMIT; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~safearay() {
        // nothing to destroy
    }
};

int main() {
    safearay sa1;
    int temp = 12345;

    sa1.putel(7, temp);     // insert value at index 7
    temp = sa1.getel(7);    // read value back

    cout << "Value at index 7: " << temp << endl;

    sa1.show();             // display entire array

    return 0;
}
