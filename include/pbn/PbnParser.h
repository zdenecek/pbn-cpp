#pragma once

#include <istream>

#include "PbnFile.h"
#include "Tag.h"
#include "TagFactory.h"


class PbnParser {

public:
    PbnFile parse(std::istream& inputStream);

private:

    TagFactory tagFactory;

    void parseToken(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);
    std::string parseMultilineComment(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);

    void parseTag(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);
    std::vector<std::string> getTableValues(PbnFile &file, std::string &line, std::istream &inputStream);

};
