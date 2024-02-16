#include "iter.hpp"


void print_to_lower(std::string& str)
{
	for (std::string::const_iterator itr = str.begin(); itr != str.end(); itr++)
		std::cout << (char)tolower(*itr);
	std::cout << std::endl;
}

void print_to_upper(std::string& str)
{
	for (std::string::const_iterator itr = str.begin(); itr != str.end(); itr++)
		std::cout << (char)toupper(*itr);
	std::cout << std::endl;
}

int main()
{
	std::string strings[] = {"One", "Two", "Three", "Four"};

	std::cout << "To Upper: " << std::endl;
	::iter(strings, 4, print_to_upper);
	std::cout << "To Lower: " << std::endl;
	::iter(strings, 4, print_to_lower);
}