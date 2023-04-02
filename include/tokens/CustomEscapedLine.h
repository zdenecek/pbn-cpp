#pragma  once

#include "EscapedLine.h"
#include <ostream>
#include <string>

namespace tokens
{
class CustomEscapedLine : public tokens::EscapedLine {

public:
    std::string content;
    static constexpr std::string_view typeName = "Escaped Line";

    explicit CustomEscapedLine(const std::string &content);

    std::string getTypeName() const override;

    [[nodiscard]] bool isExport() const override;

    [[nodiscard]] bool isVersion() const override;

    void serialize(std::ostream& to) const override;
};

CustomEscapedLine::CustomEscapedLine(const std::string &content) : content(content) {

}

bool CustomEscapedLine::isExport() const {
    return false;
}

bool CustomEscapedLine::isVersion() const {
    return false;
}

void CustomEscapedLine::serialize(std::ostream& to) const  {
    to << tokens::escapeCharacter << this->content;
}

std::string CustomEscapedLine::getTypeName() const {
    return std::string(this->typeName);
}

}