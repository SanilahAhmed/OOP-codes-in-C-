#include <iostream>
using namespace std;

const int MAX = 5; // max size of queue

class queue {
private:
    int q[MAX];
    int head, tail;

public:
    queue() { head = 0; tail = -1; }

    // Add item to queue
    void put(int val) {
        if ((tail + 1) % MAX == head && tail != -1) {
            cout << "Queue is full!\n";
            return;
        }

        tail = (tail + 1) % MAX;
        q[tail] = val;
        cout << val << " added to queue.\n";
    }

    // Remove item from queue
    int get() {
        if (head == (tail + 1) % MAX && tail == -1) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int val = q[head];
        if (head == tail) {
            // Reset when last element removed
            head = 0;
            tail = -1;
        } else {
            head = (head + 1) % MAX;
        }

        return val;
    }

    // Display queue contents
    void display() {
        if (tail == -1) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue contents: ";
        int i = head;
        while (true) {
            cout << q[i] << " ";
            if (i == tail) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    queue q1;

    q1.put(10);
    q1.put(20);
    q1.put(30);

    q1.display();

    cout << "Removed: " << q1.get() << endl;
    q1.display();

    q1.put(40);
    q1.put(50);
    q1.display();

    return 0;
}
