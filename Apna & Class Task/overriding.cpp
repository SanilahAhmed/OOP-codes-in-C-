#include <iostream>
#include <string>
using namespace std;

class rider {

public:
void show(){
    cout<<" rider class\n";
}
virtual void hello(){
    cout<<"hello from rider\n";
}

};

class deliever : public rider{
    public:
    void show(){
        cout<<" deliever class\n";
    }
    void hello(){
    cout<<"hello from deliever\n";
}
};

int main() {
   // rider r1;
    //r1.show();
    //r1.hello();

   deliever d1;
  d1.show();
  d1.hello();
    return 0;
}