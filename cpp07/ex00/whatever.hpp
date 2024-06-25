#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <string>
#include <iostream>

void printsmth();

template<typename T>
void swap(T & a, T & b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename U>
U min(U const &  a, U const & b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename A>
A max(A const & a, A const & b)
{
    if (a > b)
        return (a);
    return (b);
}


#endif