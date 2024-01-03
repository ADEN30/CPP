#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(std::string str);
  Animal(const Animal &src);
  ~Animal();
  Animal &operator=(const Animal &src);
  virtual void makeSound();
};

#endif
