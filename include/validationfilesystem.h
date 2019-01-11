#ifndef VALIDATIONFILESYSTEM_LIBRARY_H
#define VALIDATIONFILESYSTEM_LIBRARY_H

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
    class FileSystem
    {
    private:

    public:
        /**
         * Validate existence of a directory.
         * @param directoryPath  - Path to directory
         * @return - Directory exists
         */
        static bool validateDirectoryPath(std::string directoryPath)
        {
            filesystem::path tmpPath;
            std::vector<std::string>::iterator stringVectorIt;
            if (directoryPath.empty())
                return false;
            filesystem::path directoryPathFull = root_path(directoryPath);

            /// Validate existence of directory
            return filesystem::is_directory(directoryPathFull);
        }

        /**
         * Validate existence of a directory and optionally sub directories and files there.
         * @param directoryPath  - Path to directory
         * @param subDirectoryNames - List of sub directory names
         * @param fileNames - List of sub file names
         * @return - Directory exists
         */
        static bool
        validateDirectoryContent(std::string directoryPath, std::vector<std::string> *subDirectoryNames = NULL,
                                 std::vector<std::string> *fileNames = NULL)
        {
            filesystem::path tmpPath;
            std::vector<std::string>::iterator stringVectorIt;
            if (directoryPath.empty())
                return false;
            filesystem::path pathFull = root_path(directoryPath);

            /// Validate existence of directory
            if (!filesystem::is_directory(pathFull))
                return false;

            /// Validate existence of directory content
            if (subDirectoryNames != NULL)
                for (stringVectorIt = subDirectoryNames->begin();
                     stringVectorIt < subDirectoryNames->end(); stringVectorIt++)
                {
                    tmpPath = filesystem::path(*stringVectorIt);
                    if (!tmpPath.is_absolute())
                        tmpPath = pathFull / tmpPath;
                    if (!filesystem::is_directory(tmpPath))
                        return false; /// TODO: need better feedback
                }

            /// Validate existence of directory content
            if (fileNames != NULL)
                for (stringVectorIt = fileNames->begin(); stringVectorIt < fileNames->end(); stringVectorIt++)
                {
                    tmpPath = filesystem::path(*stringVectorIt);
                    if (!tmpPath.is_absolute())
                        tmpPath = pathFull / tmpPath;
                    if (!filesystem::is_regular_file(tmpPath))
                        return false; /// TODO: need better feedback
                }

            return true;
        }

        static bool validateFilePath(std::string filePath, bool executable);
    };
}

#endif