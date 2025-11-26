#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Constructor
    Distance() {
        feet = 0;
        inches = 0.0;
    }

    // Setter
    void setDist(int f, float in) {
        feet = f;
        inches = in;
    }

    // Getter (optional)
    void getDist(int &f, float &in) {
        f = feet;
        in = inches;
    }

    // Function to get input from user
    void getdata() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Add another distance to current object
    void add_dist(Distance d2) {
        feet += d2.feet;
        inches += d2.inches;

        if (inches >= 12.0) {
            feet += int(inches / 12);  // feet= 3 + (30/12) = 5
            inches = inches - int(inches / 12) * 12; //inches= 30 - (30/12) * 12 = 6
        }
    }

    // Divide a distance by an integer
    void div_dist(Distance d2, int divisor) {
        float fltfeet = d2.feet + d2.inches / 12.0;     // feet=10; inches/12 = 6/12 = 0.5; fltfeet= 10.5;
        fltfeet /= divisor;      //10.5 / 3 = 3.5 feet

        feet = int(fltfeet);          // feet = 3 because int(3.5) = 3;
        inches = (fltfeet - feet) * 12.0;  // inches = (3.5 - 3) * 12 = 0.5 * 12 = 6 inches
    }

    // Display distance
    void show() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Destructor
    ~Distance() {
        // Optional cleanup
    }
};

int main() {
    Distance dist[100];
    Distance total;   // for sum of all distances
    Distance average; // for average distance

    int n;

    cout << "How many distances (max 100)? ";
    cin >> n;

    cout << endl;

    // Input distances
    for (int i = 0; i < n; i++) {
        cout << "Distance " << i + 1 << endl;
        dist[i].getdata();
        total.add_dist(dist[i]);
        cout << endl;
    }

    // Compute average
    average.div_dist(total, n);

    // Display average
    cout << "Average distance = ";
    average.show();

    return 0;
}
