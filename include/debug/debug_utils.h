#pragma once

#include <ostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "PbnFile.h"

struct Debug
{

    static void serializePbnFile(const PbnFile &file, std::ostream &out)
    {

        auto saved_flags = out.flags();
        size_t i = 0;
        for (auto &token : file.getTokens())
        {
            out << std::left
                << std::setw(6) << i
                << std::setw(2) << ": "
                 << std::setw(20) << ("<" + token->typeName() + ">");
            out.flags(saved_flags);

            token->serialize(out);
            out << "\n";
            i++;
        }

        out.flags(saved_flags);
    }

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

    static void playground(const PbnFile &file, std::ostream &out) {

    }
};