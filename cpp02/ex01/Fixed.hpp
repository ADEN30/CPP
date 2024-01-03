#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed {
public:
  Fixed();
  Fixed(const int input);
  Fixed(const float input);
  Fixed(const Fixed &copy);
  ~Fixed();
  Fixed &operator=(const Fixed &rh);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int nb;
  static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj);

#endif
