
#pragma once

#include "SemanticPbnToken.hpp"

#include <string>
#include <ostream>


namespace tokens
{
    /// @brief Represents a text line as an unrecognized token. Not permitted by the specification. Internal use.
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
