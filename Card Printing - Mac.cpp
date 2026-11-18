// macOS Terminal example for coloring and printing 502 playing cards.
#include <iostream> // Provides cout and cin for console input/output.
using namespace std;

// Convert the Windows-style project color number (0-15) to an ANSI code.
int ansiColor(int color, bool background) {
    // ANSI foreground codes use a different color order than Windows codes.
    const int foregroundCodes[16] = {
        30, 34, 32, 36, 31, 35, 33, 37,
        90, 94, 92, 96, 91, 95, 93, 97
    };

    // Background codes are 10 higher than their matching foreground codes.
    return foregroundCodes[color] + (background ? 10 : 0);
}

// Set text and background colors with an ANSI escape sequence.
void setColor(int textColor, int bgColor) {
    cout << "\033[" << ansiColor(textColor, false) << ";"
         << ansiColor(bgColor, true) << "m";
}

// Clear the Terminal and move the cursor to the top-left corner.
void clearScreen() {
    cout << "\033[2J\033[H" << flush;
}

// Shared color values match the Windows example and the project handout.
const int BLACK = 0;
const int WHITE = 7;
const int LIGHT_GREEN = 10; // Used for a card that can be played.
const int LIGHT_RED = 12;
const int BRIGHT_WHITE = 15;

// Suit numbers match the 502 project card encoding.
const int SPADES = 0;
const int HEARTS = 1;
const int DIAMONDS = 2;
const int CLUBS = 3;

// Each card is an integer from 0 to 51: suit * 13 + value.
int getSuit(int card) {
    return card / 13;
}

// Values run from 0 (Ace) to 12 (King); 9 represents a 10.
int getValue(int card) {
    return card % 13;
}

// Print the card's visible rank instead of its internal number.
void printValue(int card) {
    int value = getValue(card);

    if (value == 0)
        cout << "A"; // Value 0 represents an Ace.
    else if (value == 10)
        cout << "J"; // Value 10 represents a Jack.
    else if (value == 11)
        cout << "Q"; // Value 11 represents a Queen.
    else if (value == 12)
        cout << "K"; // Value 12 represents a King.
    else
        cout << value + 1; // Number cards are stored one lower than their face.
}

// Print the suit as a Unicode symbol supported by macOS Terminal.
void printSuit(int card) {
    int suit = getSuit(card);

    if (suit == SPADES)
        cout << "♠";
    else if (suit == HEARTS)
        cout << "♥";
    else if (suit == DIAMONDS)
        cout << "♦";
    else
        cout << "♣"; // The remaining suit is Clubs.
}

// Keep card borders aligned; 10 already occupies two characters.
void printPadding(int card) {
    if (getValue(card) == 9)
        cout << " |";
    else
        cout << "  |";
}

// Print one card. borderColor is used for the border and rank:
// BRIGHT_WHITE for a normal card, LIGHT_GREEN for a card that can be played.
// Hearts and diamonds symbols are always red.
void printCard(int card, int borderColor) {
    setColor(borderColor, BLACK); // Use the border color for the border and rank.
    cout << " +-----+\n | ";

    printValue(card); // Print A, 2-10, J, Q, or K.

    // Switch to red before printing a heart or diamond symbol.
    if (getSuit(card) == HEARTS || getSuit(card) == DIAMONDS)
        setColor(LIGHT_RED, BLACK);
    printSuit(card);

    // Restore the border color, close the card, then reset the Terminal color.
    setColor(borderColor, BLACK);
    printPadding(card);
    cout << "\n +-----+\n";
    setColor(WHITE, BLACK);
}

// Demonstrate how to encode and print three example cards.
int main() {
    // suit * 13 + value: Clubs is suit 3, and a 9 has value 8.
    int nineOfClubs = CLUBS * 13 + 8;

    // Hearts is suit 1, and a 10 has value 9.
    int tenOfHearts = HEARTS * 13 + 9;

    // Hearts is suit 1, and a Jack has value 10 (card number 23).
    int jackOfHearts = HEARTS * 13 + 10;

    cout << "Top of discard pile\n";
    printCard(nineOfClubs, BRIGHT_WHITE);
    cout << "\n";

    cout << "Red suit and two-character value\n";
    printCard(tenOfHearts, BRIGHT_WHITE);
    cout << "\n";

    // A Jack can be played on any card, so it is shown in green.
    cout << "Valid card that can be played (green)\n";
    printCard(jackOfHearts, LIGHT_GREEN);
    cout << "\nPress Enter to clear the screen...";

    cin.get(); // Wait until the user presses Enter.
    clearScreen();
    cout << "Screen cleared.\n";
    return 0; // End the example successfully.
}
