#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card {
private:
    int number;   // 0–51 (represents a card)

public:
    Card() {
        number = 0;
    }

    Card(int n) {
        number = n;
    }

    void show() {
        const char* suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        const char* ranks[13] = {
            "A", "2", "3", "4", "5", "6", "7",
            "8", "9", "10", "J", "Q", "K"
        };

        int suit = number / 13; //(0 se 12 → Hearts)
        int rank = number % 13; //(0 se 12 → A se K)

        cout << ranks[rank] << " of " << suits[suit];
    }
};

class Deck {
private:
    Card cards[52];

public:
    // Constructor – fills deck with 52 cards
    Deck() {
        for (int i = 0; i < 52; i++)
            cards[i] = Card(i);
    }

    // Shuffle the deck
    void shuffle() {
        srand(time(0)); // seed random number generator
        for (int i = 0; i < 52; i++) {
            int r = rand() % 52; // random index from 0 to 51
            Card temp = cards[i]; // swap cards[i] and cards[r]
            cards[i] = cards[r];
            cards[r] = temp;
        }
    }

    // Deal 4 players of 13 cards each
    void deal(Card hand[4][13]) {
        int k = 0;

        for (int p = 0; p < 4; p++) {
            for (int c = 0; c < 13; c++) {
                hand[p][c] = cards[k++]; //deck ka first card player 1 ko, second to player 2 basically card distribution
            }
        }
    }

    // Destructor
    ~Deck() {
        // nothing needed
    }
};

int main() {
    Deck deck;
    deck.shuffle();

    Card hand[4][13];

    deck.deal(hand);

    // Display hands
    for (int p = 0; p < 4; p++) {
        cout << "\nPlayer " << p + 1 << "'s Hand:\n";
        for (int c = 0; c < 13; c++) {
            hand[p][c].show();
            cout << endl;
        }
    }

    return 0;
}
