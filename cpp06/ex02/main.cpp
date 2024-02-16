#include "Base.hpp"

int main()
{
    Base *ptr;
    Base src;

    ptr = src.generate();
    src.identify(ptr);
    src.identify(*ptr);
}