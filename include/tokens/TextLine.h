
#pragma once

#include "SemanticPbnToken.h"

#include <string>
#include <ostream>


namespace tokens {

class TextLine : public SemanticPbnToken {
protected:
    std::string content;

public:
    explicit TextLine(const std::string &content);
    void serialize(std::ostream& to) const override;

    bool isTag() const override;

    std::string typeName() const override;
};
}
