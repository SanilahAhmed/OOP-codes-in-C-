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
     cout<<"Ship No."<<serial<<" created!"<<endl;
}
~serialnum(){
    cout<<"Ship destroyed!"<<endl;
}
    int getserialnum() const{
    return serial;
    }
};
int serialnum::count = 0; 

class ship{
    serialnum snum;
    int  latitude, longitude;

    public:
    ship(){
        cout<<"Ship constructor called!"<<endl;
    }
    void setship(int lo, int la ){
        latitude = la;
        longitude = lo;
    }
    void getship(){
        cout << "Enter your ship latitude (0 - 90): "<<endl;
        cin >> latitude;
        cout << "Enter your ship longitude (0 - 180): "<<endl;
        cin >> longitude;

    }
    void showship(){
        cout<<"Your Ship No is : " <<snum.getserialnum()<<endl;
        cout<<"Your Ship's Location's Longitude = "<< longitude << " & Latitude = "<< latitude<< endl;
    }
};
int main(){
    ship s1 , s2, s3;

    cout<<"\n1st Ship's Location & SerialNumbers : "<<endl;
    s1.getship();
    s1.showship();

    cout<<"\n2nd Ship's Location & SerialNumbers : "<<endl;
    s2.getship();
    s2.showship();

    cout<<"\n3rd Ship's Location & SerialNumbers : "<<endl;
    s3.getship();
    s3.showship();

}