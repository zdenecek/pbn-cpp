#pragma once

#include <string>
#include <ostream>

namespace tokens
{
class SemanticPbnToken {
public:
    virtual ~SemanticPbnToken() noexcept = default;

    std::string toString() const;
    
    virtual void serialize(std::ostream& to) const = 0;
    virtual std::string getTypeName() const = 0;

    virtual bool isTag() const { return false; };
    virtual bool isCommentary() const { return false; };
    virtual bool isEscapedLine() const { return false; };
    virtual bool isTextLine() const { return false; };
};

}