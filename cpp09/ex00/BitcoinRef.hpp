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
#include "Errors.hpp"

class BitcoinRef
{
    private :
        std::map<time_t, float> _arr;
        std::string _file;
        static bool check_date(std::string &);
        static bool check_format(std::string &, std::string & wall);
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

};

#endif