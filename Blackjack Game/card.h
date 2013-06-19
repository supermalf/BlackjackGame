//
//  card.h
//  Blackjack Game
//
//  Created by MALF on 20/6/12.
//

#ifndef Blackjack_Game_card_h
#define Blackjack_Game_card_h

#include <string>
#include <iostream>

static const int CARD_RANGE = 52;
static const int CARD_NSUITS = 4;
static const int CARD_NFACES = 13;

class Card
{
public:
  enum Rank { 
    RANK_ACE   = 0, 
    RANK_TWO   = 1, 
    RANK_THREE = 2, 
    RANK_FOUR  = 3, 
    RANK_FIVE  = 4, 
    RANK_SIX   = 5, 
    RANK_SEVEN = 6, 
    RANK_EIGHT = 7, 
    RANK_NINE  = 8, 
    RANK_TEN   = 9, 
    RANK_JACK  = 10, 
    RANK_QUEEN = 11, 
    RANK_KING  = 12
  };
  enum Suit { 
    SUIT_SPADES   = 0, 
    SUIT_HEARTS   = 1, 
    SUIT_CLUBS    = 2, 
    SUIT_DIAMONDS = 3 
  };  
  
  
  Card();
  explicit Card(int value);
  ~Card();
  
  int GetRank() const;
  int GetSuit() const;
  
  std::string GetRankName() const;
  std::string GetSuitName() const;
  
  bool IsAvailable() const;
  void SetAvailable(bool state);
  
  void Print() const;

private:
  bool m_available;
  int m_value;    //[1 .. 51]
  
  static const std::string m_rankNames[];
  static const std::string m_suitNames[];
};


std::ostream& operator<<(std::ostream& o, const Card& c);

#endif
