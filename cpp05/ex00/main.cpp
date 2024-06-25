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
	std::cout << "\n";
 	try
    {
        Bureaucrat test("Valerian", 147);
        test.promote();
        test.demote();
        test.demote();
        test.demote();
        test.demote();
        test.demote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}