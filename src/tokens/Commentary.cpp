
#include <string>

#include "Commentary.h"

namespace tokens
{

    void Commentary::serialize(std::ostream &to) const
    {
        if (this->format == CommentaryFormat::Singleline)
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

    Commentary::Commentary(const std::string &content)
    {
        if(std::find(content.begin(), content.end(), '\n') == content.end()) {
            this->format = CommentaryFormat::Singleline;
            this->startsOnNewLine = true;
        } else {
            this->format = CommentaryFormat::Multiline;
            this->startsOnNewLine = false;
        }
    }

    bool Commentary::isCommentary() const
    {
        return true;
    }

} // tokens