
#pragma once

#include "SemanticPbnToken.h"

#include <string>

namespace tokens {

class TextLine : public SemanticPbnToken {
protected:
    std::string content;

public:
    explicit TextLine(const std::string &content);
    std::string toString() const override;

    bool isTag() const override;

    std::string typeName() const override;
};
}
