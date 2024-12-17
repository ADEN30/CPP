#include <iostream>
#include <list>
#include <deque>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <cmath>
#include <set>

// Validation des arguments
std::string validate_arguments(int argc, char** argv) {
    if (argc <= 1) {
        return "Aucun argument fourni.";
    }
    for (int i = 1; i < argc; ++i) {
        char* end;
        long value = strtol(argv[i], &end, 10);
        if (*end != '\0' || value < 0) {
            return "Les arguments doivent être des nombres entiers positifs.";
        }
        if (value > INT_MAX) {
            return "Un argument est trop grand.";
        }
    }
    return "";
}

// Fonction pour afficher un conteneur sous forme de chaîne
template <typename Container>
std::string container_to_string(const Container& container) {
    std::ostringstream oss;
    oss << "[";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) {
            oss << " ";
        }
        oss << *it;
    }
    oss << "]";
    return oss.str();
}

// Conversion des arguments en deque
std::deque<int> arguments_to_deque(int argc, char** argv) {
    std::deque<int> result;
    for (int i = 1; i < argc; ++i) {
        result.push_back(std::atoi(argv[i]));
    }
    return result;
}

// Conversion des arguments en deque
std::list<int> arguments_to_list(int argc, char** argv) {
    std::list<int> result;
    for (int i = 1; i < argc; ++i) {
        result.push_back(std::atoi(argv[i]));
    }
    return result;
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

// Insérer les éléments restants en utilisant les groupes Jacobsthal
template <typename Container>
void optimized_insertion(Container& container, std::list<typename Container::value_type>& main_chain, 
                         std::list<typename Container::value_type>& pend) {
    std::deque<size_t> group_sizes = compute_group_sizes(pend.size());
    typename std::list<typename Container::value_type>::iterator pend_it = pend.begin();

    for (std::deque<size_t>::iterator group_it = group_sizes.begin(); group_it != group_sizes.end(); ++group_it) {
        size_t group_size = *group_it;
        for (size_t i = 0; i < group_size && pend_it != pend.end(); ++i, ++pend_it) {
            typename std::list<typename Container::value_type>::iterator insert_pos = 
                std::upper_bound(main_chain.begin(), main_chain.end(), *pend_it);
            main_chain.insert(insert_pos, *pend_it);
        }
    }

    // Appliquer les modifications au conteneur
    container.assign(main_chain.begin(), main_chain.end());
}
template <typename Container>
void sort_pairs(Container& element) {
    if (element.size() < 2) {
        return; // Pas besoin de trier si la taille est inférieure à 2
    }


    typename Container::iterator it = element.begin();
    typename Container::iterator first = it;
    typename Container::iterator second = it;

    
    size_t count = 0;
    size_t half_size = element.size() / 2;

    // Parcours de la liste pour trouver et échanger les paires
    while (it != element.end()) {
        if (count == half_size - 1) {
            // Initialiser `first` juste avant la fin de la première moitié
            first = it;
        } 
        else if (count == element.size() - 1) {
            // Comparer et échanger avec le dernier élément
            second = it;
            std::cout << "first = " << *first << " second = " << *second << std::endl;
            if (*second < *first) {
                std::cout << "swap" << std::endl;
				if (first == element.begin())
				{
				}
					std::advance(first, 1);
                std::rotate(element.begin(),  first, element.end()); // Echanger les éléments
            }
        }
        
        ++it;
        ++count;
    }

    // Affichage de l'état du conteneur après tri
    std::cout << "Liste après tri des paires : ";
    for (typename Container::iterator it = element.begin(); it != element.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
Container ford_johnson_sort(Container& container, size_t nb_boucle) {
	std::cout << "CALL FORD-JONHSON" << std::endl;
    // Vérification de la condition d'arrêt : taille <= 1 ou non divisible par nb_boucle
    if (container.size() <= 1) {
        return container;  // Retourner le conteneur tel quel si la taille n'est pas divisible par nb_boucle
    }

    // Diviser le conteneur en paires
    Container main_chain;
    typename Container::iterator it = container.begin();
    typename Container::iterator init = it;
    std::list<int> tmp;

    // Traitement des éléments du conteneur
    while (it != container.end() && container.size() / nb_boucle != 0) {
        // Enregistrer la position de l'itérateur initial
        init = it;

        // Remplir tmp avec nb_boucle éléments
        size_t nb = 0;
        tmp.clear(); // Nettoyer tmp avant de l'utiliser
        while (it != container.end() && nb < nb_boucle) {
            tmp.push_back(*it);
			it = container.erase(it);
            ++nb;
        }

        // Trier les paires dans tmp (fonction sort_pairs à définir séparément)
        sort_pairs(tmp);

        // Supprimer les éléments traités de container

        // Ajouter les éléments triés dans main_chain
        for (typename std::list<int>::iterator i = tmp.begin(); i != tmp.end(); ++i) {
            main_chain.push_back(*i);
        }

        // Affichage du conteneur après modification
        std::cout << "Container après modification: ";
        for (typename Container::iterator iter = main_chain.begin(); iter != main_chain.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    // Appel récursif si la taille de main_chain est encore divisible par nb_boucle
    if (main_chain.size() % nb_boucle == 0) {
        return ford_johnson_sort(main_chain, nb_boucle *2);
    }

    // Retourner la chaîne principale une fois que la taille n'est plus divisible par nb_boucle
    return main_chain;
}


template <typename Container>
bool estTrie(const Container& container) {
    if (container.empty()) {
        return true; // Un conteneur vide est considéré comme trié
    }

    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator suivant = it;
    ++suivant;

    // Comparer chaque élément avec le suivant
    while (suivant != container.end()) {
        if (*suivant < *it) {
            return false; // Pas trié si un élément est plus petit que le précédent
        }
        ++it;
        ++suivant;
    }

    return true; // Tous les éléments sont dans l'ordre croissant
}

int main(int argc, char** argv) {
    // Validation des arguments


    std::string validation_error = validate_arguments(argc, argv);
    if (!validation_error.empty()) {
        std::cerr << "Erreur : " << validation_error << std::endl;
        return EXIT_FAILURE;
    }

    // Conversion des arguments
    std::deque<int> deq = arguments_to_deque(argc, argv);
    std::list<int> lis = arguments_to_list(argc, argv);

    // Mesure du temps pour le deque
    clock_t start_deq = clock();
    std::cout << "\033[31mAvant\033[00m : " << container_to_string(arguments_to_deque(argc, argv)) << std::endl;
    ford_johnson_sort(deq, 2);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;

    // Affichage des résultats
    std::cout << "\033[31mAvant\033[00m : " << container_to_string(arguments_to_deque(argc, argv)) << std::endl;
    std::cout << "\033[32mAprès\033[00m : " << container_to_string(deq) << std::endl;
    	std::cout << "Temps pour trier " << deq.size() << " éléments avec Ford-Johnson : " << time_deq << "s" << std::endl;


    clock_t start_list = clock();
    ford_johnson_sort(lis, 2);
    clock_t end_list = clock();
    double time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC;

    // Affichage des résultats
    std::cout << "Temps pour trier list " << lis.size() << " éléments avec Ford-Johnson : " << time_list << "s" << std::endl;
    return EXIT_SUCCESS;
}
