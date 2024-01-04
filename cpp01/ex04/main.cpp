#include "Sed.hpp"
#include <fstream>

int main ( int ac, char **av )
{
    if (ac != 4) {
        std::cerr << "Usage: ./SedV2 <filename> <to_find> <replace>." << std::endl;
        return 1;
    } else {
        Sed   new_sed(av[1]);
        new_sed.replace2(av[2], av[3]);
    }
    return 0;
}	

