#include <iostream>
using namespace std;

class MyString {
private:
    char str[50];

public:
    MyString(const char s[] = "") { // jb khali chorna ho to ""
        int i;
        for (i = 0; s[i] != '\0'; i++)
            str[i] = s[i]; // copy manually
        str[i] = '\0';
    }

    ~MyString() {}

    void setStr(const char s[]) {
        int i;
        for (i = 0; s[i] != '\0'; i++)
            str[i] = s[i];
        str[i] = '\0';
    }

    char* getStr() {
        return str;
    }

    void toUpper() {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    MyString s("hello world");
    s.toUpper();
    s.display();
}
