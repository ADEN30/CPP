#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class RPN
{
    private:
        std::vector<int> _digit;
        std::string _operator;
    public:
        RPN(std::string &);
        RPN(const RPN&);
        RPN& operator=(const RPN &);
       ~RPN();
        const int* getdigit() const;
        const std::string getstr() const;
        unsigned int getDigitsize() const;
        void    calculate();
        int     operations(char c, int, int);
};


std::ostream& operator<<(std::ostream&, const RPN &);

#endif