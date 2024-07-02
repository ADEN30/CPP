#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "\e[0;31m";
        Bureaucrat test("Paul", 2);
	    try
	    {
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
	std::cout << "\n\e[0;32m";
	{
		Bureaucrat test("Paul", 2);
	    try
	    {
	        Form paper("Cpp05", 2, 151);
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
	std::cout << "\n\e[0;33m";
	{
		Bureaucrat test("Paul", 2);
 	   try
 	   {
 	       Form paper("Cpp05", 2, 0);
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
}