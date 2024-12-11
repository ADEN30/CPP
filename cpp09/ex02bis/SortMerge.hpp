#ifndef SORTMERGE_HPP
#define SORTMERGE_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm> // pour std::sort

// Fonction pour générer les nombres de Jacobsthal
template <typename Container>
Container generateJacobsthal(size_t n) {
    Container jacobsthal;
    if (n > 0) jacobsthal.push_back(0);
    if (n > 1) jacobsthal.push_back(1);

    for (size_t i = 2; i < n; ++i) {
        size_t next = *(++jacobsthal.rbegin()) + 2 * *(jacobsthal.rbegin());
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

// Fonction pour générer les réels-index basés sur les nombres de Jacobsthal
template <typename Container>
std::deque<double> generateRealIndices(const Container& unsorted) {
    size_t n = unsorted.size();

    // Générer les nombres de Jacobsthal jusqu'à n
    std::deque<size_t> jacobsthal = generateJacobsthal<std::deque<size_t> >(n);

    // Calculer les réels-index
    std::deque<double> realIndices;
    if (n > 0) {
        for (size_t i = 0; i < n; ++i) {
            realIndices.push_back(static_cast<double>(jacobsthal[i]) / jacobsthal[n - 1]);
        }
    }

    return realIndices;
}

// Fonction récursive pour créer et trier des paires à partir d'un conteneur
template <typename Container>
std::deque<std::pair<typename Container::value_type, typename Container::value_type> > createPairs(Container& container, size_t index = 0) {
    std::deque<std::pair<typename Container::value_type, typename Container::value_type> > pairs;

    if (index + 1 < container.size()) {
        typename Container::iterator it = container.begin();
        std::advance(it, index);
        typename Container::iterator nextIt = it;
        std::advance(nextIt, 1);

        // Trier la paire avant de l'ajouter
        if (*it > *nextIt) {
            std::swap(*it, *nextIt);
        }
        pairs.push_back(std::make_pair(*it, *nextIt));

        // Appel récursif
        std::deque<std::pair<typename Container::value_type, typename Container::value_type> > remainingPairs = createPairs(container, index + 2);
        pairs.insert(pairs.end(), remainingPairs.begin(), remainingPairs.end());
    }

    return pairs;
}

// Fonction pour trier les paires par largeur (différence entre les deux valeurs)
template <typename Pair>
size_t calculateWidth(const Pair& pair) {
    return std::abs(static_cast<int>(pair.first) - static_cast<int>(pair.second));
}


// Fonction de comparaison pour trier les paires par largeur
template <typename Pair>
bool comparePairsByWidth(const Pair& a, const Pair& b) {
    return calculateWidth(a) < calculateWidth(b);
}

template <typename PairContainer>
void sortPairsByWidth(PairContainer& pairs) {
    // Utilisation de la fonction de comparaison classique avec std::sort
    std::sort(pairs.begin(), pairs.end(), comparePairsByWidth<typename PairContainer::value_type>);
}




#endif