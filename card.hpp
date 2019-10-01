#ifndef ANIMO__CARD_HPP_
#define ANIMO__CARD_HPP_

#include "color.hpp"
#include <functional>
#include <string>

// The other classes need to know about
// Player but it also needs to know about them.
// This is the solution:
class Player;

class Ability {

public:
  Ability(std::function<void(Player &, Player &)> behavior, unsigned int cost);
  void operator()(Player &self, Player &other);

private:
  // TODO: maybe make this a reference,
  // kind of troublesome
  std::function<void(Player &, Player &)> _behavior;
  unsigned int _cost;
};

class Card {
public:
  using RefType = std::reference_wrapper<Card>;
  Card(std::string name, std::string type, std::string description,
       Ability action, Ability reaction, Color color);

  void act(Player &self, Player &other);
  void react(Player &self, Player &other);

private:
  Card();
  std::string _name;
  std::string _type;
  std::string _description;
  Ability _action;
  Ability _reaction;
  const Color _color;
};

#endif // ANIMO__CARD_HPP_
