#pragma once

#include "SemanticPbnToken.h"
#include <string>

using namespace std;


class Tag : public SemanticPbnToken {
protected:
    string tagname;
    string content;

public:
    [[nodiscard]] const string &getTagname() const;

    [[nodiscard]] const string &getContent() const;

    string typeName() const override;

    string toString() const override;
};

