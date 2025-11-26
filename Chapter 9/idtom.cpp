#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string ldtoms(long double num) {
    // Using ostringstream to format with 2 decimal places
    ostringstream out;
    out << fixed << setprecision(2) << num; 
    return out.str(); // return as a string
}

int main() {
    long double amount;
    cout << "Enter money amount: ";
    cin >> amount;

    string money = ldtoms(amount);
    cout << "Money format: " << money << endl;

    return 0;
}
