#ifndef BITCOIN_REF
#define BITCOIN_REF
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <exception>
#include <sstream>

class BitcoinRef
{
    private :
        std::map<time_t, float> _arr;
        std::string _file;
        static void isValidFormatInputFile(std::string );
        static float search_value(std::string &, std::string );
        static time_t build_key(std::string &, char );
        void findprev_date(time_t &, std::string &);
    
    public :
        static void utc(time_t& );
        BitcoinRef(std::string &);
        static size_t* dateTosize_t(std::string &);
        static time_t dateToSeconde(size_t, size_t, size_t);
        void scale_bitcoin();
        void found_key(time_t &, std::string &);
        ~BitcoinRef();

    class ConstructorErr : public std::exception
    {
        const char* what() const throw();
    };
    class DateValueErr : public std::exception 
    {
        private:
        size_t year;
        size_t month;
        size_t day;

        public:
        DateValueErr(size_t &annee, size_t &mois, size_t &jour);
        const std::string DateErr();

    };
    class WallErr : public std::exception 
    {
        const char* what() const throw();

    };
    class LineErr : public std::exception 
    {
		private:
			std::string str;
		public:
			LineErr(std::string & line);
			~LineErr() throw();
        	const std::string Line();

    };
    class ValuetoUpperErr : public std::exception 
    {
        const char* what() const throw();

    };
    class ValueNegativeErr : public std::exception 
    {
        const char* what() const throw();

    };
    class FileErr : public std::exception 
    {
        const char* what() const throw();

    };

};

#endif