#ifndef DEBUG_DEBUG_UTILS_HPP_
#define DEBUG_DEBUG_UTILS_HPP_

#include <ostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "PbnFile.hpp"

/// @brief This class stores debug utilities
struct Debug
{
    /// @brief Serializes a PbnFile to an output stream include token typeNames.
    /// @param file file to serialize.
    /// @param out stream to serialize the file to.
    static void serializePbnFile(const PbnFile &file, std::ostream &out)
    {

        auto saved_flags = out.flags();
        size_t i = 0;
        for (auto &token : file.getTokens())
        {
            out << std::left
                << std::setw(6) << i
                << std::setw(2) << ": "
                << std::setw(20) << ("<" + token->getTypeName() + ">");
            out.flags(saved_flags);

            token->serialize(out);
            out << "\n";
            i++;
        }

        out.flags(saved_flags);
    }

    /// @brief Prints file BoardContext ranges to the stream.
    static void printBoardContextRanges(const PbnFile &file, std::ostream &out)
    {
        for (auto &context : file.getBoards())
        {
            out << "Board " << context.getBoardNumber() << ": ";
            auto range = file.BoardContextIdToTokenIndex.at(context.id);
            out << "[" << range.StartIndex << ", " << range.StartIndex + range.TokenCount - 1 << "]"
                << "\n";
        }
    }

    // static void playground(const PbnFile &file, std::ostream &out)
    // {
    //     (void)file;
        
    //     (void)out;
    // }
};

#endif // DEBUG_DEBUG_UTILS_HPP_
