//
//  deck.cpp
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "deck.h"
#include <cassert>
#include <algorithm>

using namespace std;

Deck::Deck()
: m_deltIndex(0)
{
  for (int i=0; i<CARD_RANGE; i++)
    m_cards[i] = Card(i);
  Shuffle();
}

Deck::~Deck()
{
}

const Card& Deck::DealCard() 
{
  assert(m_deltIndex >= 0 && m_deltIndex<CARD_RANGE);
  return m_cards[m_deltIndex++];
}

void Deck::Shuffle()
{
  srand(time(0));
  
  for (int i=0; i<CARD_RANGE-1; i++) 
  {
    int randNum = i + (rand() % (CARD_RANGE-i));
    swap(m_cards[i], m_cards[randNum]);
  }
  m_deltIndex = 0;
}

int Deck::GetNumCards() const
{
  return CARD_RANGE;
}

int Deck::GetNumRemainingCards() const
{
  return CARD_RANGE - m_deltIndex;
}
