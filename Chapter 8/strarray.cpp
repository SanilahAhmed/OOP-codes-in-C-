#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class String
{
private:
    enum { SZ = 80 };   // Maximum string size
    char str[SZ];       // String store

public:
    // Default constructor
    String() 
    { 
        strcpy(str, "");   // Empty string initialize
    }

    // Parameterized constructor
    String(char s[]) 
    { 
        strcpy(str, s);    // Argument copy
    }

    // Copy constructor
    String(const String &s) 
    { 
        strcpy(str, s.str); // Copy existing object
    }

    // Display function
    void display() const 
    { 
        cout << str;        // Print string
    }

    // Getter
    const char* getStr() const // char pointer to const
    { 
        return str; 
    }

    // Setter
    void setStr(const char s[]) 
    { 
        strcpy(str, s); 
    }

    // Overloaded += operator
    String& operator+=(const String &ss)
    {
        // Overflow check
        if (strlen(str) + strlen(ss.str) < SZ)
        {
            strcat(str, ss.str);  // Append argument string to current
        }
        else
        {
            cout << "\nString overflow"; 
            exit(1);               // Program terminate if overflow
        }

        return *this;              // Return current object reference
    }
};

int main()
{
    String s1 = "Merry Christmas! "; // Constructor with argument
    String s2 = "Happy New Year!";   // Constructor with argument
    String s3;                        // Empty string

    s1.display(); // Display s1
    s2.display(); // Display s2
    s3.display(); // Display s3 (empty)

    s3 = s1 += s2; // s2 append ho gaya s1 me, result s3 me bhi assign

    s3.display(); // Display concatenated result
    cout << endl;

    return 0;
}