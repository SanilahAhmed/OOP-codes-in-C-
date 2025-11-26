#include <iostream>
using namespace std;

const int MAX = 10;

class queue {
private:
    int arr[MAX];
    int head;
    int tail;

public:
    queue() {
        head = 0;
        tail = -1;
    }

    ~queue() {
        // nothing special needed
    }

    void put(int x) {
        if (tail == MAX - 1) // -1 == 9? no then, tail ++ otherwise:
            tail = -1; // tail ko wapas -1 krdo

        tail++; // tail =0 hogai
        arr[tail] = x; // now put arr[0]= 11 arr[1]=22 arr[2]=33 arr[3]=44 now tail =3;
    }

    int get() {
        int temp = arr[head]; // temp = arr[0] removed 11 then move head to next
        head++; // head =1 head  =2

        if (head == MAX) // head ==10?
            head = 0;

        return temp; // removed 11 then removed 22
    }

    void show() {
        cout << "Queue items: ";
        int i = head; // head =2 tail =3 then new items added tail =5

        while (true) {
            cout << arr[i] << " ";
            if (i == tail)
                break;

            i++;
            if (i == MAX)
                i = 0;
        }

        cout << endl;
    }
};

int main() {
    queue q;

    q.put(11);
    q.put(22);
    q.put(33);
    q.put(44);

    q.show();

    cout << "Removed: " << q.get() << endl;
    cout << "Removed: " << q.get() << endl;

    q.show();

    q.put(55);
    q.put(66);

    q.show();

    return 0;
}

