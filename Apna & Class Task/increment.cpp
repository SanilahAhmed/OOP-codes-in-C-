#include <iostream>
#include <iomanip>
using namespace std;

class time {
private:
    int hrs, mins, secs;

    void normalize() {
        if (secs >= 60) { secs -= 60; mins++; }
        if (secs < 0) { secs += 60; mins--; }
        if (mins >= 60) { mins -= 60; hrs++; }
        if (mins < 0) { mins += 60; hrs--; }
        if (hrs < 0) { hrs = mins = secs = 0; }
    }

public:
    time() : hrs(0), mins(0), secs(0) {}
    time(int h, int m, int s) : hrs(h), mins(m), secs(s) {}

    void display() {
        cout << setfill('0') << setw(2) << hrs << ":"
             << setfill('0') << setw(2) << mins << ":"
             << setfill('0') << setw(2) << secs;
    }

    time operator+(time t2) {
        int s = secs + t2.secs;
        int m = mins + t2.mins;
        int h = hrs + t2.hrs;
        if (s > 59) { s -= 60; m++; }
        if (m > 59) { m -= 60; h++; }
        return time(h, m, s);
    }

    time& operator++() {
        secs++;
        normalize();
        return *this;
    }

    time operator++(int) {
        time temp = *this;
        secs++;
        normalize();
        return temp;
    }

    time& operator--() {
        secs--;
        normalize();
        return *this;
    }

    time operator--(int) {
        time temp = *this;
        secs--;
        normalize();
        return temp;
    }
};

int main() {
    time time1(5, 59, 59);
    time time2(4, 30, 30);
    time time3;

    time3 = time1 + time2;
    cout << "\ntime3 = "; time3.display();

    cout << "\n\nPrefix ++time3: ";
    ++time3; time3.display();

    cout << "\nPostfix time3++: ";
    time temp1 = time3++; temp1.display();
    cout << " (before), now time3 = "; time3.display();

    cout << "\n\nPrefix --time3: ";
    --time3; time3.display();

    cout << "\nPostfix time3--: ";
    time temp2 = time3--; temp2.display();
    cout << " (before), now time3 = "; time3.display();

    cout << endl;
    return 0;
}
