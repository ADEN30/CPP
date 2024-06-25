#include "SortMerge.hpp"

void SortMerge::sort(std::list<size_t> & src)
{
    if (src.size() <= 1)
        return ;
    std::list<size_t> _arrleft;
    std::list<size_t> _arrright;
    it _its = src.begin();
    size_t i = 0;
    while(_its != src.end())
    {
        if (i < src.size() / 2)
            _arrleft.push_back(*_its);
        else
            _arrright.push_back(*_its);
        _its++;
        i++;
    }
    sort(_arrleft);
    sort(_arrright);
    merge(_arrleft, _arrright, src);
}

void SortMerge::sort(std::deque<size_t> & src)
{
    if (src.size() <= 1)
        return ;
    std::deque<size_t> _arrleft;
    std::deque<size_t> _arrright;
    iter _its = src.begin();
    size_t i = 0;
    while(_its != src.end())
    {
        if (i < src.size() / 2)
            _arrleft.push_back(*_its);
        else
            _arrright.push_back(*_its);
        _its++;
        i++;
    }
    sort(_arrleft);
    sort(_arrright);
    merge(_arrleft, _arrright, src);
}


void SortMerge::merge(std::list<size_t>& left, std::list<size_t>& right, std::list<size_t>& arr)
{
    arr.clear();
    it _itl = left.begin();
    it _itr = right.begin();
    while (_itl != left.end() && _itr != right.end())
    {
        if (*_itl < *_itr)
        {
            arr.push_back(*_itl);
            _itl++;
        }
        else
        {
            arr.push_back(*_itr);
            _itr++;
        }
    }
    while (_itl != left.end())
    {
        arr.push_back(*_itl);
        _itl++;
    }
    while (_itr != right.end())
    {
        arr.push_back(*_itr);
        _itr++;
    }
}

void SortMerge::merge(std::deque<size_t>& left, std::deque<size_t>& right, std::deque<size_t>& arr)
{
    arr.clear();
    iter _itl = left.begin();
    iter _itr = right.begin();
    while (_itl != left.end() && _itr != right.end())
    {
        if (*_itl < *_itr)
        {
            arr.push_back(*_itl);
            _itl++;
        }
        else
        {
            arr.push_back(*_itr);
            _itr++;
        }
    }
    while (_itl != left.end())
    {
        arr.push_back(*_itl);
        _itl++;
    }
    while (_itr != right.end())
    {
        arr.push_back(*_itr);
        _itr++;
    }
}


std::ostream& operator<<(std::ostream& f, std::deque<size_t> &src)
{
    for (iter i = src.begin(); i != src.end(); i++)
    {
        f << *i << " ";
    }
    return (f);
}