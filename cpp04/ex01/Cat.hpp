#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *ide;

public:
  Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &src);
  ~Cat();
  void makeSound();
};

#endif
