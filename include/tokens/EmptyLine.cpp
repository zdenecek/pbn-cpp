#include "EmptyLine.h"

namespace tokens {

    void EmptyLine::serialize(std::ostream&) const {
        // do nothing
    }

    std::string EmptyLine::typeName() const {
        return "Empty Line";
    }

    bool EmptyLine::isTag() const {
        return false;
    }
}

