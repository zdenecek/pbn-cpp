#include "PbnInfoPrinter.h"

void PbnInfoPrinter::printOverview(std::string filename, const PbnFile &file, std::ostream &out)
{
    out << "File: " << filename << "\n";
    out << "Boards: ";
    if (file.getBoards().empty())
        out << "None\n";
    else
        out
            << file.getBoards()[0].getBoardNumber()
            << " - "
            << file.getBoards().back().getBoardNumber()
            << " (" << file.getBoards().size() << " boards)"
            << "\n";

    out << "Analyses: No";
}