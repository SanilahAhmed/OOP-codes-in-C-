#include <iostream>
using namespace std;

// Function to find the index of the largest element (LOGIC SAME)
int maxint(int arr[], int size) {
    int maxIndex = 0; 
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// CLASS ADDED (uses same arr and n)
class ArrayHandler {
private:
    int arr[100];
    int n;

public:
    // Constructor
    ArrayHandler() {
        n = 0;
        cout << "Constructor called.\n";
    }

    // Setter for size
    void setSize(int size) {
        n = size;
    }

    // Setter for array element
    void setElement(int index, int value) {
        arr[index] = value;
    }

    // Getter for array element
    int getElement(int index) {
        return arr[index];
    }

    // Function to return size
    int getSize() {
        return n;
    }

    // Show all elements
    void show() {
        cout << "Array elements: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to access internal array (for maxint)
    int* getArray() {
        return arr;
    }

    // Destructor
    ~ArrayHandler() {
        cout << "Destructor called.\n";
    }
};

int main() {
    ArrayHandler obj;  // object created

    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    obj.setSize(n);  // set size

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        obj.setElement(i, x);  // using setter
    }

    cout << "\nYou entered:\n";
    obj.show();  // show array

    // LOGIC SAME: call maxint()
    int index = maxint(obj.getArray(), obj.getSize());

    cout << "\nLargest element: " << obj.getElement(index) << endl;
    cout << "Index of largest element: " << index << endl;

    return 0;
}
