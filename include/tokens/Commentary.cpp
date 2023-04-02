
#include <string>

#include "Commentary.h"

namespace tokens {

    void Commentary::serialize(std::ostream& to) const {
        if(this->format == CommentaryFormat::Semicolon)
            to << ";" << this->content;
        else
            to << "{" << this->content << "}";
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