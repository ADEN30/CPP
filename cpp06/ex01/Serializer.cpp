#include "Serializer.hpp"

size_t Serializer::serialize(Data* ptr)
{
   return (reinterpret_cast<size_t>(ptr)); 
}

Data* Serializer::deserialize(size_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}