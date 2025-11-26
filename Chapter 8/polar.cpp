#include <iostream>
#include <cmath>
using namespace std;

class Polar {
private:
    double radius;
    double angle;  // in degrees

    // Convert degrees to radians
    double deg2rad(double deg) const {
        return deg * M_PI / 180.0; // 90 * pi/180 = pi/2
    }

    // Convert radians to degrees
    double rad2deg(double rad) const {
        return rad * 180.0 / M_PI;
    }

public:
    // Constructor
    Polar(double r = 0.0, double a = 0.0) {
        radius = r;
        angle = a;
    }

    // Display function
    void display() const {
        cout << "Radius: " << radius << ", Angle: " << angle << " degrees" << endl;
    }

    // Overloaded + operator
    Polar operator+(const Polar& p) const {
        // Convert both to rectangular
        double x1 = radius * cos(deg2rad(angle));
        double y1 = radius * sin(deg2rad(angle));

        double x2 = p.radius * cos(deg2rad(p.angle));
        double y2 = p.radius * sin(deg2rad(p.angle));

        // Add rectangular coordinates
        double x = x1 + x2;
        double y = y1 + y2;

        // Convert back to polar
        double r = sqrt(x*x + y*y);
        double a = rad2deg(atan2(y, x)); // atan2 handles the quadrant correctly

        return Polar(r, a);
    }
};

int main() {
    Polar p1(5, 30);   // radius 5, angle 30 degrees
    Polar p2(3, 60);   // radius 3, angle 60 degrees

    cout << "Polar 1: ";
    p1.display();

    cout << "Polar 2: ";
    p2.display();

    Polar p3 = p1 + p2;   // add polar points
    cout << "Result (p1 + p2): ";
    p3.display();

    return 0;
}
