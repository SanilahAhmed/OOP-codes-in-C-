#include <iostream>
#include <string>
using namespace std;

class serialnum {
private:
    int serial;
    static int count;

public:
serialnum() {
    count++; 
    serial = count;
     cout<<"Object No."<<serial<<" created!"<<endl;
}
~serialnum(){
    cout<<"Object destroyed!"<<endl;
}

 void setserialnum(int s){
    serial=s;
 }
 int getserialnum() const{
    return serial;
}
void showserialnum(){
    cout<<"I am Object number: "<<serial<<endl;
}
};
int serialnum::count = 0;

int main() {
    serialnum obj1, obj2, obj3;
    obj1.showserialnum();
    obj2.showserialnum();
    obj3.showserialnum();
    return 0;
}