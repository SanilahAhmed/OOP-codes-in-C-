#include <iostream>
using namespace std;

class SafeArray {
private:
    int arr[100];       // actual array
    int lower;          // user-specified lower bound
    int upper;          // user-specified upper bound

public:
    // Constructor with lower and upper bounds
    SafeArray(int l = 0, int u = 99) {
        if (u - l + 1 > 100) { 
            cout << "Error: Array size exceeds 100.\n";
            upper = l + 99;
        } else {
            lower = l;
            upper = u;
        }
    }

    // Setter
    void set(int index, int value) {
        if (index < lower || index > upper) { // 0 <  index < 100
            cout << "Error: Index " << index << " out of bounds.\n";
            return;
        }
        arr[index - lower] = value;  // arr[0-0]=value;
    }

    // Getter
    int get(int index) const {
        if (index < lower || index > upper) {
            cout << "Error: Index " << index << " out of bounds.\n";
            return 0;
        }
        return arr[index - lower];
    }

    // Overloaded subscript operator []
    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "Error: Index " << index << " out of bounds.\n";
            // Return first element as fallback
            return arr[0];
        }
        return arr[index - lower];  // map to actual array index
    }

    // Display array contents
    void display() const {
        cout << "SafeArray contents:\n";
        for (int i = lower; i <= upper; i++) {
            cout << "Index " << i << ": " << arr[i - lower] << "\n";
        }
    }
};

int main() {
    SafeArray sa(100, 110);  // indexes from 100 to 110

    // Set values
    for (int i = 100; i <= 110; i++) {
        sa[i] = i * 2; // sa[100] = 200 .
    }

    // Display values
    sa.display();

    // Access an out-of-bounds index
    sa[115] = 500;  // Error

    return 0;
}
