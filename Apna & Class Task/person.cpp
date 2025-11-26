#include <iostream>
using namespace std;

class person  {
public:
    string name ;
    int age;

    // Constructor
    person(string n, int a){
        name=n;
        age=a;
    }
};

class student : public person {
    private:
    int rollno;

    public:
    student(string n, int a, int r) :person(n,a){
        rollno=r;                                    // constructor
    }

    string getnames(){return name; }
    int getages(){return age; }
    int getrollnos(){return rollno; }

};

int main() {
    student obj("Sanilah",18,109);

    cout<<"your name is: "<< obj.getnames()<<endl;
    cout << "Your age is: " << obj.getages() << endl;
    cout << "Your roll number is: " << obj.getrollnos() << endl;

    return 0;
}