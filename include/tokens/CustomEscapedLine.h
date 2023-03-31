#pragma  once

#include "EscapedLine.h"

class CustomEscapedLine : public tokens::EscapedLine {

public:
    std::string content;

    explicit CustomEscapedLine(const std::string &content);

    std::string typeName() const override;

    [[nodiscard]] bool isExport() const override;

    [[nodiscard]] bool isVersion() const override;

    std::string toString() const override;
};

CustomEscapedLine::CustomEscapedLine(const std::string &content) : content(content) {

}

bool CustomEscapedLine::isExport() const {
    return false;
}

bool CustomEscapedLine::isVersion() const {
    return false;
}

std::string CustomEscapedLine::toString() const {
    return tokens::escapeCharacter + this->content;
}

std::string CustomEscapedLine::typeName() const {
    return "Escaped Line";
}

