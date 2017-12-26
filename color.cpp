#include "color.hpp"

Color::Color(Color const& c):r(c.r), g(c.g), b(c.b) {}

Color::Color(int rr, int gg, int bb): r(rr), g(gg), b(bb) {}
