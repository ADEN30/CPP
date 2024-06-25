#include "RPN.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
        return (-1);
    std::string _str = argv[1];
    try
    {
        RPN test(_str);
        std::cout << test << std::endl;
     
    }
    catch(std::string & e)
    {
        std::cerr << e << '\n';
    }
    
    return 0;
}