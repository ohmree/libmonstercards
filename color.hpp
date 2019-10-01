#ifndef ANIMO__COLORS_HPP_
#define ANIMO__COLORS_HPP_

class Color {
public:
  Color(unsigned r, unsigned g, unsigned b);
  unsigned r();
  unsigned g();
  unsigned b();

private:
  unsigned _r;
  unsigned _g;
  unsigned _b;
};

#endif // ANIMO__COLORS_HPP_
