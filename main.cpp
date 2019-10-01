#include <iostream>
#include <optional>
#include <vector>

#include "card.hpp"
#include "extra_colors.hpp"
#include "player.hpp"
#include "rps.hpp"

using std::optional;
using std::vector;

class Monstercards {
public:
  Monstercards(Player &p1, Player &p2, Player &starting)
      : _player1(p1), _player2(p2), _current(starting) {}
  void turn(Card &play, std::optional<Card::RefType> reaction) {
    play.act(_player1, _player2);
    if (reaction) {
      reaction.value().get().react(_player1, _player2);
    }
  }

private:
  Player &_player1, &_player2;
  Player &_current;

  Monstercards();
};

// example client code
int main() {

  // the player's deck can be gotten in many ways
  // my fav idea is using lua as a config format,
  // basically like json with lambdas that take
  // two players (self, other) for card behavior
  auto dud = [](Player &self, Player &other) {};
  Ability action(dud, 1);
  Ability reaction(dud, 2);

  Card c1("Man", "normal", "Does literally nothing", action, reaction,
          colors::Red);
  vector<Card::RefType> v{c1};
  Player p1(10, 5, v);
  Player p2(10, 5, v);

  // choosing starting player
  // imagine this is gotten
  // by magic ui function
  // "Rps get_rps_selection()"
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

  // TODO: progress
  return 0;
}
