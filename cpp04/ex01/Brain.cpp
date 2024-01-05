#include "Brain.hpp"

Brain::Brain(){}

Brain::Brain(const Brain& copy)
{
	*this = copy;
}

Brain::~Brain(){}

Brain& Brain::operator=(const Brain& src)
{
	this->ideas = src.ideas;
	return (*this);
}
