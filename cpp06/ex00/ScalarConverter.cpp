#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter()
{};

void ScalarConverter::convert(std::string  str)
{
    if (first_check(str))
    {
        if (isChar(str))
        {
            printChar(str[0]);
            std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "Float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
            std::cout << "Double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        }
        else if (isInt(str))
        {
            int nb = std::atoi(str.c_str());

            printChar(nb);
            std::cout << "Int: " << static_cast<char>(std::atoi(str.c_str())) << std::endl;
            std::cout << "Float: " << static_cast<float>(std::atoi(str.c_str())) << ".0f" << std::endl;
            std::cout << "Double: " <<  static_cast<double>(std::atoi(str.c_str())) << ".0" << std::endl;

        }
        else if (isFloat(str))
        {
			float _f = atof(str.c_str());

            printChar(std::atoi(str.c_str()));
            std::cout << "Int: " << static_cast<int>(_f) << std::endl;
			if (fmod(_f, 1))
			{
            	std::cout << "Float: " << _f << "f" << std::endl;
           		std::cout << "Double: " << static_cast<double>(_f) << std::endl;
			}
			else
			{
	           	std::cout << "Float: " << _f << ".0f" << std::endl;
           		std::cout << "Double: " << static_cast<double>(_f) << ".0" << std::endl;
			}
        }
        else if (isDouble(str))
        {
			double _d = std::strtod(str.c_str(), NULL);

            printChar(static_cast<char>(_d));
            std::cout << "Int: " << static_cast<int>(_d) << std::endl;
			if (fmod(_d, 1))
			{
				std::cout << "Float: " << static_cast<float>(_d) << "f" << std::endl;
    	        std::cout << "Double: " << _d << std::endl;
			}
			else
			{
				std::cout << "Float: " << static_cast<float>(_d) << ".0f" << std::endl;
    	        std::cout << "Double: " << _d << ".0" << std::endl;
			}
        }
        else
            std::cout << "Invalid argument" << std::endl;
    }
    else
        return ;
}