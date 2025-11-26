#include <iostream>
#include <string>
using namespace std;

class date {
private:
    int month , day , year;
    
public:
    void getdate(){
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;

    }
    void showdate() {
        cout<< month << "/" << day << "/" << year << endl;
    }
        
};

int main() {
    date obj;
    obj.getdate();
    cout<<"You Entered:  ";
    obj.showdate();
    return 0;
}