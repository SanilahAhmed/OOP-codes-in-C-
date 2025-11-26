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
    ~Time() { }

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

    // Normalize time
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (seconds < 0) {  // seconds = -30
            int m = (abs(seconds) + 59)/60; // m= (abs(-30)+59)/60 = 1   yahan 59 jo hai min borrow kiya hai
            minutes -= m;  // minutes = minutes -1 qk sec -30 tha already time - mein tha
            seconds += m*60; // seconds = -30 + 60 = 30
            // simple 1 minute borrow karo (ya jitne chahiye) 60  sec add kro
        }
        if (minutes < 0) {
            int h = (abs(minutes) + 59)/60;
            hours -= h;
            minutes += h*60;
        }
        if (hours < 0) hours = 0;
    }

    // Prefix ++
    Time operator++() { // sec = 59
        seconds++; // sec = 60 
        normalize(); // min =1 : sec =0
        return *this; // sec = 0
    }

    // Postfix ++
    Time operator++(int) {
        Time temp = *this; // temp = 59
        seconds++; // sec = 60
        normalize(); // sec = 0
        return temp; // temp = 59
    }

    // Prefix --
    Time operator--() { // sec = 61
        seconds--; // sec = 60
        normalize(); // sec = 0 min =1
        return *this; // sec = 0
    }

    // Postfix --
    Time operator--(int) {
        Time temp = *this; // sec = 61
        seconds--; // sec = 60
        normalize(); // sec = 0 min =1
        return temp; // temp = 61
    }
};

int main() {
    Time t1(1, 59, 59);

    cout << "Original time: ";
    t1.display();
    cout << endl;

    ++t1;  // Prefix increment
    cout << "After ++t1: ";
    t1.display();
    cout << endl;

    t1++;  // Postfix increment
    cout << "After t1++: ";
    t1.display();
    cout << endl;

    --t1;  // Prefix decrement
    cout << "After --t1: ";
    t1.display();
    cout << endl;

    t1--;  // Postfix decrement
    cout << "After t1--: ";
    t1.display();
    cout << endl;

    return 0;
}
