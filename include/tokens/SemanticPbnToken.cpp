#include "SemanticPbnToken.h"

#include <sstream>

std::string SemanticPbnToken::toString() const
{
    std::stringstream ss;
    this->serialize(ss);
    return ss.str();
}