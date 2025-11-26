#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

    // Destructor
    ~Time() {
        // nothing needed
    }

    // Setter
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

    // Getter
    void getTime(int &h, int &m, int &s) const {
        h = hours;
        m = minutes;
        s = seconds;
    }

    // Display
    void display() const {
        cout << hours << ":" << minutes << ":" << seconds;
    }

    // Normalize time (convert 60s → 1m, 60m → 1h)
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60; // minutes = minutes + (seconds / 60)
            seconds %= 60;           // seconds = seconds % 60
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

    // Overloaded + operator
    Time operator+(const Time& t) const {
        Time temp;
        
        temp.hours   = hours   + t.hours; // add hours of both times objects
        temp.minutes = minutes + t.minutes;
        temp.seconds = seconds + t.seconds;

        temp.normalize();
        
        return temp;
    }
};

int main() {
    Time t1(2, 45, 50);   // 2:45:50
    Time t2(1, 30, 20);   // 1:30:20

    Time t3 = t1 + t2;    // add using + operator now t3 should be 4:16:10

    cout << "Time 1: ";
    t1.display();
    cout << endl;

    cout << "Time 2: ";
    t2.display();
    cout << endl;

    cout << "Time 3 (t1 + t2): ";
    t3.display();
    cout << endl;

    return 0;
}
