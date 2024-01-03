#include <iostream>

int islow(char c) {
  if (c >= 97 && c <= 122)
    return (1);
  return (0);
}

void print(std::string str) {
  int i;

  i = 0;
  while (str[i]) {
    if (islow(str[i])) {
      std::cout << (char)(str[i] - 32);
    } else {
      std::cout << str[i];
    }
    i++;
  }
}

int main(int argv, char **argc) {
  int i;

  i = 1;
  if (argv > 1) {
    while (i < argv) {
      print(argc[i]);
      i++;
    }
    std::cout << std::endl;
  } else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  return (0);
}
