#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat test("Paul", 2);
        test.demote();
        test.promote();
        test.promote();
        test.promote();
        test.promote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}