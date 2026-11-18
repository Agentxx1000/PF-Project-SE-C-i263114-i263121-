#include<iostream>
using namespace std;

const int PLAYERS = 2; // the game always has 2 players
const int DECK_SIZE = 52; // cards in one deck
const int START_CARDS = 7; // cards dealt to each player
const int MAX_HAND = 52; // the most cards one hand can hold
const int LIMIT = 502; // 502 or more loses the game
const int MAX_SCORES = 10; // records kept in highscores.txt
const int SPADES = 0, HEARTS = 1, DIAMONDS = 2, CLUBS = 3; // suits
const int ACE = 0, TWO = 1, SEVEN = 6, EIGHT = 7, JACK = 10; // values
const int ACE_OF_SPADES = 0, SEVEN_OF_HEARTS = 19; // special cards
const int NO_DEMAND = -1; // no Jack demand is waiting
const int DRAW = 0; // 0 = draw / accept a penalty or skip
// Console colours (same numbers as the Card Printing example)
const int BLACK = 0, WHITE = 7, GREY = 8, LIGHT_GREEN = 10, LIGHT_RED = 12;
const int BLUE = 9, CYAN = 11, MAGENTA = 13, YELLOW = 14, BRIGHT_WHITE = 15;

//STUDENT 1

// Put the cards 0 to 51 into the deck
void createDeck(int deck[], int &deckSize);
// Mix the cards into a random order
void shuffleDeck(int deck[], int deckSize);
// Take the top card; refill from the discard pile if empty
int drawCard(int deck[], int &deckSize, int
discardPile[], int &discardSize);
// Return true if the card can be played now
bool isLegalCard(int card, int topCard, int demandSuit, int pendingDraw, bool pendingSkip);
// Update the waiting effects after a card is played
void applyCardEffect(int card, int chosenSuit,
int &pendingDraw, bool &pendingSkip, int &demandSuit);
// Return the penalty points of one card
int getCardPoints(int card);
// Pick a legal card (7♥ first, then the most points); return its position, or 0 to draw
int chooseComputerCard(int hand[], int handSize, int topCard, int demandSuit, int pendingDraw, bool pendingSkip);
// Return the suit the computer holds the most
int chooseComputerSuit(int hand[], int handSize);

//STUDENT 2

// Read a number between low and high (ask again if wrong)
int readChoice(int low, int high);
// Show the rules of the game
void showInstructions();
// Read the names and colours of both players
void setupPlayers(string names[], int colors[], bool isComputer[], bool vsComputer);
// Show the round number, totals and card counts
void showScoreboard(string names[], int colors[], int totals[], int handSize[], int roundNumber, int currentPlayer);
// Show the draw pile count, top card and waiting effects
void showTopCard(int topCard, int deckSize,
int pendingDraw, bool pendingSkip, int demandSuit);
// Print the hand side by side (green = can play, grey = cannot)
void printHand(int hand[], int handSize, bool legal[]);
// Read highscores.txt and show the top 10 
void showLeaderboard();
// Add a winner to highscores.txt (sorted, top 10 only)
void saveWinner(string winnerName, int winnerScore);

//COMMON 

// Read a number between low and high (ask
again if wrong)
int readChoice(int low, int high);
// Show the rules of the game
void showInstructions();
// Read the names and colours of both players
void setupPlayers(string names[], int colors[], bool isComputer[], bool vsComputer);
// Show the round number, totals and card counts
void showScoreboard(string names[], int colors[], int totals[], int handSize[], int roundNumber, int currentPlayer);
// Show the draw pile count, top card and waiting effects
void showTopCard(int topCard, int deckSize, int pendingDraw, bool pendingSkip, int demandSuit);
// Print the hand side by side (green = can play, grey = cannot)
void printHand(int hand[], int handSize, bool legal[]);
// Read highscores.txt and show the top 10
void showLeaderboard();
// Add a winner to highscores.txt (sorted, top 10 only)
void saveWinner(string winnerName, int winnerScore);

int main()
{
	
	return 0;
}