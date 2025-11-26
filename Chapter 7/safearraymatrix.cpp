#include <iostream>
using namespace std;

class Matrix {
private:
int arr[10][10];
int rows;
int cols;

public:
// Constructor
Matrix(int r, int c) {
if(r > 10) r = 10;
if(c > 10) c = 10;
rows = r;
cols = c;

    // Initialize all elements to 0  
    for(int i = 0; i < rows; i++) {  
        for(int j = 0; j < cols; j++) {  
            arr[i][j] = 0;  
        }  
    }  
}  

// Destructor  
~Matrix() {  
    // nothing needed  
}  

// Setter  
void putel(int r, int c, int val) {  
    if(r >= 0 && r < rows && c >= 0 && c < cols)  
        arr[r][c] = val;  
    else  
        cout << "Index out of bounds!" << endl;  
}  

// Getter  
int getel(int r, int c) {  
    if(r >= 0 && r < rows && c >= 0 && c < cols)  
        return arr[r][c];  
    else {  
        cout << "Index out of bounds!" << endl;  
        return -1;  
    }  
}  

// Show matrix  
void show() {  
    for(int i = 0; i < rows; i++) {  
        for(int j = 0; j < cols; j++) {  
            cout << arr[i][j] << " ";  
        }  
        cout << endl;  
    }  
}  


};

int main() {
Matrix m1(3, 4); // 3 rows, 4 columns
int temp = 12345;


m1.putel(2, 3, temp); // put value  
temp = m1.getel(2, 3); // get value  

cout << "Value at (2,3): " << temp << endl;  
cout << "Matrix contents:" << endl;  
m1.show();  

return 0;  


}
