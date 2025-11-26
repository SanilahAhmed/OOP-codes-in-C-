#include <iostream>
#include <string>
using namespace std;

class employee  {
private:
    int num;
    float compensation;

public:
employee()  {cout<<"Constructor called!"<< endl;}

~employee(){
    cout<<"Destructed!"<<endl;
}

void setnum (int n)  {num=n;}
int getnum()  {return num;}

void setcompensation ( float c)  { compensation=c;}
float getcompensation()  {return compensation;}

void inputEmployee() {
        int n; 
        float c;
        cout << "Enter Employee Number: ";
        cin >> n;
        cout << "Enter Compensation in dollars : ";
        cin >> c;
        setnum(n);
        setcompensation(c);
    }
    void showEmployee(){
        cout<<"Employee's Number is : "<< getnum() << endl;
         cout<<"Employee's Compensation in dollars is : "<< getcompensation() << endl;
    }

};

int main() {
    employee obj[3];
   
    
    for(int i=0; i<3; i++){

         cout << "Employee " << i+1 << endl;
         obj[i].inputEmployee();
    }
      
    cout<<"Employee's Detail"<< endl;

    for(int i=0; i<3; i++){

         obj[i].showEmployee();
    }
    return 0;
}