#include "TextLine.h"

std::string tokens::TextLine::toString() const {
    return this->content;
}

tokens::TextLine::TextLine(const std::string &content) : content(content) {}

std::string tokens::TextLine::typeName() const {
    return "Unrecognized Text Line";
}

bool tokens::TextLine::isTag() const {
    return false;
}
