#include "BitcoinRef.hpp"

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
            throw BitcoinRef::FileErr();
        std::string file = argv[1];
        BitcoinRef _bitcoin(file);
        _bitcoin.scale_bitcoin();
        
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}