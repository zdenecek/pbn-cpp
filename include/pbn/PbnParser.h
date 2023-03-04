#pragma once

#include <istream>

#include "PbnFile.h"

using namespace std;

class PbnParser {

public:
    PbnFile parse(istream& inputStream);

private:
    void handleLine(PbnFile& file, const string& line, istream& inputStream);
    void parseMultilineComment(PbnFile &file, const string &line, istream &inputStream, bool startedOnNewLine);
};
