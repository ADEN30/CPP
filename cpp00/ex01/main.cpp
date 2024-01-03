#include "PhoneBook.hpp"

int main(void) {
  PhoneBook phone1;
  std::string order;
  do {
    std::cout << "Enter an instruction" << std::endl;
    std::cin >> order;

    if (std::cin.good() && order == "ADD")
      phone1.add();
    else if (std::cin.good() && order == "SEARCH")
      phone1.search();
  } while (order != "EXIT");
  return (0);
}
