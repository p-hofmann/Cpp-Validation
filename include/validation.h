#ifndef VALIDATION_LIBRARY_H
#define VALIDATION_LIBRARY_H

#include <string>
#include <vector>
#include <map>
#include <exception>
#include "filesystem.h"

namespace Validation
{
    class BadValueException : public std::exception
    {
        const char * what () const throw ()
        {
            return "Invalid Value!";
        }
//        int _line;
//        const char *_file;
//        const char *_func;
//        const char *_info;
//
//    public:
//        BadValueException(const char *msg, const char *file, int line, const char *func, const char *info = "")
//                : std::exception(msg), _file(file), _line(line), _func(func), _info(info) {}
//        BadValueException(const char *msg)
//                : std::exception(msg), _file(""), _line(-1), _func(""), _info("") {}
//
//        const char *get_file() const { return _file; }
//        int get_line() const { return _line; }
//        const char *get_func() const { return _func; }
//        const char *get_info() const { return _info; }
    };

#endif