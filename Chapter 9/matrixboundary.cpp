#include <iostream>
using namespace std;

const int MAX = 10;

class matrix {
private:
    int arr[MAX][MAX];
    int rows, cols;

public:
    // Constructor to set matrix size
    matrix(int r, int c) {
        if (r > MAX) r = MAX;
        if (c > MAX) c = MAX;
        rows = r;
        cols = c;
    }

    // Put element
    void putel(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Error: Index out of range!\n";
            return;
        }
        arr[r][c] = value;
    }

    // Get element
    int getel(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Error: Index out of range!\n";
            return -1;
        }
        return arr[r][c];
    }

    // Display matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    matrix m1(3, 4);  // 3x4 matrix
    int temp = 12345;

    m1.putel(2, 3, temp); // store value
    cout << "Value stored at (2,3)\n";

    temp = m1.getel(2, 3); // retrieve value
    cout << "Value at (2,3): " << temp << endl;

    cout << "\nMatrix Contents:\n";
    m1.display();

    return 0;
}
