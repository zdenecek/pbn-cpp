#pragma once

#include "SemanticPbnToken.h"
#include <string>

namespace tokens {


    class EmptyLine : public SemanticPbnToken {
    public:
        std::string toString() const override;
        std::string typeName() const override;

        bool isTag() const override;

    };

}

