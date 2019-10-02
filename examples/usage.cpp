#include "../extra_colors.hpp"
#include "../monstercards.hpp"
#include "../rps.hpp"
#include <cassert>
#include <iostream>
#include <map>

std::ostream &operator<<(std::ostream &out, const Rps value) {
  static std::map<Rps, std::string> strings;
  if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
    INSERT_ELEMENT(Rps::Rock);
    INSERT_ELEMENT(Rps::Paper);
    INSERT_ELEMENT(Rps::Scissors);
#undef INSERT_ELEMENT
  }

  return out << strings[value];
}

int main() {
  auto dud = [](Player &self, Player &other) {
    other.health(other.health() - 1);
  };
  Ability action(dud, 1);
  Ability reaction(dud, 2);
  Card hurty("Hurty", "mykind", "Hurts your opponent", action, reaction,
             colors::Red);
  Player p1(10, 5);
  Player p2(10, 5);
  Rps p1_sel = rps::random_selection();
  Rps p2_sel = rps::random_selection();

  auto winner = rps::rps(p1_sel, p2_sel);
  while (!winner) {
    p1_sel = rps::random_selection();
    p2_sel = rps::random_selection();
    winner = rps::rps(p1_sel, p2_sel);
  }

  // clunky but should work
  Player &starting = p1;

  if (winner.value() == p1_sel) {
    starting = p1;
  } else {
    starting = p2;
  }

  Monstercards m(p1, p2, starting);
  // Should be something like this
  // Card& p1_sel = get_card_selection();
  // Where the client implements the above function
  // Also do the same for the other player's reaction
  Card &current_play = hurty;
  // No reaction:
  m.make_play(current_play);
  m.next_turn();
  // With other player reaction:
  // Card& other_reaction = get_other_reaction();
  // m.make_play(current_play, other_reaction);
  // where get_other_reaction is a function provided by the client
  //}
  return 0;
}
