#include "TextLine.h"

void tokens::TextLine::serialize(std::ostream& to) const {
    to << this->content;
}

tokens::TextLine::TextLine(const std::string &content) : content(content) {}

std::string tokens::TextLine::getTypeName() const {
    return std::string(this->typeName);
}

bool tokens::TextLine::isTextLine() const {
    return true;
}
