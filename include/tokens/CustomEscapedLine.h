#pragma once

#include "EscapedLine.h"
#include <ostream>
#include <string>

namespace tokens
{
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