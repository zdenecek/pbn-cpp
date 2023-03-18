
#pragma once

#include "SemanticPbnToken.h"

#include <string>

using namespace  std;

namespace tokens {

class TextLine : public SemanticPbnToken {
protected:
    string content;

public:
    explicit TextLine(const string &content);
    string toString() const override;

    bool isTag() const override;

    string typeName() const override;
};
}
