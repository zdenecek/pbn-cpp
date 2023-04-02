
#include <string>

#include "Commentary.h"

namespace tokens
{

    void Commentary::serialize(std::ostream &to) const
    {
        if (this->format == CommentaryFormat::Semicolon)
            to << ";" << this->content;
        else
            to << "{" << this->content << "}";
    }

    std::string Commentary::getTypeName() const
    {
        return std::string(this->typeName);
    }

    Commentary::Commentary(CommentaryFormat format, bool startsOnNewLine, const std::string &content) : format(format),
                                                                                                        startsOnNewLine(
                                                                                                            startsOnNewLine),
                                                                                                        content(content) {}

    bool Commentary::isCommentary() const
    {
        return true;
    }

} // tokens