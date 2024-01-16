#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat test("Paul", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}