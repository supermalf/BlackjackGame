//
//  hand.cpp
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#include "hand.h"
#include "card.h"

using namespace std;

Hand::Hand()
{
}

Hand::~Hand()
{
  m_cards.clear();
}

void Hand::AddCard(const Card& card)
{
  m_cards.push_back(card);
  
  //std::sort(hand.begin(),hand.end(),CardCompare);
}

bool Hand::RemCard(const Card& card)
{
  int cRank = card.GetRank();
  int cSuit = card.GetSuit();
  
  for (vector<Card>::iterator it = m_cards.begin(); it != m_cards.end(); ++it)
  {
    if((it->GetRank() == cRank) &&
       (it->GetSuit() == cSuit))
    {
      m_cards.erase(it);
      return true;
    }
  }
  return false;
}

void Hand::Clear()
{
  m_cards.clear();
}

int Hand::GetScore() const
{
  int score=0;
  
  for (vector<Card>::const_iterator it = m_cards.begin(); it != m_cards.end(); ++it)
        score += it->GetRank();
  return score;
}

int Hand::GetNumCards() const
{
  return m_cards.size();
}

const std::vector<Card>& Hand::GetCards() const
{
  return m_cards;
}

void Hand::Print() const
{
  Card card;
  
  for (vector<Card>::const_iterator it=m_cards.begin(); it!=m_cards.end(); ++it)
    it->Print();
}

