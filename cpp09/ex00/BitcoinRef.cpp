#include "BitcoinRef.hpp"

BitcoinRef::BitcoinRef(std::string & file) : _file(file)
{
    std::string _str;
    std::ifstream in("./cpp_09/data.csv", std::ios::in);

    if (!in.is_open())
        throw BitcoinRef::FileErr();
    std::getline(in, _str);
    while (std::getline(in, _str))
    {
        try
        {
            if (!BitcoinRef::check_date(_str))
                throw (BitcoinRef::ConstructorErr());
            _arr.insert(std::pair<time_t, float>(BitcoinRef::build_key(_str, ','), BitcoinRef::search_value(_str, ",")));
        }
        catch( const std::exception & e)
        {
            std::cerr << e.what() << '\n';
        } 
    }
    in.close();

}
/*Check format of the date*/
bool    BitcoinRef::check_date(std::string & str)
{
    unsigned int _i = 0;
    int _count = 0;

    while ((std::isdigit(str[_i]) && _i < str.size()) || (str[_i] == '-' && (_i) > 0 && std::isdigit(str[_i - 1])))
    {
       if (str[_i] != '-')
            _count++;
        _i++;
    }
    if (_count != 8)
        throw BitcoinRef::DateErr();
    
    return (1);
}

bool BitcoinRef::check_format(std::string & str, std::string & wall)
{
    size_t _index = str.find(wall, 0);
    int _dot = 0;

    if (_index == std::string::npos)
        throw BitcoinRef::WallErr();
    _index += wall.size();
    while((str[_index] == '.' && _dot <= 1) || (std::isdigit(str[_index]) && _index < str.size()))
    {
        if (str[_index] == '.')
            _dot++;
        _index++;
    }
    if (str[_index] == '-')
        throw BitcoinRef::ValueNegativeErr();
    if (_index < str.size())
        throw BitcoinRef::LineErr();
    return (1);
}

float BitcoinRef::search_value(std::string & str, std::string c)
{
    size_t _index;
    float _value;

    _index = str.find(c, 0); 
    if (_index == std::string::npos)
        throw BitcoinRef::WallErr();
    std::string _sub = str.substr(_index + c.size(), str.size() - 1);
    _value = std::strtof(_sub.c_str(), 0);
    if (_value > 1000 && c == " | ")
        throw BitcoinRef::ValuetoUpperErr();
    else if (_value < 0 && c == " | ")
        throw BitcoinRef::ValueNegativeErr();
    else
        return (_value);
}

time_t BitcoinRef::build_key(std::string & str, char c)
{
    size_t _index;
    size_t* _tab;
    time_t _time;

    _index = str.find(c, 0);
    if (_index != std::string::npos)
    {
        std::string _lft = str.substr(0, _index);
        _tab = dateTosize_t(_lft);
        _time = BitcoinRef::dateToSeconde(_tab[0], _tab[1], _tab[2]);
        delete []_tab;
        return (_time);

    }
    if (c == ',')
        throw BitcoinRef::CommaErr();
    else
        throw BitcoinRef::SpaceErr();
}

size_t* BitcoinRef::dateTosize_t(std::string & str)
{
    std::string::size_type it;
    std::string _sub;
    size_t* _date = new size_t(3);

    try
    {
        it = str.find('-', 0);
        if (it == std::string::npos)
            throw BitcoinRef::DateErr() ;
        _sub = str.substr(0, it);
        _date[0] = std::strtoul(_sub.c_str(), 0, 10);

        it = str.find('-', it + 1);
        if (it == std::string::npos)
            throw BitcoinRef::DateErr() ;
        _sub = str.substr(it - 2, it);
        _date[1] = std::strtoul(_sub.c_str(), 0, 10);
        _sub = str.substr(it+1, str.size());
        _date[2] = std::strtoul(_sub.c_str(), 0, 10);
        return (_date);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    throw BitcoinRef::DateErr();
}

// Fonction pour vérifier si une année est bissextile
bool is_leap_year(size_t year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true; // Divisible par 400 : bissextile
            } else {
                return false; // Divisible par 100 mais pas par 400 : non bissextile
            }
        } else {
            return true; // Divisible par 4 mais pas par 100 : bissextile
        }
    }
    return false; // Non divisible par 4 : non bissextile
}


void get_current_date(size_t& year, size_t& month, size_t& day) {
    // Obtenir l'heure actuelle
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    // Extraire l'année, le mois et le jour
    year = static_cast<size_t>(now->tm_year + 1900);
    month = static_cast<size_t>(now->tm_mon + 1);
    day = static_cast<size_t>(now->tm_mday);
}

time_t BitcoinRef::dateToSeconde(size_t year, size_t month, size_t day)
{
    struct tm timeinfo;
    size_t current_year, current_month, current_day = 0;
    size_t lim_day;

    get_current_date(current_year, current_month, current_day);

    if (is_leap_year(year) && month == 2)
        lim_day = 29;
    else if (month == 2)
        lim_day = 28;
    else if ((month % 2 == 0 && month <= 7) || (month % 2 == 1 && month > 7))
        lim_day = 30;
    else
        lim_day = 31;


    if (month > 12 ||  month < 1 || day > lim_day || day < 1 || year < 2009 || current_year < year)
    {
        std::cout << year << " " << month << " " << lim_day << std::endl;
        throw BitcoinRef::DateValueErr(year, month, day);
    }
    else if (current_year == year && current_month < month)
        throw BitcoinRef::DateValueErr(year, month, day);
    else if (current_year == year && current_month == month && current_day < day )
        throw BitcoinRef::DateValueErr(year, month, day);


    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday= day + 1;
    timeinfo.tm_hour = 1;
    timeinfo.tm_min = 1;
    timeinfo.tm_sec = 1;

    time_t _date = mktime(&timeinfo);
    if (_date == -1)
        throw (-1);

    return (_date);
}

void BitcoinRef::scale_bitcoin()
{
    std::ifstream _in(_file.c_str(), std::ios::in);
    std::string _str;
    std::string _sep = " | ";

    if (!_in.is_open())
        throw BitcoinRef::FileErr();
    while (std::getline(_in, _str))
    {
        try
        {
            check_date(_str);
            check_format(_str, _sep);
            time_t _t = BitcoinRef::build_key(_str, ' ');
            this->found_key(_t, _str);
        }
        catch(const std::exception & e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    _in.close();
}

void BitcoinRef::findprev_date(time_t & key, std::string & str)
{
    time_t _diff;

    std::map<time_t, float>::iterator it;
    std::map<time_t, float>::iterator tmp;
    it = _arr.begin();
    _diff = it->first;
    while( it != _arr.end())
    {
        if (key - it->first > 0)
        {
            if (_diff > key - it->first)
            {
                _diff = key - it->first;
                tmp = it;
            }
        }
        ++it;
    }
    BitcoinRef::utc(key);
    std::cout << " => " << BitcoinRef::search_value(str, " | ") << " = " << BitcoinRef::search_value(str, " | ") * tmp->second << std::endl;
}

void BitcoinRef::utc(time_t & time)
{
    char timeString[11] = "yyyy-mm-dd";
    std::strftime(timeString, 11, "%FT%TZ", std::gmtime(&time));
    std::cout << timeString;
}

void BitcoinRef::found_key(time_t & key, std::string &str)
{
    std::map<time_t, float>::iterator it;
    it = _arr.begin();
    float value_init = 0.0;
    while( it != _arr.end())
    {
        if (it->first == key)
        {
            value_init = BitcoinRef::search_value(str, " | ");
            BitcoinRef::utc((key));
            std::cout << " => " << value_init << " = " << value_init * it->second << std::endl;
            return ;
        }
        ++it;
    }
    BitcoinRef::findprev_date(key, str);
}

BitcoinRef::~BitcoinRef(){}


const char* BitcoinRef::ConstructorErr::what() const throw()
{
    return ("Errors constructor ! \nCheck the format of the date");
}

const char* BitcoinRef::DateErr::what() const throw()
{
    return ("Errors format of the date");
}

BitcoinRef::DateValueErr::DateValueErr(size_t &annee, size_t &mois, size_t &jour) : year(annee), month(mois), day(jour){}

const char* BitcoinRef::DateValueErr::what() const throw()
{
    std::ostringstream oss;

    oss << "Errors: bad input => ";
    oss << year;
    oss << '-';
    oss << month;
    oss << '-';
    oss << day;
    std::string err = oss.str();
    char* ret = new char(err.size() + 1);
    std::strcpy(ret, err.c_str());
    return (ret);
}

const char* BitcoinRef::WallErr::what() const throw()
{
    return ("Errors the separation format is not availible");
}

const char* BitcoinRef::LineErr::what() const throw()
{
    return ("Errors format of the line, some characters are too many, invalid or missing");
}

const char* BitcoinRef::ValuetoUpperErr::what() const throw()
{
    return ("Errors: too large number.");
}

const char* BitcoinRef::ValueNegativeErr::what() const throw()
{
    return ("Errors: not a positive number.");
}

const char* BitcoinRef::CommaErr::what() const throw()
{
    return ("Errors, comma is not found");
}

const char* BitcoinRef::SpaceErr::what() const throw()
{
    return ("Errors, space is not found");
}

const char* BitcoinRef::FileErr::what() const throw()
{
    return ("Error: could not open file.");
}