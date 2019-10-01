#include "rps.hpp"

std::optional<Rps> rps(Rps p1, Rps p2) {
  std::map<Rps, Rps> what_beats{{Rps::Rock, Rps::Paper},
                                {Rps::Paper, Rps::Scissors},
                                {Rps::Scissors, Rps::Rock}};
  if (p1 == p2) {
    return std::nullopt;
  }
  if (p1 == what_beats[p2]) {
    return std::make_optional(p1);
  } else if (p2 == what_beats[p1]) {
    return std::make_optional(p2);
  } else {
    return std::nullopt;
  }
}
