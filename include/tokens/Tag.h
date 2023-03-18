#pragma once

#include "SemanticPbnToken.h"
#include <string>

using namespace std;


class Tag : public SemanticPbnToken {
protected:
    string tagname;
    string content;

public:
    Tag(const string &tagname, const string &content);

    [[nodiscard]] const string &getTagname() const;

    [[nodiscard]] const string &getContent() const;

    virtual bool isTableTag() const;

    string typeName() const override;

    bool isTag() const override;

    string toString() const override;
};

