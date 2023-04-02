#pragma  once

#include "EscapedLine.h"
#include <ostream>
#include <string>


class CustomEscapedLine : public tokens::EscapedLine {

public:
    std::string content;

    explicit CustomEscapedLine(const std::string &content);

    std::string typeName() const override;

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

std::string CustomEscapedLine::typeName() const {
    return "Escaped Line";
}

