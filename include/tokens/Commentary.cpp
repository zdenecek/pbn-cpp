//
// Created by zdnek on 03/03/2023.
//

#include "Commentary.h"

namespace tokens {

    string Commentary::toString() const {
        if(this->format == CommentaryFormat::Semicolon)
            return  ";" + this->content;
        else
            return  "{" + this->content + "}";
    }

    string Commentary::typeName() const {
        if (this->startsOnNewLine) return "Commentary";
        else return "Commentary (inline)";

    }

    Commentary::Commentary(CommentaryFormat format, bool startsOnNewLine, const string &content) : format(format),
                                                                                                   startsOnNewLine(
                                                                                                           startsOnNewLine),
                                                                                                   content(content) {}

} // tokens