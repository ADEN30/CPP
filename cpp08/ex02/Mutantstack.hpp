#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin() {return std::stack<T>::c.begin();}
        iterator end() {return std::stack<T>::c.end();}

        const_iterator begin() const {return std::stack<T>::c.begin();}
        const_iterator end() const {return std::stack<T>::c.begin();}
};

#endif