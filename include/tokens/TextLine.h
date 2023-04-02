
#pragma once

#include "SemanticPbnToken.h"

#include <string>
#include <ostream>

namespace tokens
{

    class TextLine : public SemanticPbnToken
    {
    protected:
        std::string content;

    public:
        explicit TextLine(const std::string &content);
        static constexpr std::string_view typeName = "Unrecognized Text Line";
        bool isTextLine() const override;
        void serialize(std::ostream &to) const override;

        std::string getTypeName() const override;
    };
}
