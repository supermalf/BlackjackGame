//
//  deck.h
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#ifndef Blackjack_Game_deck_h
#define Blackjack_Game_deck_h

#include "card.h"

class Deck
{
public:
  Deck();
  ~Deck();
  
  const Card& DealCard();
  void Shuffle();
  int GetNumCards() const;
  int GetNumRemainingCards() const;
  
  //DealHand
  
  
private:
  Card m_cards[CARD_RANGE]; // all cards delt or not
  int m_deltIndex;          // marks the first undelt card
};

#endif
