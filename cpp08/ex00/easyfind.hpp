#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T & container, int value )
{

    typename T::iterator ptr = std::find(container.begin(), container.end(), value );
    if (ptr != container.end())
    {
        return (ptr);
    }
    else
        throw (std::string)"not found";

}
#endif