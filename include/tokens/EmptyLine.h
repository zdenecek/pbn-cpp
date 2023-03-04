#pragma once

#include "SemanticPbnToken.h"
#include <string>

namespace tokens {


    class EmptyLine : public SemanticPbnToken {
    public:
        string toString() const override;

        string typeName() const override;


    };

}

