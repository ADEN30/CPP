#include "whatever.hpp"

template<typename T>
void swap(T & a, T & b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename U>
U min(U const &  a, U const & b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename A>
A max(A const & a, A const & b)
{
    if (a > b)
        return (a);
    return (b);
}

template void swap<int>(int& a, int& b);
template void swap<double>(double& a, double& b);
template void swap<std::string>(std::string& a, std::string& b);

template int min<int>(int const & a, int const & b);
template double min<double>(double const & a, double const & b);
template std::string min<std::string>(std::string const & a, std::string const & b);

template int max<int>(int const & a, int const & b);
template double max<double>(double const & a, double const & b);
template std::string max<std::string>(std::string const & a, std::string const & b);