//
//  blackjack.h
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

/*
 The objective and main goal when playing blackjack is to get as close to 21 as you possibly can, 
 or match 21, with any amount of cards. 
 
 The value of each card is as follows:
  - The value of card numbers 2-10 represent their own numerical value Jacks, Queens, and Kings 
  are worth 10
  - Aces are 1 or 11, whichever you choose
 
 The first premise to understand when playing Blackjack is that your only competition is the 
 blackjack dealer. No matter how many virtual or real players are at your table, your only foe is 
 the Dealer. Bottom line, if you beat the blackjack dealer you win. If you tie the Dealer it is a 
 push and you retain your bet. The most common blackjack rule is that the dealer stands on all 17s. 
 In this case, the dealer must continue to take cards ("hit") until his total is 17 or greater. An 
 Ace in the dealer's hand is always counted as 11, if possible without the dealer going over 21. For 
 example, (Ace + 8) would be 19 and the dealer would stop drawing cards ("stand"). Also, (Ace + 6) 
 is 17 and again the dealer will stand. (Ace + 5) is only 16, so the dealer would hit. S/He will 
 continue to draw cards until the hand's value is 17 or more. For example, (Ace + 5 + 7) is only 13 
 so s/he hits again. (Ace + 5 + 7 + 5) makes 18 so s/he would stop ("stand") at that point.
 */

#ifndef Blackjack_Game_blackjack_h
#define Blackjack_Game_blackjack_h

#include <cassert>
#include "hand.h"

class Card;

class BJHand : public Hand
{
public:
  BJHand(){}
  ~BJHand(){}
  
  int GetScore() const
  {
    int score = 0;
    int hasAce = false;
    
    // Getting total without ACE
    for (int i=0; i<m_cards.size(); i++)
    {
      int rank = m_cards[i].GetRank();
      
      if ((rank >= Card::RANK_TWO) && (rank <= Card::RANK_TEN))
        score += rank+1;
      else if((rank >= Card::RANK_JACK) && (rank <= Card::RANK_KING))
        score += 10;
      else if((rank == Card::RANK_ACE) && !hasAce) 
        hasAce = true;
    }
    
    // Adding Aces value
    if(hasAce)
    {
      for (int i=0; i<m_cards.size(); i++)
      {
        int rank = m_cards[i].GetRank();
        
        if(rank == Card::RANK_ACE)
        {
          if(score+11 <= 21)
            score += 11;
          else
            score += 1;
        }
      }
    }
    return score;
  }
  
  bool IsBusted() const
  {
    return GetScore()>21;
  }
  
  bool Is21() const
  {
    return GetScore()==21;
  }
  
};


#endif
