#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span & src)
{
    *this = src;
}

Span& Span::operator=(const Span & src)
{
   _arr = src._arr;
   _size = src._size;
   return (*this);
}

Span::~Span(){}


void	Span::addNumber(unsigned int nb)
{
	if (_arr.size() + 1 > _size)
		throw tabFull();
	_arr.push_back(nb);
}


void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_arr.size() + std::distance(begin, end) > _size)
		throw tabFull();
	_arr.insert(_arr.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
	if (_arr.size() <= 1)
		throw tabSize();
	std::vector<unsigned int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	std::vector<unsigned int>::iterator it = std::min_element(tmp.begin(), tmp.end());
	while (*it == 0 && it != tmp.end())
		it++;
	return (*it);

}

unsigned int Span::longestSpan()
{
	if (_arr.size() <= 1)
		throw tabSize();
	std::vector<unsigned int> tmp = _arr;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

const char* Span::tabFull::what() const throw()
{
    return ("The container of the Span is full, can't add a number");
}
const char* Span::tabSize::what() const throw()
{
    return ("The container of the Span does not have at least 2 elements");
}
const char* Span::tabEmpty::what() const throw()
{
    return ("The tab is empty");
}
const char* Span::tabLength::what() const throw()
{
    return ("The size of the tab is too high");
}