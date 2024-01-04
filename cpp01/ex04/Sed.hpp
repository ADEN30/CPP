#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <cstring>
class	Sed
{
	private:
		std::string infile;
		std::string outfile;
	public:
		Sed(std::string filename);
		~Sed();
	void	replace2(std::string target, std::string str);
};

#endif
