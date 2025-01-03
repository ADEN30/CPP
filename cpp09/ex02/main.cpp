#include "PmergeMe.hpp"


template <typename Container>
bool has_duplicate(const Container& container) {
    typename Container::const_iterator it = container.begin();
    std::set<typename Container::value_type> seen_values;

    while (it != container.end()) {
        if (seen_values.find(*it) != seen_values.end()) {
            return true; // Un doublon a été trouvé
        }
        seen_values.insert(*it);
        ++it;
    }
    return false; // Aucun doublon trouvé
}

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
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) {
            oss << " ";
        }
        oss << *it;
    }
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



    if (has_duplicate(lis) || has_duplicate(deq))
    {
        std::cout << "Il y a un doublon !" << std::endl;
        return 0;
    }
    
    std::cout << "Avant : " << container_to_string(lis) << std::endl;
    
    // Mesure du temps pour le list
     clock_t start_list = clock();
     lis = ford_johnson_sort(lis, 1);
     clock_t end_list = clock();
     double time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC;

    // Affichage des résultats
  	std::cout << "Après : " << container_to_string(lis) << std::endl;
    std::cout <<"Time to process a range of " << lis.size() << " elements with std::list : " << time_list  << "s" << std::endl;

    // Mesure du temps pour le deque
    clock_t start_deq = clock();
    deq = ford_johnson_sort(deq, 1);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;

    // Affichage des résultats
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << time_deq  << "s" << std::endl;



    return EXIT_SUCCESS;
}