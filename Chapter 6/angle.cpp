#include <iostream>
#include <string>
using namespace std;

class angle {
private:
    int degree;
    float minutes;
    char direction;
public:
     angle(int d, float m, char ch){
        degree = d;
        minutes = m;
        direction = ch;
     }
     
     void setAngle(int d, float m, char ch) {
        degree = d;
        minutes = m;
        direction = ch;
    }

     void getangle(){
        cout<<"Enter degree for latitude(0 - 90) , longitude(0 - 180)"<<endl;
        cin>>degree;
        cout<<"Enter minutes "<<endl;
        cin>>minutes;
        cout<<"Enter your direction(N, S, E, W)"<<endl;
        cin>> direction;
     }
     void displayangle() const {
        cout<< degree <<"\xF8"<< minutes <<"'" << direction <<endl;

     }
};

int main() {
    angle a1(179,59.9,'E');
    cout<<"Your initialized angle is: "<<endl;
    a1.displayangle();

    int n;
    cout<<"Enter the number of angles you want"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Angle no . "<< i+1 << "is: "<<endl;
        angle userangle(0,0.0,'N');
        userangle.getangle();
        cout<<"Your angle is: ";
        userangle.displayangle();
    }
    return 0;
}