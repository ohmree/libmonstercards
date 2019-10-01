#include "player.hpp"
#include "card.hpp"
#include <map>

Player::Player(int health, unsigned mana) : _health(health), _mana(mana){};
unsigned int Player::mana() { return _mana; }
unsigned int Player::mana(unsigned int new_mana) { return (_mana = new_mana); }
int Player::health() { return _health; }
int Player::health(int new_health) { return (_health = new_health); }
