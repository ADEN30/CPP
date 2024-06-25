#include "Span.hpp"


int main()
{
    Span sp = Span(3);
    unsigned int arr[] ={4, 20, 21} ; 
    try
    {
        sp.add_sev_numbers(arr, sizeof(arr) / sizeof(unsigned int));
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}