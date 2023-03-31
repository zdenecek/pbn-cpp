#pragma once

#include <string>
#include "SemanticPbnToken.h"

namespace tokens {

    enum class CommentaryFormat {
        Semicolon,
        Brace,
    };

    class Commentary : public SemanticPbnToken {
    public:
        std::string typeName() const override;
        Commentary(CommentaryFormat format, bool startsOnNewLine, const std::string &content);
        std::string toString() const override;

        bool isTag() const override;

        CommentaryFormat format;
        bool startsOnNewLine;
        std::string content;
    };

} // tokens
