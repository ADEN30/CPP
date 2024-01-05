#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  Animal *meta = new Animal();
  // the pointer itself is const not the object it points to
  Animal *j = new Dog();
  Animal *i = new Cat();
  std::cout << j->gettype() << " " << std::endl;
  std::cout << i->gettype() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << "-------------------" << std::endl;
  WrongAnimal *wrong = new WrongAnimal();
  wrong->makeSound();
  wrong->gettype();
  delete wrong;
  wrong = new WrongCat();
  wrong->makeSound();
  wrong->gettype();
  delete wrong;
  std::cout << "-------------------" << std::endl;

  delete meta;
  delete i;
  delete j;
  //
  return 0;
}
