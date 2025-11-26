#include <iostream>
using namespace std;

float memory[100];
int mem_top = 0;

class Float {
private:
    int addr;   // index in memory array

public:
    // Constructor
    Float(float value) {
        addr = mem_top;
        memory[mem_top] = value;
        mem_top++;
    }

    // Setter
    void set(float value) {
        memory[addr] = value;
    }

    // Getter
    float get() {
        return memory[addr];
    }

    // Display
    void display() {
        cout << memory[addr] << endl;
    }

    // Give address
    int getAddress() {
        return addr;
    }

    // Destructor (nothing to delete)
    ~Float() {}
};

// Pointer to Float
class ptrFloat {
private:
    int addr;   // stores address of memory index

public:
    // Constructor
    ptrFloat(int address) {
        addr = address;
    }

    // Dereference
    float& operator*() { // *p1 jb called and & return reference
        return memory[addr]; // memory[100] array 
    }

    // Display
    void display() {
        cout << memory[addr] << endl;
    }

    // Destructor
    ~ptrFloat() {}
};

// MAIN
int main() {
    Float var1(1.234);
    Float var2(5.678);

    ptrFloat p1(var1.getAddress());
    ptrFloat p2(var2.getAddress());

    cout << "p1 points to: " << *p1 << endl;
    cout << "p2 points to: " << *p2 << endl;

    *p1 = 7.123;
    *p2 = 8.456;

    cout << "After change:" << endl;
    cout << "var1 = " << var1.get() << endl;
    cout << "var2 = " << var2.get() << endl;
}
