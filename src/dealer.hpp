#ifndef DEALER_HPP
#define DEALER_HPP
#include "player.hpp"
#include "deck.hpp"

class Dealer: public Player{

public:
    void revealCard()const;  //reveals the first card in hand
    void fillHand(Deck& deck);    //takes cards until points over 17
};

#endif