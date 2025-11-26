#include <iostream>
using namespace std;

class FloatArray {
private:
    float* arr;
    int size;

public:
    FloatArray(int s) : size(s) {
        arr = new float[size];
    }

    ~FloatArray() {
        delete[] arr;
    }

    void setValue(int index, float value) {
        *(arr + index) = value;
    }

    float getValue(int index) {
        return *(arr + index);
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << *(arr + i) << " ";
        cout << endl;
    }

    float average() {
        float sum = 0;
        for (int i = 0; i < size; i++)
            sum += *(arr + i);
        return sum / size;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    FloatArray obj(n);

    for (int i = 0; i < n; i++) {
        float x;
        cout << "Enter value " << i + 1 << ": ";
        cin >> x;
        obj.setValue(i, x);
    }

    obj.display();
    cout << "Average = " << obj.average();
}
