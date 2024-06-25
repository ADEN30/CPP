#ifndef SORTMERGE_HPP
#define SORTMERGE_HPP

#include <iostream>
#include <deque>
#include <cstdlib>
#include <list>
#include <ctime>
typedef std::list<size_t>::iterator it;
typedef typename std::deque<size_t>::iterator iter;

std::ostream& operator<<(std::ostream& f, std::deque<size_t> &src);
class SortMerge
{

    public:
        static void sort(std::list<size_t>&);
        static void sort(std::deque<size_t>&);
        static void merge(std::list<size_t>&, std::list<size_t>& , std::list<size_t>&);
        static void merge(std::deque<size_t>&, std::deque<size_t>& , std::deque<size_t>&);

};




#endif