#pragma once

#include <string>
#include <ostream>

class SemanticPbnToken {
public:
    virtual ~SemanticPbnToken() noexcept = default;

    std::string toString() const;
    
    virtual void serialize(std::ostream& to) const = 0;
    virtual std::string typeName() const = 0;

    virtual bool isTag() const = 0;
};

