#include "PmergeMe.hpp"

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

// Calcul du nombre de Jacobsthal
long jacobsthal_number(long n) {
    return static_cast<long>((pow(2, n + 1) + pow(-1, n)) / 3);
}

// Générer une séquence de Jacobsthal
std::deque<long> generate_jacobsthal_sequence(size_t size) {
    std::deque<long> sequence;
    for (size_t i = 0; i < size; ++i) {
        sequence.push_back(jacobsthal_number(i));
    }
    return sequence;
}

// Calculer les tailles des groupes à partir de la séquence de Jacobsthal
std::deque<size_t> compute_group_sizes(size_t n) {
    std::deque<size_t> group_sizes;
    std::deque<long> jacobsthal = generate_jacobsthal_sequence(n + 2);
    for (size_t i = 2; i < jacobsthal.size() && n > 0; ++i) {
        size_t group_size = std::min(static_cast<size_t>(jacobsthal[i] - jacobsthal[i - 1]), n);
        group_sizes.push_back(group_size);
        n -= group_size;
    }
    return group_sizes;
}