#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(std::string str);
  Animal(const Animal &src);
  virtual ~Animal();
  Animal &operator=(const Animal &src);
  virtual void makeSound() = 0;
  std::string gettype();
};

#endif
