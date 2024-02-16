#include "ToolsConverter.hpp"

bool isChar(std::string str)
{
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
    {
        return (true);
    }
    return (false);
}

bool isInt(std::string str)
{
    long unsigned int i = 0;

    while(i < str.size() && isdigit(str[i]))
    {
        i++;
    }
    if (str[i])
        return (false);
    return (true);
}

bool isFloat(std::string str)
{
    int _dot = 0;
    long unsigned int i = 0;
    if (str[i] == '-')
        i++;
    while((i < str.size() && isdigit(str[i])) || str[i] == '.')
    {
        if (str[i] == '.')
            _dot++;
        i++;
    }
    if (_dot != 1 || str[i] != 'f' || (str[i] == 'f' && i != str.size() - 1) || (str[i - 2] != '.' && _dot == 1))
        return (false);
    return (true);
}

bool isDouble(std::string str)
{
    int _dot = 0;
    long unsigned int i = 0;

    if (str[i] == '-')
        i++;
     while((i < str.size() && isdigit(str[i])) || str[i] == '.')
     {
         if (str[i] == '.')
             _dot++;
         i++;
    }
    if (_dot != 1 || str[i] || (str[i - 2] != '.' && _dot == 1))
        return (false);
    return (true);
}

void printChar(int c)
{
    if (std::isprint(c))
        std::cout << "Char: '" << (char)c << "'" << std::endl;
    else
        std::cout << "char: Impossible to display" << std::endl;
    
}

bool first_check(std::string str)
{
    if (!str.compare("+inf") || !str.compare("+inff"))
    {
        std::cout << "char: " << "Impossible to display." << std::endl;
        std::cout << "Int: " << "Impossible to display." << std::endl;
        std::cout << "Float: " << "+inff." << std::endl;
        std::cout << "Double: " << "+inf." << std::endl;
        return (false);
    }
    else if (!str.compare("-inf") || !str.compare("-inff"))
    {
        std::cout << "char: " << "Impossible to display." << std::endl;
        std::cout << "Int: " << "Impossible to display." << std::endl;
        std::cout << "Float: " << "-inff." << std::endl;
        std::cout << "Double: " << "-inf." << std::endl;
        return (false);

    }
    else if (!str.compare("nanf") || !str.compare("nan"))
    {
        std::cout << "char: " << "Impossible to display." << std::endl;
        std::cout << "Int: " << "Impossible to display." << std::endl;
        std::cout << "Float: " << "nanf." << std::endl;
        std::cout << "Double: " << "nan." << std::endl;
        return (false);

    }
        
   return (true);
}

