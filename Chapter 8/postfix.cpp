#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count;

public:
    Counter() { count = 0; }       // default constructor
    Counter(int c) { count = c; }  // parameterized constructor

    unsigned int get_count() { return count; } //count =4

    // prefix ++
    Counter operator++() {
        ++count;
        return Counter(count); //count = 5
    }

    // postfix ++
    Counter operator++(int) {
        Counter old(count);  // count = 4
        count++;             // count = 5
        return old;          // old.count = 4
    }
};

int main() {
    Counter c;
    cout << "start c=" << c.get_count() << "\n"; // start c=4

    Counter a = c++; // a=4, c=5
    cout << "after c++: c=" << c.get_count() << ", a=" << a.get_count() << "\n";

    Counter b = ++c; //b=6, c=6
    cout << "after ++c: c=" << c.get_count() << ", b=" << b.get_count() << "\n";

    return 0;
}
