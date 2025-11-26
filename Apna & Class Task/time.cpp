#include <iostream>
using namespace std;
 class Time{
    private:

    int hr;
    int min;
    int sec;

    public:
    Time(){
      cout<<"hi, i am consructor.\n";      //non parameterized constructor
 
   } 

   Time(int hour, int minute, int second){
      hr = hour;
      min = minute;                          // parameterized constructor  
      sec = second;
   }

     void sethours(int h)  {hr =h;}
     void setminutes(int m)  {min =m;}
     void setseconds(int s)  {sec =s;}


     int gethours( )    {return hr;}
     int getminutes( )  {return min;}
     int getseconds( )  {return sec;}

 };
 
 int main (){
    Time obj; // parameterized Time obj("11","28","00");  // constructor call
    obj.sethours(11);
    obj.setminutes(28);
    obj.setseconds(00);

    cout<<"your time is "<< obj.gethours()<<" : " <<obj.getminutes()<<" : "<<obj.getseconds()<< endl;

    return 0;
 }
