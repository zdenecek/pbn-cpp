#include "EmptyLine.h"

namespace tokens {

    string EmptyLine::toString() const {
        return std::string();
    }

    string EmptyLine::typeName() const {
        return "Empty Line";
    }

    bool EmptyLine::isTag() const {
        return false;
    }
}

