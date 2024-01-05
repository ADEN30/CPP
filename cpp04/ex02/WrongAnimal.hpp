#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  ~WrongAnimal();
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal &operator=(const WrongAnimal &src);

  void makeSound(void);
  std::string gettype(void);
};

#endif
