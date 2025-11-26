#include <iostream>
#include <string>
using namespace std;

class print {

public:
void show(int x){
    cout<<"x hold : "<< x << endl;
}
void show(char ch){
    cout<<"ch hold : "<< ch << endl;
}


};

int main() {
    print p1;
    p1.show(3);

    return 0;
}