#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
public:
  WrongCat(void);
  WrongCat(const WrongCat &copy);
  WrongCat &operator=(const WrongCat &copy);
  ~WrongCat(void);

  void makeSound(void);
};

#endif
