//
//  hand.h
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#ifndef Blackjack_Game_hand_h
#define Blackjack_Game_hand_h

#include <vector>
#include "card.h"

class Hand
{
public:
  Hand();
  virtual ~Hand();
  
  void AddCard(const Card& card);
  bool RemCard(const Card& card);
  void Clear();
  int GetNumCards() const;
  
  const std::vector<Card>& GetCards() const;
  virtual int GetScore() const;
  
  virtual void Print() const;
  
  //compareCards, printHand, GetHand
  
protected:
  std::vector<Card> m_cards;
};

#endif
