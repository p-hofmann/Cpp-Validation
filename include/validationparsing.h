#ifndef VALIDATIONPARSING_LIBRARY_H
#define VALIDATIONPARSING_LIBRARY_H

#include <string>
#include <vector>
#include <map>
#include <exception>
#include "filesystem.h"

namespace Validation
{
    /**
     * A collection of methods for validations:
     *  - file/folder permissions
     *  - file/folder existence
     *  - parsed bool states
     */
    class Parsing
    {
    private:
        /**
         * List of expressions that represent a boolean state
         * TODO: replace with hash-map if available
         */
        static const std::map<std::string, bool> _boolean_expressions;

    public:
        /**
         * Test if a string represent a boolean state
         * @param expression - Boolean expression
         * @return - Is valid expression
         */
        static bool isBooleanExpression(std::string const &expression)
        {
            return _boolean_expressions.find(expression) != _boolean_expressions.end();
        }

        /**
         * Returns boolean state of string expression
         * @param expression - Boolean expression
         * @return - Boolean state of expression
         * @throws - BadValueException
         */
        static bool getBooleanState(std::string const &expression)
        {
            auto result = _boolean_expressions.find(expression);
            if (result == _boolean_expressions.end())
                throw BadValueException();
            return result->second;
        }
    }
}

#endif