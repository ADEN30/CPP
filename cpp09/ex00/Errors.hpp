#ifndef ERRORS_HPP
#define ERRORS_HPP
#include <cstring>
#include <exception>

class Errors
{
    public :
    class ConstructorErr : public std::exception
    {
        const char* what() const throw()
        {
            return ("Errors constructor ! \nCheck the format of the date");
        }
    };
    class DateErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors format of the date");
        }

    };
    class DateValueErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors the value of the date is wrong");
        }

    };
    class WallErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors the separation format is not availible");
        }

    };
    class LineErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors format of the line, some characters are too many, invalid or missing");
        }

    };
    class ValuetoUpperErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors the value is to upper");
        }

    };
    class ValueNegativeErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors the value is negative");
        }

    };
    class CommaErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors, comma is not found");
        }

    };
    class SpaceErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors, space is not found");
        }

    };
    class FileErr : public std::exception 
    {
        const char* what() const throw()
        {
            return ("Errors, file is not open");
        }

    };
};


#endif