#include "card.hpp"
#include <sstream>

using std::string;
using std::stringstream;

Card::Card(int id, int suit){

    this->id = id;
    this->suit = suit;
}

Card::~Card(){

}

int Card::getCardId()const{

    return id;
}

char* Card::getVerboseValue()const{

    if(id == 0)
        return (char *)"Ace";
    else if(id > 0 && id < 10){
        stringstream out;
        out << (id + 1);
        string a = out.str();
        return &a[0];
    }
    else if(id == 10)
        return (char *)"Jack";
    else if(id == 11)
        return (char *)"Queen";
    else if(id == 12)
        return (char *)"King";
    else
        return (char *)"ERROR";
}

char* Card::getSuit()const{

    switch(suit) {
        case 0:
            return (char *)"spades";
            break;

        case 1:
            return (char *)"hearts";
            break;

        case 2:
            return (char *)"diamonds";
            break;

        case 3:
            return (char *)"clubs";
            break;

        default:
            return (char *)"ERROR";
            break;
    }
}