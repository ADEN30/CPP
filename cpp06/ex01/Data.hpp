#ifndef DATA_HPP
#define DATA_HPP
#include <string>
#include <iostream>
class Data
{
    public:
        int nb;
        std::string msg;;
        Data();
        ~Data();
};

/* std::ostream& operator<<(std::ostream& flux, const Data *obj)
 {
    flux << obj->nb << std::endl;
    flux << obj->msg << std::endl;
    return (flux);
 }*/

#endif
