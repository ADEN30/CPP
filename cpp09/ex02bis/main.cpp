#include "SortMerge.hpp"
int main() {
    // Exemple d'utilisation de la génération de Jacobsthal
    std::deque<size_t> jacobsthalDeque = generateJacobsthal<std::deque<size_t> >(10);
    std::cout << "Nombres de Jacobsthal : ";
    for (std::deque<size_t>::const_iterator it = jacobsthalDeque.begin(); it != jacobsthalDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Exemple d'utilisation de la génération des réels-index
    std::deque<size_t> unsortedDeque;
    unsortedDeque.push_back(5);
    unsortedDeque.push_back(1);
    unsortedDeque.push_back(8);
    unsortedDeque.push_back(2);

    std::deque<double> realIndices = generateRealIndices(unsortedDeque);
    std::cout << "Réels-index : ";
    for (std::deque<double>::const_iterator it = realIndices.begin(); it != realIndices.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Création et tri des paires
    std::deque<std::pair<size_t, size_t> > pairs = createPairs(unsortedDeque);
    std::cout << "Paires générées (triées par valeurs internes) : ";
    for (std::deque<std::pair<size_t, size_t> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    sortPairsByWidth(pairs);
    std::cout << "Paires triées par largeur : ";
    for (std::deque<std::pair<size_t, size_t> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    return 0;
}