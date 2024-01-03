#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *ptr_str = &str;
  std::string &ref_str = str;

  std::cout << "The memory address of the string variable : " << &str
            << std::endl;
  std::cout << "The memory address held by stringPTR : " << &ptr_str
            << std::endl;
  std::cout << "The memory address held by stringREF : " << &ref_str
            << std::endl;

  std::cout << "The memory address of the string variable : " << str
            << std::endl;
  std::cout << "The memory address held by stringPTR : " << *ptr_str
            << std::endl;
  std::cout << "The memory address held by stringREF : " << ref_str
            << std::endl;
}
