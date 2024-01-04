#include "Fixed.hpp"
#include <cmath>
#include <iostream>
Fixed::Fixed() {
  //std::cout << "Default constructor called\n";
  this->nb = 0;
}

Fixed::Fixed(const int input) { 
//std::cout << "Int constructor called\n";
this->nb = input << this->bits; }

Fixed::Fixed(const float input) { 
//std::cout << "Float constructor called\n";
this->nb = round(input * (1 << this->bits)); }

Fixed::Fixed(const Fixed &copy) {
  //std::cout << "Copy constructor called\n";
  *this = copy;
}

Fixed::~Fixed() { /*std::cout << "Destructor called\n";*/ }

Fixed &Fixed::operator=(const Fixed &rh) {
 // std::cout << "Copy assignment operator called\n";
  this->nb = rh.nb;
  return (*this);
}

int Fixed::operator==(const Fixed &rh) {
  if (this->nb == rh.nb)
    return (1);
  else
    return (0);
}

int Fixed::operator!=(const Fixed &rh) {
  if (this->nb != rh.nb)
    return (1);
  else
    return (0);
}

int Fixed::operator<=(const Fixed &rh) {
  if (this->nb <= rh.nb)
    return (1);
  else
    return (0);
}

int Fixed::operator>=(const Fixed &rh) {
  if (this->nb >= rh.nb)
    return (1);
  else
    return (0);
}

int Fixed::operator>(const Fixed &rh) {
  if (this->nb > rh.nb)
    return (1);
  else
    return (0);
}

int Fixed::operator<(const Fixed &rh) {
  if (this->nb < rh.nb)
    return (1);
  else
    return (0);
}

Fixed Fixed::operator*(const Fixed &rh) const {
  return (Fixed(this->toFloat() * rh.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rh) const {
  return (Fixed(this->toFloat() / rh.toFloat()));
}

Fixed Fixed::operator+(const Fixed &rh) const {
  return (Fixed(this->toFloat() + rh.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rh) const {
  return (Fixed(this->toFloat() + rh.toFloat()));
}

Fixed &Fixed::operator--(void) {
  --(this->nb);
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed save(*this);
  --(this->nb);
  return (save);
}

Fixed Fixed::operator++(int) {
  Fixed save(*this);
  save.nb = this->nb++;
  return (save);
}

Fixed &Fixed::operator++(void) {
  ++(this->nb);
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}

float Fixed::toFloat(void) const { return (float)this->nb / (1 << this->bits); }

int Fixed::toInt(void) const { return (this->nb >> this->bits); }

std::ostream &operator<<(std::ostream &out, Fixed const &obj) {
  out << obj.toFloat();
  return (out);
}
