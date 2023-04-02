#include "EmptyLine.h"

namespace tokens
{

    void EmptyLine::serialize(std::ostream &) const
    {
        // do nothing
    }

    std::string EmptyLine::getTypeName() const
    {
        return std::string(this->typeName);
    }

    bool EmptyLine::isTag() const
    {
        return false;
    }
}
