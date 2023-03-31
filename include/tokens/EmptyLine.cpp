#include "EmptyLine.h"

namespace tokens {

    std::string EmptyLine::toString() const {
        return std::string();
    }

    std::string EmptyLine::typeName() const {
        return "Empty Line";
    }

    bool EmptyLine::isTag() const {
        return false;
    }
}

