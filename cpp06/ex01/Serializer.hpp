#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{   
    public:
        static size_t serialize(Data* ptr);
        static Data* deserialize(size_t raw);

};
#endif