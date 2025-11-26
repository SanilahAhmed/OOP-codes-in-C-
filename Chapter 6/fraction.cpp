#include <iostream>
#include <string>
using namespace std;

class fraction {
private:
    int num, den,sum ;
    char ch;
public:

fraction(int n=0, int d=1){
    num=n;
    den=d;
    cout<<"Constructor called!"<<endl;
}

~fraction(){
    cout<<"destructor"<<endl;
}
void setfraction(int n, int d  ){
    num=n;
    den=d;
}
  int getfraction(){
    char slash;
    cout<<"Enter fraction in form (a/b)"<<endl;
    cin>>num >> slash >> den;
  }

  void showfraction(){
    cout<<"your fraction values are: "<<num<< " / " << den <<endl;

  }
  fraction addfraction(fraction& f2){
    int n =(num*f2.den)+(f2.num*den);
    int d =(den*f2.den);
    return fraction(n, d);
} 

};

int main() { int n;
    cout << "How many times do you want to add fractions? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Fraction Addition " << i + 1 << " :" << endl;

        fraction f1, f2, sum;

        cout << "Enter first fraction:"<<endl;
        f1.getfraction();

        cout << "Enter second fraction:"<<endl;
        f2.getfraction();

    
        sum = f1.addfraction(f2);

        cout << "Sum = ";
        sum.showfraction();
        cout << endl;
    }
    return 0;
}