
#ifndef MANIPULATORS_PBNINFOPRINTER_HPP_
#define MANIPULATORS_PBNINFOPRINTER_HPP_

#include "PbnFile.hpp"

#include <string>
#include <vector>
#include <memory>

namespace manipulators
{
    /// @brief Used to execute the --info command.
    class PbnInfoPrinter
    {

    public:
        static void printOverview(std::string filename, const PbnFile &file, std::ostream &out);

        static std::string GetGeneratorInfo(const PbnFile &file);
    };

}

#endif // MANIPULATORS_PBNINFOPRINTER_HPP_
