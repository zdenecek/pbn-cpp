
#pragma once

#include "PbnFile.h"

#include <string>
#include <vector>
#include <memory>


class PbnInfoPrinter {

public:
    static void printOverview(std::string filename, const PbnFile &file, std::ostream &out);
}