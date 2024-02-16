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

void Base::identify(Base* p)
{
    std::cout << typeid(*p).name() << std::endl;
}

void Base::identify(Base& p)
{
    std::cout << typeid(p).name() << std::endl;
}