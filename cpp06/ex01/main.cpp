#include "Serializer.hpp"

int main()
{
    Data* test = new Data();
    uintptr_t ptr = Serializer::serialize(test) ;
    std::cout << Serializer::deserialize(ptr)->msg << std::endl;;

    delete(test);
    return (0);
}