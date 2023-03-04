#pragma once

#include <string>

using namespace std;

class SemanticPbnToken {
public:
    virtual ~SemanticPbnToken() noexcept = default;

    virtual string toString() const = 0;
    virtual string typeName() const = 0;

};

