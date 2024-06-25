#include "SortMerge.hpp"


int main(int argv, char** argc)
{
    if (argv < 1)
        return (-1);
    std::string _str(argc[1]);
    size_t j;
    std::string _nb;
    std::list<size_t> _arr;
    std::deque<size_t> _arr2;
    for(int i = 1; i < argv; i++)
    {
        j = 0;
        while(argc[i][j] != '\0' && std::isdigit(argc[i][j]))
            _nb.push_back(argc[i][j++]);
        if (_nb.size() > 0)
        {
           _arr.push_back(std::atoi(_nb.c_str())) ;
           _arr2.push_back(std::atoi(_nb.c_str())) ;
           _nb.clear();
        }
        else
            return (-2);
    }
    std::cout << "Before : " << _arr2 << std::endl;
    const std::clock_t c_start = std::clock();
    SortMerge::sort(_arr);
    const std::clock_t c_end = std::clock();
    const std::clock_t c_start2 = std::clock();
    SortMerge::sort(_arr2);
    const std::clock_t c_end2 = std::clock();
    std::cout << "After : " << _arr2 << std::endl;
    std::cout << "Time to process a range of " << _arr.size() << " elements with std::list : ";
    std::cout << static_cast<double>((c_end - c_start)) << " us"<< std::endl;
    std::cout << "Time to process a range of " << _arr.size() << " elements with std::duque : ";
    std::cout << static_cast<double>((c_end2 - c_start2)) << " us"<< std::endl;
} 