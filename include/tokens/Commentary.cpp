
#include <string>

#include "Commentary.h"

namespace tokens {

    std::string Commentary::toString() const {
        if(this->format == CommentaryFormat::Semicolon)
            return  ";" + this->content;
        else
            return  "{" + this->content + "}";
    }

    std::string Commentary::typeName() const {
        return "Commentary";
    }

    Commentary::Commentary(CommentaryFormat format, bool startsOnNewLine, const std::string &content) : format(format),
                                                                                                   startsOnNewLine(
                                                                                                           startsOnNewLine),
                                                                                                   content(content) {}

    bool Commentary::isTag() const {
        return false;
    }

} // tokens