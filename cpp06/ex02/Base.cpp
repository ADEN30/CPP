#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){}

Base::~Base(){}

Base* Base::generate()
{
   time_t t;
   Base* ptr;

   time(&t);
   switch (t % 3)
   {
    case 0:
        return (ptr = new A());
    case 1:
        return (ptr = new B());
    case 2:
        return (ptr = new C());
   }
   return (NULL);
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void Base::identify(Base& p) {
	try
	{
		
		A & _p = dynamic_cast<A&>(p);
		(void)_p;
        std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B & _p = dynamic_cast<B&>(p);
		(void)_p;
        std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C & _p = dynamic_cast<C&>(p);
		(void)_p;
        std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}