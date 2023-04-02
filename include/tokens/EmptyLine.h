#pragma once

#include "SemanticPbnToken.h"
#include <string>
#include <ostream>

namespace tokens {


    class EmptyLine : public SemanticPbnToken {
    public:
        void serialize(std::ostream& to) const override;
        std::string typeName() const override;

        bool isTag() const override;

    };

}

