#include "Contact.hpp"
#include <string>

void Contact::addcontact(void) {
  std::cout << "Enter the name : " << std::flush;
  std::cin >> this->firstname;
  std::cout << "Enter the lastname : " << std::flush;
  std::cin >> this->lastname;
  std::cout << "Enter the nickname : " << std::flush;
  std::cin >> this->nickname;
  std::cout << "Enter the phone number : " << std::flush;
  std::cin >> this->number;
  std::cout << "Enter the biggest secret of the guy : " << std::flush;
  std::cin >> this->secret;
  std::cout << "Enter the name : " << std::flush;
  std::cout << "You have a new contact !" << std::endl;
}

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::view(std::string str) {
  //  std::cout << str.length() << std::endl;
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");

  return (str);
}

void Contact::completed_view(std::string str) {
  int i;

  i = 0;
  while (str.length() + i < 10) {
    std::cout << ' ';
    i++;
  }
}

void Contact::print(int index) {
  if (index == 0) {
    completed_view("index");
    std::cout << "index" << std::flush;
    completed_view("firstnam");
    std::cout << "firstname" << std::flush;
    completed_view("lastnam");
    std::cout << "lastname" << std::flush;
    completed_view("nicknam");
    std::cout << "nickname" << std::endl;
  }
  completed_view(" ");
  std::cout << index << "|" << std::flush;
  completed_view(this->firstname);
  std::cout << view(this->firstname) << std::flush;
  std::cout << "|" << std::flush;
  completed_view(this->lastname);
  std::cout << view(this->lastname) << std::flush;
  std::cout << "|" << std::flush;
  completed_view(this->nickname);
  std::cout << view(this->nickname) << std::flush;
  std::cout << std::endl;
}
