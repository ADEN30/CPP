#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <list>

class Span
{
    private:
        std::vector<unsigned int> _arr;
        unsigned int _size;

    public:
        Span(unsigned int);
        Span(const Span &);
        Span& operator=(const Span &);
        ~Span();
        void addNumber(unsigned int);
        void addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class tabFull : public std::exception
        {
            const char* what() const throw();
        };
        class tabSize : public std::exception
        {
            const char* what() const throw();
        };
        class tabEmpty : public std::exception
        {
            const char* what() const throw();
        };
        class tabLength : public std::exception
        {
            const char* what() const throw();
        };

};

#endif