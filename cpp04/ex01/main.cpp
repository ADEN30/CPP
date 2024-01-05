#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>


int main() {
  Animal *meta = new Animal();
  Animal *j = new Dog();
  Animal *i = new Cat();
  std::cout << j->gettype() << " " << std::endl;
  std::cout << i->gettype() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete j;
  delete i;
  delete meta;
  return 0;
}
