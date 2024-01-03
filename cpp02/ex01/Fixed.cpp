#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  this->nb = 0;
}

Fixed::Fixed(const int input) { this->nb = input << this->bits; }

Fixed::Fixed(const float input) { this->nb = input * (1 << this->bits); }

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called\n";
  this->nb = copy.nb;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed &Fixed::operator=(const Fixed &rh) {
  std::cout << "Copy assignment operator called\n";
  this->nb = rh.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawbits member function called\n";
  return (this->nb);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawbits member function called\n";
  this->nb = raw;
}

float Fixed::toFloat(void) const { return (float)this->nb / (1 << this->bits); }

int Fixed::toInt(void) const { return (this->nb >> this->bits); }

std::ostream &operator<<(std::ostream &out, Fixed const &obj) {
  out << obj.toFloat();
  return (out);
}
