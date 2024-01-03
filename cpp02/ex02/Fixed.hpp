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
  int operator==(const Fixed &rh);
  int operator<=(const Fixed &rh);
  int operator>=(const Fixed &rh);
  int operator!=(const Fixed &rh);
  int operator>(const Fixed &rh);
  int operator<(const Fixed &rh);
  Fixed operator*(const Fixed &rh) const;
  Fixed operator/(const Fixed &rh) const;
  Fixed operator-(const Fixed &rh) const;
  Fixed operator+(const Fixed &rh) const;
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed const &min(Fixed const &a, Fixed const &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(Fixed const &a, Fixed const &b);
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
