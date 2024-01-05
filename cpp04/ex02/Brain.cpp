#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor called\n"; }

Brain::Brain(const Brain &copy) {
  *this = copy;
  std::cout << "Brain copy constructor called\n";
}

Brain::~Brain() { std::cout << "Brain destructor called\n"; }

Brain &Brain::operator=(const Brain &src) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = src.ideas[i];
  }
  std::cout << "Brain assignements called\n";
  return (*this);
}
