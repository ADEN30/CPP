#include "easyfind.hpp"
#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 67, 8};
    std::vector<int> vec(arr, arr + 4);
    try
    {
        std::vector<int>::iterator it = ::easyfind(vec, 10);    
        std::cout << *it << std::endl;
    }
    catch(const std::string &e)
    {
        std::cerr << e << '\n';
    }
    
    try
    {
        std::vector<int>::iterator it = ::easyfind(vec, 67);    
        std::cout << *it << std::endl;
    }
    catch(std::string &e)
    {
        std::cerr << e << '\n';
    }
    
    return (0);
}

