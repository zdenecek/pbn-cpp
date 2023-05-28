#ifndef TOKENS_CUSTOMESCAPEDLINE_HPP_
#define TOKENS_CUSTOMESCAPEDLINE_HPP_

#include "EscapedLine.hpp"
#include <ostream>
#include <string>

namespace tokens
{
    /// @brief Represents an escaped line which neither an export directive or a version directive
    class CustomEscapedLine : public EscapedLine
    {

    public:
        std::string content;
        static constexpr std::string_view typeName = "Escaped Line";

        explicit CustomEscapedLine(const std::string &content);

        std::string getTypeName() const override;

        [[nodiscard]] bool isExport() const override;
        [[nodiscard]] bool isVersion() const override;

        void serialize(std::ostream &to) const override;
    };

}

#endif // TOKENS_CUSTOMESCAPEDLINE_HPP_
