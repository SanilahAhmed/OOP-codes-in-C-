#include <iostream>
using namespace std;

class Reverser {
private:
    string str;

public:
    // Constructor
    Reverser() {
        str = "";
    }

    // Setter
    void setStr(string s) {
        str = s;
    }

    // Getter
    string getStr() {
        return str;
    }

    // Function to reverse the string
    void reversit() {
        int start = 0;
        int end = str.length() - 1;

        for(; start < end; start++, end--) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
        }
    }

    // Display function
    void show() {
        cout << "Reversed string: " << str << endl;
    }

    // Destructor
    ~Reverser() {
        // Just to show destructor is called
        // (optional message)
    }
};

int main() {
    Reverser r;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    r.setStr(input);   // store string
    r.reversit();      // reverse string
    r.show();          // show result

    return 0;
}
