#include "SortMerge.hpp"

void print_colored(const std::string& text, const std::string& color) {
    // Codes ANSI des couleurs
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";

    std::string chosen_color;
    if (color == "red") chosen_color = RED;
    else if (color == "green") chosen_color = GREEN;
    else if (color == "yellow") chosen_color = YELLOW;
    else if (color == "blue") chosen_color = BLUE;
    else if (color == "magenta") chosen_color = MAGENTA;
    else if (color == "cyan") chosen_color = CYAN;
    else if (color == "white") chosen_color = WHITE;
    else chosen_color = RESET; // Par défaut, réinitialiser la couleur

    std::cout << chosen_color << text << RESET << std::endl;
}