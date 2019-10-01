#include "card.hpp"

Ability::Ability(std::function<void(Player &, Player &)> behavior,
                 unsigned int cost)
    : _behavior(behavior), _cost(cost) {}
void Ability::operator()(Player &self, Player &other) {
  _behavior(self, other);
}

Card::Card(std::string name, std::string type, std::string description,
           Ability action, Ability reaction, Color color)
    : _name(name), _type(type), _description(description), _action(action),
      _reaction(reaction), _color(color){};

void Card::act(Player &self, Player &other) { _action(self, other); }

void Card::react(Player &self, Player &other) { _reaction(self, other); }
