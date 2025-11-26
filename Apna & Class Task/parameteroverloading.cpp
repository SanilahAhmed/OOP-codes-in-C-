#include <iostream>
#include <string>
using namespace std;

class student {

public:
string name;

student() {
    cout<<"Non parameterized constructor\n";
}
student(string n) {
    name=n;
    cout<<"parameterized constructor\n";
}

};

int main() {
   student s1("Sanilah"); // parameterized 
    // student s1; // non parameterized
    return 0;
}