#include "Harl.hpp"

int main( void ) {

    std::string input;
    Harl        harl;

    do
    {
        std::cout << "Enter a level: ";
        std::cin >> input;
        if (!std::cin.eof())
            harl.complain(input);
    } while (input.compare("exit") && !std::cin.eof());

    return 0;
}
