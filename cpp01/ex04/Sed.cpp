#include "Sed.hpp"

Sed::Sed(std::string filename)
{
	this->infile = filename;
	this->outfile = filename + ".replace";
}

Sed::~Sed()
{
}

void Sed::replace2(std::string target, std::string str)
{
	std::string start;
	size_t	begin;
	int	end;
	std::ifstream ifs(this->infile.c_str());
	if (!ifs.is_open())
	{
	std::cerr << "Error: can't open the file " << this->infile << std::endl;
		return ;
	}
	std::getline(ifs, start, '\0');
	if (!start.c_str())
	{
		std::cerr << "The file is empty" << std::endl;
		return ;
	}
	ifs.close();
	do {
		begin = start.find(target);
		end = target.length() - 1;
		if (begin != std::string::npos)
		{
			start = start.erase(begin, target.length());
			start.insert(begin, str);
		}
	}
	while (begin != std::string::npos);
	std::ofstream nfile(this->outfile.c_str(), std::ios::out | std::ios::trunc);
	nfile << start;
	nfile.close();
}
	
	
	
	
