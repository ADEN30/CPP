#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>


class Base
{
    public :
        Base();
        virtual ~Base();
        Base* generate(void);
        void identify(Base*);
        void identify(Base&);
};

#endif