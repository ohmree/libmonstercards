#ifndef ANIMO__PLAYER_HPP_
#define ANIMO__PLAYER_HPP_

#include "card.hpp"
#include "rps.hpp"
#include <optional>
#include <vector>

class Player {
public:
  Player(int health = 10, unsigned int mana = 5);
  unsigned int mana();
  unsigned int mana(unsigned int new_mana);
  int health();
  int health(int new_health);

private:
  unsigned int _health;
  unsigned int _mana;
  // For now these seem out of this library's scope
  // Clients can implement deck, hand and draw pile
  // functionality easily and provide easier integration
  // with their interface
  // std::vector<Card::RefType> _deck;      // this is the player's complete
  // deck std::vector<Card::RefType> _hand; // self-explanatory
  // std::vector<Card::RefType> _draw_pile; // this is the deck minus the hand
};

#endif // ANIMO__PLAYER_HPP_
