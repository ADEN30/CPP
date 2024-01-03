#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {
private:
  std::string firstname;
  std::string lastname;
  std::string nickname;
  std::string number;
  std::string secret;

public:
  Contact();
  ~Contact();
  void addcontact(void);
  std::string view(std::string);
  void completed_view(std::string);
  void print(int);
};

#endif
