#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
  Contact last;

  last.addcontact();
  this->contact[this->number % 8] = last;
  this->number += 1;
}

void PhoneBook::search() {
  int i;
  int value;
  int length;

  i = 0;
  if (this->number >= 8)
    length = 8;
  else
    length = this->number;
  while (i < length) {
    this->contact[i].print(i);
    i++;
  }
  do {
    std::cout << "Search the contact with the index : ";
    std::cin >> value;
    if (value < 0 || value >= length)
      std::cout << "Error index : " << value << std::endl;
    else
      this->contact[value].print(value);
  } while (value < 0 || value >= length);
}
