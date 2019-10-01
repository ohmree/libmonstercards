#ifndef ANIMO__RPS_HPP_
#define ANIMO__RPS_HPP_

#include <map>
#include <optional>

enum class Rps { Rock, Paper, Scissors };
std::optional<Rps> rps(Rps p1, Rps p2);
#endif // ANIMO__RPS_HPP_
