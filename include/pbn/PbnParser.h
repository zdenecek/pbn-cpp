#pragma once

#include <istream>

#include "PbnFile.h"
#include "Tag.h"
#include "TagFactory.h"

using namespace std;

class PbnParser {

public:
    PbnFile parse(istream& inputStream);

private:

    TagFactory tagFactory;

    void parseToken(PbnFile &file, string &line, istream &inputStream, bool startedOnNewLine);
    string parseMultilineComment(PbnFile &file,  string &line, istream &inputStream, bool startedOnNewLine);

    void parseTag(PbnFile &file, string &line, istream &inputStream, bool startedOnNewLine);
    vector<string> getTableValues(PbnFile &file,  string &line, istream &inputStream);


};
