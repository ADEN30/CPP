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
    if (str[i] == '-' || str[i] == '+')
        i++;
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
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!std::isdigit(str[i]))
        return (false);
    while((i < str.size() && isdigit(str[i])) || str[i] == '.')
    {
        if (str[i] == '.')
            _dot++;
        i++;
    }
    if (_dot != 1 || (std::isalnum(str[i]) && i < str.size() - 1) || (str[str.size() - 1] != 'f') || !std::isdigit(str[str.size() - 2]))
        return (false);
    return (true);
}

bool isDouble(std::string str)
{
    int _dot = 0;
    long unsigned int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!std::isdigit(str[i]))
        return (false);
     while((i < str.size() && isdigit(str[i])) || str[i] == '.')
     {
         if (str[i] == '.')
             _dot++;
         i++;
    }
    if (_dot != 1 || (!std::isdigit(str[i]) && i < str.size()) || !std::isdigit(str[str.size() - 1]))
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

