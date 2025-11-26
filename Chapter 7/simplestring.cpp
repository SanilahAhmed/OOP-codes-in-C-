#include <iostream>
#include <cstring>
using namespace std;

class SimpleString {
private:
    enum { SIZE = 80 }; // enum : named constant
    char str[SIZE];

public:
    // Default constructor
    SimpleString() {
        str[0] = '\0'; // initialize to empty string
    }

    // Parameterized constructor
    SimpleString(const char s[]) {
        strcpy(str, s);
    }

    // Destructor
    ~SimpleString() {
        // nothing to free (no dynamic memory)
    }

    // Setter
    void setString(const char s[]) {
        strcpy(str, s);
    }

    // Getter
    const char* getString() const { //return address of string and is not modifiable 'const'
        return str;
    }

    // Show function
    void show() const {
        cout << str; // it shows the string not the address
    }

    // Concatenation // combine two strings

    void concat(const SimpleString& s2) { // reference to class object
        if (strlen(str) + strlen(s2.str) < SIZE)
            strcat(str, s2.str);
        else
            cout << "\nString too long!";
    }
};

int main() {
    SimpleString s1("As salam o Alekum! ");
    SimpleString s2("May this season be full of blessings!");
    SimpleString s3;

    cout << "\ns1="; s1.show();
    cout << "\ns2="; s2.show();
    cout << "\ns3="; s3.show();

    // Assignment using setter
    s3.setString(s1.getString()); // getString returns const char* address of string

    cout << "\ns3="; s3.show(); 

    // Concatenation
    s3.concat(s2); // s3 = s1 + s2

    cout << "\ns3="; s3.show();

    cout << endl;
    return 0;
}
