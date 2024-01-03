#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
private:
public:
  Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &src);
  ~Cat();
  void makeSound();
};

#endif
