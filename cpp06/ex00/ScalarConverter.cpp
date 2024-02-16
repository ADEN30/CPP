#include "ScalarConverter.hpp"
#include <cstdlib>
void ScalarConverter::convert(std::string  str)
{
    if (first_check(str))
    {
        if (isChar(str))
        {
            printChar(str[0]);
            std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "Float: " << static_cast<float>(str[0]) << ".f" << std::endl;
            std::cout << "Double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        }
        else if (isInt(str))
        {
            int nb = std::atoi(str.c_str());
            printChar(nb);
            std::cout << "Int: " << std::atoi(str.c_str()) << std::endl;
            std::cout << "Float: " << std::strtof(str.c_str(), NULL) << ".f" << std::endl;
            std::cout << "Double: " <<  std::strtod(str.c_str(), NULL) << ".0" << std::endl;

        }
        else if (isFloat(str))
        {
            printChar(std::atoi(str.c_str()));
            std::cout << "Int: " << std::atoi(str.c_str()) << std::endl;
            std::cout << "Float: " << str << std::endl;
            std::cout << "Double: " <<  std::strtod(str.c_str(), NULL) << ".0" << std::endl;

        }
        else if (isDouble(str))
        {
            printChar(std::atoi(str.c_str()));
            std::cout << "Int: " << std::atoi(str.c_str()) << std::endl;
            std::cout << "Float: " << str << "f" << std::endl;
            std::cout << "Double: " << str << std::endl;

        }
    }
    else
        return ;
}