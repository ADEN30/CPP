#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error arguments" << std::endl;
        return (1);
    }
    else
    {
        ScalarConverter::convert(std::string(argv[1]));
    }
    return (0);
    
}