#include "color.hpp"

Color::Color(unsigned r, unsigned g, unsigned b) : _r(r), _g(g), _b(b) {}
unsigned Color::r() { return _r; }
unsigned Color::g() { return _g; }
unsigned Color::b() { return _b; }
