#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &copy);
  ~Fixed();
  Fixed &operator=(const Fixed &rh);
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int nb;
  static const int bits;
};

#endif
