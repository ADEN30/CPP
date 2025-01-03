#include "RPN.hpp"

RPN::RPN(std::string & str)
{
    std::string _build;
    int nombre;
    for(long unsigned int i = 0; i < str.size(); i++)
    { 
        if ((str[i] == '-' || str[i] == '+') && i < str.size() - 1 && std::isdigit(str[i + 1]))
            _build.push_back(str[i++]);
        if (std::isdigit(str[i])) 
        {
            _build.push_back(str[i]);
            nombre = std::atoi(_build.c_str());
            _digit.push_back(nombre);
            _build.clear();
            if (i < str.size() - 1 && std::isdigit(str[i + 1]))
                throw (std::string("The figures maximal is 9, you have a figure hightest than 9"));
        }
        else if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '/')
        {
            _operator.push_back(str[i]);
            this->calculate();
        }
        else if (i < str.size() && str[i] != ' ')
            throw std::string("Error");

    }
   if (this->getDigitsize() > 1)
        throw std::string("The syntaxe of RPN is wrong. Maybe, you have too many number. We take only 0 <= number < 10");
    else if (_operator.size() > 0)
        throw std::string("The syntaxe of RPN is wrong. Maybe, you have too many operator..");
}

RPN::RPN(const RPN & src)
{
    *this = src;
}

RPN& RPN::operator=(const RPN & src)
{
    const int* _tmp = src.getdigit();
    std::string _str(src.getstr());

    _operator = _str;
    for (size_t i = 0; i < src.getDigitsize() ; i++)
        _digit.push_back(_tmp[i]);
    return (*this);
}

RPN::~RPN()
{

}

const int* RPN::getdigit() const
{
    return (_digit.data());
}

const std::string RPN::getstr() const
{
    return (_operator);
}

unsigned int RPN::getDigitsize() const
{
    return (_digit.size());
}

int RPN::operations(char c, int nb1, int nb2)
{
    switch (c)
    {
    case '+':
        return (nb1 + nb2);
    case '-':
        return (nb1 - nb2);
    case '*':
        return (nb1 * nb2);
    case '/':
        return (nb1 / nb2);
    }
    throw -2;
}

void RPN::calculate()
{
    int _tmp;

    while (this->getDigitsize() > 1 && _operator.size() > 0)
    {
        try
        {
            _tmp = this->operations(_operator[0], _digit[0], _digit[1]);
            _operator.erase(_operator.begin());
            _digit.erase(_digit.begin());
            _digit.erase(_digit.begin());
            _digit.insert(_digit.begin(), _tmp);

        }
        catch(std::string & e)
        {
            std::cerr << e << '\n';
        }
        
    }
}

std::ostream& operator<<(std::ostream& f, const RPN & src)
{
    const int*  _tab;
    _tab = src.getdigit();
    for(unsigned int i = 0; i < src.getDigitsize(); i++)
        f << _tab[i] << " ";
    
    return (f);

}