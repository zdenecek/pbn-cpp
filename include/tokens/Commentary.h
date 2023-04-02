#pragma once

#include <string>
#include <ostream>
#include "SemanticPbnToken.h"

namespace tokens {

    enum class CommentaryFormat {
        Semicolon,
        Brace,
    };

    class Commentary : public SemanticPbnToken {
    public:
        static constexpr std::string_view typeName = "Commentary";
        std::string getTypeName() const override;
        Commentary(CommentaryFormat format, bool startsOnNewLine, const std::string &content);
        void serialize(std::ostream& to) const override;
        bool isCommentary() const override;

        CommentaryFormat format;
        bool startsOnNewLine;
        std::string content;
    };

} // tokens
