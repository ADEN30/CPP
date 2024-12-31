#ifndef SORTMERGE_HPP
#define SORTMERGE_HPP

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

void print_colored(const std::string& text, const std::string& color);
std::deque<size_t> compute_group_sizes(size_t n);

template <typename Container>
size_t return_offset_to_insert_element(Container &tab_of_groups)
{
	size_t total = 0;

	for (typename Container::iterator i = tab_of_groups.begin(); i < tab_of_groups.end(); i++)
	{
		total += *i;		
	}	
	return (total);
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
void sort_pairs_increase(Container& element) {
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
            if (*second < *first) {
                // std::cout << "swap" << std::endl;
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
}

template <typename Container>
void sort_pairs_decreasing(Container& element) {
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
            if (*second > *first) {
                // std::cout << "swap" << std::endl;
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
}


template <typename Container>
void copy_src_in_dest(Container &src, Container &dest)
{
	typename Container::iterator it_src = src.begin();
	
	while (it_src != src.end())
	{
		dest.push_back(*it_src);
		it_src = src.erase(it_src);
	}
}


template <typename Container>
void complete_pend(Container &pend, Container &main_chain, size_t size_element)
{
	typename Container::iterator it_main_chain = main_chain.begin();
	size_t count = 0;

	while (it_main_chain != main_chain.end())
	{
		if(count % 2 != 0 && count > 1)
		{
			std::advance(it_main_chain, -size_element);
			for (size_t i = 0; i < size_element && it_main_chain != main_chain.end(); i++)
			{
				pend.push_back(*it_main_chain);
				it_main_chain = main_chain.erase(it_main_chain);
			}
		}
		
		count++;
		for (size_t i = 0; it_main_chain != main_chain.end() && i < size_element ; i++, it_main_chain++);
		
	}
}


template <typename Container>
typename Container::iterator insert_binary(Container &main_chain, Container &pend, size_t size_element, typename Container::iterator lim_search)
{
	typename Container::iterator it_main_chain = main_chain.begin();
	typename Container::iterator it_pend = pend.begin();
	(void)lim_search;
	if(size_element > pend.size())
		return (main_chain.end());
	for (size_t i = 0; i < (size_element - 1) && it_pend != pend.end(); i++, it_pend++);
	for (size_t i = 0; i < (size_element - 1) && it_main_chain != lim_search; i++, it_main_chain++);	

	if (size_element == 1)
		lim_search = main_chain.end();
	while(it_main_chain != lim_search && it_pend != pend.end())
	{

		if (*it_pend > *it_main_chain)	
		{
			//std::cout << "tagrget 1 = " << *it_main_chain << std::endl;
			for (size_t i = 0; i < size_element && it_main_chain != lim_search; i++, it_main_chain++);	
			//std::cout << "tagrget 2 = " << *it_main_chain << std::endl;
			if (*it_pend < *it_main_chain)
			{
				//std::advance(it_pend, -size_element + 1);
				std::advance(it_main_chain, -size_element + 1);
				for (size_t i = 0; i < (size_element); i++)
				{
					it_main_chain = main_chain.insert(it_main_chain, *it_pend);
					it_pend = pend.erase(it_pend);
					if(it_pend != pend.begin())
						it_pend--;
				}
				return (it_main_chain);	
			}
		}
		else
			for (size_t i = 0; i < size_element && it_main_chain != lim_search; i++, it_main_chain++);	
	}

	it_pend = pend.begin();
	it_main_chain = main_chain.begin();
	std::advance(it_pend, size_element - 1);
	std::advance(it_main_chain, size_element - 1);
	
	if (*it_pend <  *it_main_chain)
	{

		for (size_t i = size_element; i > 0; i--)
		{
			main_chain.push_front(*it_pend);
			it_pend = pend.erase(it_pend);
			if (it_pend != pend.begin())
				it_pend--;
		}
		return (main_chain.begin());
	}
	else
	{
		it_pend = pend.begin();
		for (size_t i = size_element; i > 0; i--)
		{
			main_chain.push_back(*it_pend);
			it_pend = pend.erase(it_pend);
			if (it_pend != pend.begin())
				it_pend--;
		}
		return (main_chain.end());
	}	
	
}


template <typename Container>
Container group_to_insert(Container &pend, std::deque<size_t> &tab, size_t size_element)
{
	Container group;
	Container tmp_group;
	Container merge_group;

	std::deque<size_t>::iterator it_tab = tab.begin();
	typename Container::iterator it_pend = pend.begin();

	if(pend.size() <= size_element)
		return pend;
	std::advance(it_pend, (*it_tab * size_element) - 1);
	for (size_t i = 0; i < *it_tab ; i++)
	{
		for (size_t j = 0; j < size_element; j++)
		{
		
			tmp_group.push_front(*it_pend);
			it_pend = pend.erase(it_pend);
			if (it_pend != pend.begin())
				it_pend--;
		}
		typename Container::iterator it_tmp_group = tmp_group.begin();
		for (size_t j = 0; j < size_element; j++)
		{
			group.push_back(*it_tmp_group);
			it_tmp_group = tmp_group.erase(it_tmp_group);
		}
		
	}

	it_tab = tab.erase(it_tab);
	return (group);
	
}

template <typename Container>
Container ford_johnson_sort(Container& container, size_t nb_boucle) {
    // Vérification de la condition d'arrêt : taille <= 1 ou non divisible par nb_boucle
    if (container.size() <= 1 || container.size() / nb_boucle < 1) {
        return container;  // Retourner le conteneur tel quel si la taille n'est pas divisible par nb_boucle
	}

    // Diviser le conteneur en paires
    Container main_chain;
	Container pend;
	Container odd;
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
        sort_pairs_increase(tmp);


        // Ajouter les éléments triés dans main_chain
        for (typename std::list<int>::iterator i = tmp.begin(); i != tmp.end(); ++i) {
            main_chain.push_back(*i);
        }
    }
		// Si on a un reste dans  container
		copy_src_in_dest(container, main_chain);

    // Appel récursif si la taille de main_chain est encore divisible par nb_boucle
    if (main_chain.size() / (nb_boucle) > 1) {
        main_chain = ford_johnson_sort(main_chain, nb_boucle*2);
	}
	
		//Build odd
		for (size_t i = main_chain.size() % (nb_boucle * 2); i > 0 ; i--)
		{
			typename Container::iterator it_main = main_chain.end();
			std::advance(it_main, -1);
			odd.push_front(*it_main);
			it_main = main_chain.erase(it_main);
		}
		
		// Build pend
		complete_pend(pend, main_chain, nb_boucle);

		// Insert Pend
		std::deque<size_t> group_jacobsthal = compute_group_sizes((pend.size() / nb_boucle));
		size_t nb_group_jacobsthal = group_jacobsthal.size();
		size_t nb_pairs = return_offset_to_insert_element(group_jacobsthal);
		
		

		for (size_t i = 0; i < nb_group_jacobsthal; i++)
		{
			typename Container::iterator it_old = main_chain.end();
			size_t keep_jacobsthal_nb = *group_jacobsthal.begin(); 


			Container tmp_group_pend =  group_to_insert(pend, group_jacobsthal, nb_boucle);

			// insert all element of the group jacobsthal
			size_t nb_element_to_insert = tmp_group_pend.size() / (nb_boucle);
			for (size_t j = 0; j < nb_element_to_insert; j++)
			{
				it_old = main_chain.end();
				std::advance(it_old, -static_cast<long long>((nb_pairs + j - keep_jacobsthal_nb) * nb_boucle));
				insert_binary(main_chain, tmp_group_pend, nb_boucle, it_old);
				nb_pairs -= 1;
			}
		}

		//Insert odd	

		size_t insert_n_group_by_odd = odd.size() / (nb_boucle);
		typename Container::iterator it_old = main_chain.end();

		for (size_t i = 0; i < insert_n_group_by_odd; i++)
		{
			insert_binary(main_chain, odd, nb_boucle, it_old);
		}
		// Copy odd 
		copy_src_in_dest(odd, main_chain );


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


#endif