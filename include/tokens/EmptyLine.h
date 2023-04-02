#pragma once

#include "SemanticPbnToken.h"
#include <string>
#include <ostream>

namespace tokens
{

    class EmptyLine : public SemanticPbnToken
    {
    public:
        static constexpr std::string_view typeName = "Empty Line";
       
        std::string getTypeName() const override;
        bool isTag() const override;
        void serialize(std::ostream &to) const override;
    };

}
