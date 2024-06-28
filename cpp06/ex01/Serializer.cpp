#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
   return (reinterpret_cast<size_t>(ptr)); 
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}