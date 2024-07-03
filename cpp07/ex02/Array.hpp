#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
template<typename T>
class Array
{
    private:
        T* _tab;
		unsigned int _size;
    
    public:
		Array() : _tab(new T[0]), _size(0){}
		Array(unsigned int n) : _tab(new T[n]), _size(n){}
		Array(const Array<T>& src) : _tab(new T[src._size]), _size(src._size)
		{
		    for (unsigned int i = 0; i < _size; ++i)
		    {
		        _tab[i] = src._tab[i];
		    }
		}
		T& operator[](unsigned int i) const
		{
			if (i >= _size)
				throw OutOfBounds();
			else
				return (_tab[i]);
		}
		Array& operator=(const Array& rhs)
		{
			if (&rhs == this)
				return (*this);
			delete [] _tab;
			_tab = new T(rhs.size());
			_size = rhs.size();
			for(unsigned int i(0); i < rhs.size(); i++)
			{
				_tab[i] = rhs[i];
			}
			return (*this);
		}
		unsigned int size() const { return (_size); }
		~Array() {delete []_tab; }
		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw() { return ("Index out of bouds");}
		};

};

template<typename T>
std::ostream& operator<<(std::ostream & f, const Array<T>& src)
{
	for(unsigned int i = 0; i < src.size(); i++)
	{ f << src[i] << " "; }
	return (f);
};

#endif