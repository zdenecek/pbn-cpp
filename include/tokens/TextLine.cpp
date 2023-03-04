#include "TextLine.h"

string tokens::TextLine::toString() const {
    return this->content;
}

tokens::TextLine::TextLine(const string &content) : content(content) {}

string tokens::TextLine::typeName() const {
    return "Unrecognized Text Line";
}
