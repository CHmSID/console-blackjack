#ifndef CARD_HPP
#define CARD_HPP
#include <string>

using std::string;

class Card {

public:
    Card(int value, int suit);
    ~Card();

    int getCardValue();       //the id of the card, can be 0-12 where 0 is ace
    string getVerboseValue(); //converts 0 to 'ace', 12 to 'king', etc
    string getSuit();

private:
    int suit;
    int value;
};

#endif