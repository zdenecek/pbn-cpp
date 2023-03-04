#pragma  once

#include "EscapedLine.h"

class CustomEscapedLine : public tokens::EscapedLine {

public:
    string content;

    explicit CustomEscapedLine(const string &content);

    string typeName() const override;

    [[nodiscard]] bool isExport() const override;

    [[nodiscard]] bool isVersion() const override;

    string toString() const override;
};

CustomEscapedLine::CustomEscapedLine(const string &content) : content(content) {

}

bool CustomEscapedLine::isExport() const {
    return false;
}

bool CustomEscapedLine::isVersion() const {
    return false;
}

string CustomEscapedLine::toString() const {
    return tokens::escapeCharacter + this->content;
}

string CustomEscapedLine::typeName() const {
    return "Escaped Line";
}

