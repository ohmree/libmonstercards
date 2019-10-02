#ifndef ANIMO_MONSTERCARDS_HPP
#define ANIMO_MONSTERCARDS_HPP

#include "card.hpp"
#include "player.hpp"

class Monstercards {
public:
  Monstercards(Player &p1, Player &p2, Player &starting);

  void next_turn();
  void make_play(Card &play,
                 std::optional<Card::RefType> reaction = std::nullopt);

private:
  Player &_player1, &_player2;
  Player &_current;
  Player _noncurrent;

  Monstercards();
};

#endif
