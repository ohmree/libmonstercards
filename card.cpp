#include "card.hpp"
#include "player.hpp"

Ability::Ability(std::function<void(Player &, Player &)> behavior,
                 unsigned int cost)
    : _behavior(behavior), _cost(cost) {}
void Ability::operator()(Player &self, Player &other) {
  _behavior(self, other);
}
unsigned int Ability::cost() { return _cost; }

Card::Card(std::string name, std::string type, std::string description,
           Ability action, Ability reaction, Color color)
    : _name(name), _type(type), _description(description), _action(action),
      _reaction(reaction), _color(color){};

void Card::act(Player &self, Player &other) {
  self.mana(self.mana() - _action.cost());
  _action(self, other);
}

void Card::react(Player &self, Player &other) {
  self.mana(self.mana() - _reaction.cost());
  _reaction(self, other);
}
