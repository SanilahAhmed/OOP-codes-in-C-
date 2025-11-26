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
        if (seconds < 0) {
            int m = (abs(seconds) + 59) / 60;
            minutes -= m;
            seconds += m * 60;
        }
        if (minutes < 0) {
            int h = (abs(minutes) + 59) / 60;
            hours -= h;
            minutes += h * 60;
        }
        if (hours < 0) hours = 0;
    }

    // Prefix ++
    Time operator++() { seconds++; normalize(); return *this; }

    // Postfix ++
    Time operator++(int) { Time temp = *this; seconds++; normalize(); return temp; }

    // Prefix --
    Time operator--() { seconds--; normalize(); return *this; }

    // Postfix --
    Time operator--(int) { Time temp = *this; seconds--; normalize(); return temp; }

    // Overloaded - operator (subtract two Time objects)
    Time operator-(const Time& t) const {
        int total1 = hours*3600 + minutes*60 + seconds;  // To get total seconds
        int total2 = t.hours*3600 + t.minutes*60 + t.seconds;
        int diff = total1 - total2; // difference in seconds
        if (diff < 0) diff = 0;  

        int h = diff / 3600; //hours
        int m = (diff % 3600) / 60; //minutes
        int s = diff % 60; //seconds
        return Time(h, m, s);
    }

    // Overloaded * operator (multiply Time by a float)
    Time operator*(float n) const {
        int total = hours*3600 + minutes*60 + seconds; // total seconds
        int result = static_cast<int>(total * n); //total ko float n se multiply karakr int mein covert kiya hai

        int h = result / 3600;
        int m = (result % 3600) / 60;
        int s = result % 60;
        return Time(h, m, s);
    }
};

int main() {
    Time t1(2, 30, 15);
    Time t2(1, 45, 50);

    Time t3 = t1 - t2;   // subtract
    cout << "t1 - t2 = ";
    t3.display();
    cout << endl;

    Time t4 = t2 * 2.5;  // multiply
    cout << "t2 * 2.5 = ";
    t4.display();
    cout << endl;

    return 0;
}
