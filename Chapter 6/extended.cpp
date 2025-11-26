#include <iostream>
#include <string>
using namespace std;

enum etype {labour, secretary, manager, accountant,executive,researcher };

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


class employee  {
private:
    etype type;
    date hiredate;       // "date"hiredate as an object
    float compensation;
    
public :

 employee() {
        type = labour;        // default type
        compensation = 0.0;   // default compensation
        cout << "Employee object created." << endl;
    }

    // Destructor
    ~employee() {
        cout << "Employee object destroyed." << endl;
    }

    
void setcompensation ( float c)  { compensation=c;}
float getcompensation()  {return compensation;}


void inputEmployee() {
       
        float c;
        cout << "Enter Compensation in dollars : ";
        cin >> c;
        setcompensation(c);  
        cout << "Enter date when hired: "<< endl;
        hiredate.getdate();
        cout<<endl;
        char ch;
        cout << "Enter employee type (first letter only)\n"
             << "labour, secretary, manager, accountant, executive, researcher : ";
        cin >> ch;

        switch(ch){
            case 'l': type = labour; break;
            case 's': type = secretary; break;
            case 'm': type = manager; break;
            case 'a': type = accountant; break;
            case 'e': type = executive; break;
            case 'r': type = researcher; break;
           
        }
    }

    void showEmployee(){
        cout<<"Employee type is : "<<endl;
         switch(type){
            case labour: cout << "Labour"<<endl; break;
            case secretary: cout << "Secretary"<<endl; break;
            case manager: cout << "Manager"<<endl; break;
            case accountant: cout << "Accountant"<<endl; break;
            case executive: cout << "Executive"<<endl; break;
            case researcher: cout << "Researcher"<<endl; break;

            cout<<endl;
         }
         
         cout<<"Employee's Compensation in dollars is : "<< getcompensation() << endl;
         cout<<"Date of being hired : "<<endl;
         hiredate.showdate();
         
    }

};

int main() {
    employee obj[3];
    
    
    for(int i=0; i<3; i++){

         cout << "Employee " << i+1 << endl;
         obj[i].inputEmployee();
         cout<<endl;
    }
      
    cout<<"Employee's Detail"<< endl;

    for(int i=0; i<3; i++){

         cout << "Employee " << i+1 << endl;
         obj[i].showEmployee();
        
    }

    return 0;
}