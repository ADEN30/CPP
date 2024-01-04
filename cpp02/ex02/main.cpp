#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a(2);
    Fixed b(3.5f);
    Fixed c(1.8f);

    // Opérateurs de comparaison
    std::cout << "Comparison operators:" << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;

    // Opérateurs arithmétiques
    std::cout << "\nArithmetic operators:" << std::endl;
    std::cout << "a = " << a.toInt() << " | b = " << b.toFloat() << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * c: " << a * b << std::endl;
    std::cout << "b / a: " << b / a << std::endl;

    // Opérateurs d'incrémentation et de décrémentation
    std::cout << "\nIncrement and Decrement operators:" << std::endl;

    std::cout << "Original a: " << a.toInt() << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "After a++: " << a << std::endl;

    std::cout << "\nOriginal b: " << b << std::endl;
    std::cout << "--b: " << --b << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "After b--: " << b << std::endl;

    // Fonctions membres statiques min et max
    std::cout << "\nStatic min and max functions:" << std::endl;
    std::cout << "a = " << a << " | b = " << b << " | c = " << c << std::endl;
    Fixed fminValue = Fixed::min(a, b);
    Fixed fmaxValue = Fixed::max(c, b);

    std::cout << "min(a, b): " << fminValue << std::endl;
    std::cout << "max(c, b): " << fmaxValue << std::endl;

    return 0;

}
