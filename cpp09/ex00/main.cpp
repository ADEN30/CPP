#include "BitcoinRef.hpp"

int main(int argc, char** argv)
{
    (void) argc;
    std::string file = argv[1];
    try
    {
        BitcoinRef _bitcoin(file);
        _bitcoin.scale_bitcoin();
        
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}