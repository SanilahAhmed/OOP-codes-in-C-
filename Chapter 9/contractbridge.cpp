#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int DECK_SIZE = 52;
const int HAND_SIZE = 13;
const int PLAYERS = 4;

string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int main() {
    string deck[DECK_SIZE];

    // Step 1: Create deck (52 cards)
    int index = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            deck[index++] = ranks[r] + " of " + suits[s];
        }
    }

    // Step 2: Shuffle deck randomly
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; i++) {
        int randIndex = rand() % DECK_SIZE;
        swap(deck[i], deck[randIndex]);
    }

    // Step 3: Deal 13 cards to each of 4 players
    string hand[PLAYERS][HAND_SIZE];
    index = 0;
    for (int p = 0; p < PLAYERS; p++) {
        for (int c = 0; c < HAND_SIZE; c++) {
            hand[p][c] = deck[index++];
        }
    }

    // Step 4: Display hands
    for (int p = 0; p < PLAYERS; p++) {
        cout << "\n--- Player " << p + 1 << " ---\n";
        for (int c = 0; c < HAND_SIZE; c++) {
            cout << hand[p][c] << endl;
        }
    }

    return 0;
}
