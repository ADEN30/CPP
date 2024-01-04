#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  this->nb = 5;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called\n";
  *this = copy;
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
