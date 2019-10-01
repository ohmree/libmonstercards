#include "player.hpp"
#include "card.hpp"
#include <map>

Player::Player(unsigned health, unsigned mana, std::vector<Card::RefType> deck)
    : _health(health), _mana(mana), _deck(deck){};
