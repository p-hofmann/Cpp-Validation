#include <iostream>
#include "validationfilesystem.h"

using namespace std;
using namespace Validation;

const std::map<std::string, bool> FileSystem::_boolean_expressions = {
        {"0",     false},
        {"1",     true},
        {"f",     false},
        {"t",     true},
        {"false", false},
        {"true",  true},
        {"n",     false},
        {"y",     true},
        {"no",    false},
        {"yes",   true},
        {"off",   false},
        {"on",    true}
};

/**
 * Validate existence and executable permission of file
 * @param filePath - Location of a file
 * @param executable - Expect file to be executable
 * @return - File exists and is executable
 */
bool FileSystem::validateFilePath(std::string filePath, bool executable = false)
{
    if (filePath.empty())
        return false;

    filesystem::path pathFull = filesystem::path(filePath).get_full_path();
    filesystem::path parentPath = pathFull.parent_path();

    if (!parentPath.empty() && !validateDirectoryPath(parentPath.string()))
        return false;

    if (!filesystem::is_regular_file(pathFull))
        return false;

    return !executable || pathFull.is_executabe();
}
