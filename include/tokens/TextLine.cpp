#include "TextLine.h"

void tokens::TextLine::serialize(std::ostream& to) const {
    to << this->content;
}

tokens::TextLine::TextLine(const std::string &content) : content(content) {}

std::string tokens::TextLine::typeName() const {
    return "Unrecognized Text Line";
}

bool tokens::TextLine::isTag() const {
    return false;
}
