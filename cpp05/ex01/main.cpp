#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat test("Paul", 2);
        Form paper("Cpp05", 2, 8);
        test.demote();
        std::cout << test;
       test.signForm(paper);
        std::cout << paper;
        test.promote();
       test.signForm(paper);
        std::cout << paper;
        test.promote();
        test.promote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}