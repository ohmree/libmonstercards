#ifndef ANIMO__RPS_HPP_
#define ANIMO__RPS_HPP_

#include <map>
#include <optional>

enum class Rps { Rock, Paper, Scissors };
namespace rps {
std::optional<Rps> rps(Rps p1, Rps p2);
Rps random_selection();
} // namespace rps

#endif // ANIMO__RPS_HPP_
