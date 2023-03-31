#pragma once

#include <string>
#include "SemanticPbnToken.h"



class Tag : public SemanticPbnToken {
protected:
    std::string tagname;
    std::string content;

public:
    Tag(const std::string &tagname, const std::string &content);

    [[nodiscard]] const std::string &getTagname() const;

    [[nodiscard]] const std::string &getContent() const;

    virtual bool isTableTag() const;

    std::string typeName() const override;

    bool isTag() const override;

    std::string toString() const override;
};

