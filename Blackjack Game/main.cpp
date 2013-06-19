//
//  main.cpp
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#include <iostream>
#include "deck.h"
#include "card.h"
#include "blackjack.h"

using namespace std;

BJHand *handPlayer, *handDealer;

void printDealer()
{
  cout << "Dealer Card(s): " << endl;
  handDealer->Print();
  cout << "(Score: " << handDealer->GetScore() << ")" << endl;
  cout << endl;
}

void printPlayer()
{
  cout << "Player Card(s): " << endl;
  handPlayer->Print();
  cout << "(Score: " << handPlayer->GetScore() << ")" << endl;
  cout << endl;
}


int main(int argc, const char * argv[])
{
  Card card;
  Deck *deck = new Deck();
  handPlayer = new BJHand();
  handDealer = new BJHand();
  
  cout << "BlackJack Simple Demo" << endl;
  cout << "[ MALF - June 2012  ]" << endl << endl;
  
  
  while(deck->GetNumRemainingCards() > 0)
  {
    while(true)
    {
      cout << "------------------------------------" << endl;
      cout << "> Deal(d) or Exit(e) ?" << endl;
    
      char c = 0;
      cin >> c;
  
      if(c == 'd' || c == 'D')
        break;
      else if (c == 'e' || c == 'E')
      {
        cout << "Bye!" << endl;
        return 0;
      }
    }
    
    // Clear hands
    handDealer->Clear();
    handPlayer->Clear();
  
    // Deal Dealer first card
    card = deck->DealCard();
    handDealer->AddCard(card);
 
    // Player turn
    while (true)
    {
      if(deck->GetNumRemainingCards() == 0)
      {
        cout << "Out of cards!" << endl;
        return 0;
      }
    
      printDealer();

      // Deal Player a card
      const Card& card = deck->DealCard();
      handPlayer->AddCard(card);
      printPlayer();
    
      if(handPlayer->IsBusted())
      {
        cout << "Busted! Dealer Wins!" << endl;
        break;
      }
    
      cout << "------------------------------------" << endl;
      cout << "> Stand (s) or Hit(h) ?" << endl;
    
      char c = 0;
      cin >> c;
    
      if(c == 's' || c == 'S')
        break;
      else if(c == 'h' || c == 'H')
        continue;
    }
  
    if(!handPlayer->IsBusted())
    {
      // Dealer turn
      while (true) 
      {
        int score = handDealer->GetScore();
    
        if(score < 17)
        {
          card = deck->DealCard();
          handDealer->AddCard(card);
        }
        else
          break;
      }
  
      // Results:
      cout << endl<< "Game results:" << endl;
      printDealer();
      printPlayer();
  
      if(handDealer->IsBusted())
        cout << "Dealer busted! Player wins!!" << endl;
      else if(handPlayer->GetScore() > handDealer->GetScore())
        cout << "Player wins!" << endl;
      else if(handPlayer->GetScore() < handDealer->GetScore())
        cout << "Dealer wins!" << endl;
      else
        cout << "Tie!" << endl;
    }
  }
  return 0;
}
