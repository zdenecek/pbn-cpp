#pragma once

#include <string>


class SemanticPbnToken {
public:
    virtual ~SemanticPbnToken() noexcept = default;

    virtual std::string toString() const = 0;
    virtual std::string typeName() const = 0;

    virtual bool isTag() const = 0;

};

