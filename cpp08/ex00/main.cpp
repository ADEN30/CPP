#include "easyfind.hpp"
#include <iostream>
#include <deque>

int main()
{
    int arr[] = {1, 38, 3, 67, 8};

    try
    {
		std::cout << "<<<< Vector >>>>" << std::endl;
    	std::vector<int> vec(arr, arr + 5);

		for(std::vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
		{
			std::cout << *i << '\t';
		}
		std::cout << std::endl;

        std::vector<int>::iterator it = ::easyfind(vec, 32);    
        std::cout << *it << std::endl;
    }
    catch(const std::string &e)
    {
        std::cerr << e << '\n';
    }
    
    try
    {
    	std::vector<int> vec(arr, arr + 5);
        std::vector<int>::iterator it = ::easyfind(vec, 1);    
        std::cout << *it << std::endl;
    }
    catch(std::string &e)
    {
        std::cerr << e << '\n';
    }

	std::cout << "<<<< Deque >>>>" << std::endl;
    try
    {
    	std::deque<int> vec(arr, arr +5);

		for(std::deque<int>::iterator i = vec.begin(); i < vec.end(); i++)
		{
			std::cout << *i << '\t';
		}
		std::cout << std::endl;

        std::deque<int>::iterator it = ::easyfind(vec, 4);    
        std::cout << *it << std::endl;
    }
    catch(const std::string &e)
    {
        std::cerr << e << '\n';
    }
    
    try
    {
    	std::deque<int> vec(arr, arr + 5);
        std::deque<int>::iterator it = ::easyfind(vec, 8);    
        std::cout << *it << std::endl;
    }
    catch(std::string &e)
    {
        std::cerr << e << '\n';
    }

    
    return (0);
}

