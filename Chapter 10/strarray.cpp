#include <iostream>
using namespace std;

class StringArray {
private:
    char* days[7];     // pointers to C-style strings

public:
    // Constructor
    StringArray() {
        days[0] = (char*)"Sunday";
        days[1] = (char*)"Monday";
        days[2] = (char*)"Tuesday";
        days[3] = (char*)"Wednesday";
        days[4] = (char*)"Thursday";
        days[5] = (char*)"Friday";
        days[6] = (char*)"Saturday";
    }

    // Destructor
    ~StringArray() {
        // Nothing to delete because strings are constant literals
    }

    // Getter
    char* getDay(int index) {
        return *(days + index);// days{index}
    }

    // Setter (allows changing a day string)
    void setDay(int index, char* newDay) {
        *(days + index) = newDay;
    }

    // Display
    void display() {
        cout << "Days of Week:\n";
        for (int i = 0; i < 7; i++) {
            cout << *(days + i) << endl;
        }
    }

    // Compare two C-strings alphabetically
    int compare(char* s1, char* s2) {  // if m < t return -1 from mon and tue
        while (*s1 != '\0' && *s2 != '\0') {
            if (*s1 < *s2) return -1;  // 1st string is smaller
            if (*s1 > *s2) return 1;   // 2nd string is smaller
            s1++;
            s2++;
        }
        if (*s1 == '\0' && *s2 == '\0') return 0;
        if (*s1 == '\0') return -1; // 1st string is smaller anfd ended
        return 1;               // 2nd string is smaller and ended
    }

    // Sort pointers alphabetically
    void sortDays() {
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 7; j++) {
                if (compare(*(days + i), *(days + j)) > 0) {
                    char* temp = *(days + i);
                    *(days + i) = *(days + j);
                    *(days + j) = temp;
                }
            }
        }
    }
};

int main() {
    StringArray obj;

    cout << "\nBefore Sorting:\n";
    obj.display();

    obj.sortDays();

    cout << "\nAfter Sorting:\n";
    obj.display();

    return 0;
}
