#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** arr;    // pointer to pointer (2D array)

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        arr = new int*[rows];                // 3 rows ka arr jo hr row elemt ko pint karay
        for(int i = 0; i < rows; i++) {
            arr[i] = new int[cols];          // 4 cols ka array har row k liye
        }
    }
    //[ ptr ] → [ int int int int ]
    //[ ptr ] → [ int int int int ]
    //[ ptr ] → [ int int int int ]

    // Destructor
    ~Matrix() {
        for(int i = 0; i < rows; i++) {
            delete[] arr[i];                 // delete rows
        }
        delete[] arr;                        // delete pointer array
    }

    // Setter
    void setValue(int r, int c, int value) {
        *(*(arr + r) + c) = value;           // arr[r][c] = value;

    }

    // Getter
    int getValue(int r, int c) {
        return *(*(arr + r) + c);            // pointer notation
    }

    // Display function
    void display() {
        cout << "Matrix:\n";
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << *(*(arr + i) + j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix m(r, c);

    // Input values
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int val;
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> val;
            m.setValue(i, j, val);
        }
    }

    // Display matrix
    m.display();

    return 0;
}
