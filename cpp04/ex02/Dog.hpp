#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
class Dog : public Animal {
private:
  Brain *ide;

public:
  Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &src);
  ~Dog();
  void makeSound();
};

#endif
