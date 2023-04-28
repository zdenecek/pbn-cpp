#include "CustomEscapedLine.hpp"

using namespace tokens;

CustomEscapedLine::CustomEscapedLine(const std::string &content) : content(content)
{
}

bool CustomEscapedLine::isExport() const
{
    return false;
}

bool CustomEscapedLine::isVersion() const
{
    return false;
}

void CustomEscapedLine::serialize(std::ostream &to) const
{
    to << tokens::escapeCharacter << this->content;
}

std::string CustomEscapedLine::getTypeName() const
{
    return std::string(this->typeName);
}