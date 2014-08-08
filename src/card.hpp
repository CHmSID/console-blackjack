#ifndef CARD_HPP
#define CARD_HPP
#include <string>

using std::string;

class Card {

public:
    Card(int value, int suit);
    ~Card();

    int getCardId()const;       //the id of the card, can be 0-12 where 0 is ace
    char* getVerboseValue()const; //converts 0 to 'ace', 12 to 'king', etc
    int getPoints()const;
    char* getSuit()const;

private:
    int suit;
    int id;
};

#endif