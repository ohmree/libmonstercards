#include "../extra_colors.hpp"
#include "../monstercards.hpp"
#include "../rps.hpp"
#include <cassert>
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
  Rps p1_sel = Rps::Paper;
  Rps p2_sel = Rps::Scissors;

  auto winner = rps(p1_sel, p2_sel);
  while (!winner) {
    // in real client code these need to be updated on every tie
    // p1_sel = get_rps_selection();
    // p2_sel = get_rps_selection();
    winner = rps(p1_sel, p2_sel);
  }

  // clunky but should work
  Player &starting = p1;

  if (winner.value() == p1_sel) {
    starting = p1;
  } else {
    starting = p2;
  }

  Monstercards m(p1, p2, starting);
  while (p1.health() >= 0 && p2.health() >= 0) {
    // Should be something like this
    // Card& p1_sel = get_card_selection();
    // Where the client implements the above function
    // Also do the same for the other player's reaction
    Card &current_play = hurty;
    // No reaction:
    m.turn(current_play);
    // With other player reaction:
    // Card& other_reaction = get_other_reaction();
    // m.turn(current_play, other_reaction);
    // where get_other_reaction is an imaginary function provided by the client
    assert(p2.health() == 9);
  }
  return 0;
}
