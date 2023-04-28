#include "SemanticPbnToken.hpp"

#include <sstream>

namespace tokens
{

    std::string SemanticPbnToken::toString() const
    {
        std::stringstream ss;
        this->serialize(ss);
        return ss.str();
    }

}