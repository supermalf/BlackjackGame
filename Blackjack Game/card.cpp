//
//  card.cpp
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#include "card.h"

#include <iostream>

using namespace std;


std::ostream& operator<<(std::ostream& o, const Card& c) {
    o << " " << c.GetRankName() << " of " << c.GetSuitName() << std::endl;
    return o;
}


const string Card::m_rankNames[] =  {
  "A", "2", "3", "4", "5", "6", "7", 
  "8", "9", "10", "J", "Q", "K"
};

const string Card::m_suitNames[] = {
  "Spades", "Hearts", "Clubs", "Diamonds"
};

Card::Card()
: m_available(true)
, m_value(0)
{
}

Card::Card(int value)
: m_available(true)
, m_value(value)
{
}

Card::~Card()
{
}

int Card::GetRank() const
{
  return m_value % CARD_NFACES;
}

int Card::GetSuit() const
{
  return m_value / CARD_NFACES;
}

string Card::GetRankName() const
{
  return m_rankNames[GetRank()];
}

string Card::GetSuitName() const
{
  return m_suitNames[GetSuit()];
}

bool Card::IsAvailable() const
{
  return m_available;
}

void Card::SetAvailable(bool state)
{
  m_available = state;
}

void Card::Print() const
{
  cout << " " << GetRankName() << " of " << GetSuitName() << endl;
}
