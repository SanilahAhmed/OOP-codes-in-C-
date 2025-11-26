#include <iostream>
#include <cstring>
using namespace std;

class Part {
private:
    char partName[30];
    int partNumber;
    double cost;

public:
    // Default constructor
    Part() {
        strcpy(partName, ""); // initialize to empty string
        partNumber = 0;
        cost = 0.0;
    }

    // Parameterized constructor
    Part(const char name[], int number, double c) {
        strcpy(partName, name);
        partNumber = number;
        cost = c;
    }

    // Destructor
    ~Part() {
        // nothing to free
    }

    // Setter
    void setPart(const char name[], int number, double c) {
        strcpy(partName, name);
        partNumber = number;
        cost = c;
    }

    // Getter (simple example)
    const char* getName() const { // returns part name's char array address
        return partName;
    }

    // Show Function
    void showPart() const {
        cout << "\nName=" << partName
             << ", number=" << partNumber
             << ", cost=$" << cost;
    }
};

int main() {
    Part p1, p2;

    p1.setPart("handle bolt", 4473, 217.55);
    p2.setPart("start lever", 9924, 419.25);

    cout << "\nFirst part:";  
    p1.showPart();

    cout << "\nSecond part:"; 
    p2.showPart();

    cout << endl;
    return 0;
}
