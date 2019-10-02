#include <optional>
#include <utility>

#include "monstercards.hpp"

using std::optional;

Monstercards::Monstercards(Player &p1, Player &p2, Player &starting)
    : _player1(p1), _player2(p2), _current(starting) {
  if (&_current == &_player1) {
    _noncurrent = _player2;
  } else {
    _noncurrent = _player2;
  }
}
void Monstercards::next_turn() {
  // Switch current player for next turn
  std::swap(_current, _noncurrent);
}

void Monstercards::make_play(Card &play,
                             std::optional<Card::RefType> reaction) {
  play.act(_player1, _player2);
  if (reaction) {
    reaction.value().get().react(_player1, _player2);
  }
}
