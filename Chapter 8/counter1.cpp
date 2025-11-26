#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count; // positive count
public:
    Counter() : count(0) { }       // constructor
    unsigned int get_count() {     // return count
        return count;
    }
    void operator++() {            // if x=5 and y = ++x; then x=6 and y=6
        ++count;                   // pehke x ki value increase hoi then y me assign hoi
    }
};

int main() {
    Counter c1, c2; 

    cout << "\nc1=" << c1.get_count(); // c1= 5
    cout << "\nc2=" << c2.get_count(); // c2= 6

    ++c1; // increment c1 = 6
    ++c2; // increment c2 = 7
    ++c2; // increment c2 again = 8

    cout << "\nc1=" << c1.get_count(); // c1=6
    cout << "\nc2=" << c2.get_count() << endl; // c2=8

    return 0;
}