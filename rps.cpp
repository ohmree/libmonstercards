#include "rps.hpp"
#include "external/pcg-cpp/include/pcg_extras.hpp"
#include "external/pcg-cpp/include/pcg_random.hpp"
#include <random>

std::optional<Rps> rps::rps(Rps p1, Rps p2) {
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

namespace {
// Seed with a real random value, if available
pcg_extras::seed_seq_from<std::random_device> seed_source;

// Make a random number engine
pcg32 rng(seed_source);
std::uniform_int_distribution<int> uniform_dist(0, 2);
} // namespace

Rps rps::random_selection() {
  int mean = uniform_dist(rng);
  size_t random(mean);
  Rps values[3] = {Rps::Rock, Rps::Paper, Rps::Scissors};
  return values[random];
}
