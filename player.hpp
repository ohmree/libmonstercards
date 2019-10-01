#ifndef ANIMO__PLAYER_HPP_
#define ANIMO__PLAYER_HPP_

#include "card.hpp"
#include "rps.hpp"
#include <optional>
#include <vector>

class Player {
public:
  Player(unsigned health = 10, unsigned mana = 5,
         std::vector<Card::RefType> deck = std::vector<Card::RefType>());

private:
  unsigned _health;
  unsigned _mana;
  std::vector<Card::RefType> _deck;      // this is the player's complete deck
  std::vector<Card::RefType> _hand;      // self-explanatory
  std::vector<Card::RefType> _draw_pile; // this is the deck minus the hand
};

#endif // ANIMO__PLAYER_HPP_
