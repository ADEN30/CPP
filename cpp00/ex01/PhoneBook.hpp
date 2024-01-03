#ifndef PHONE_BOOK
#define PHONE_BOOK
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
  Contact contact[8];
  int number;

public:
  PhoneBook();
  ~PhoneBook();
  void add(void);
  void search(void);
  void exit(void);
};

#endif
