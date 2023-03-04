//
// Created by zdnek on 03/03/2023.
//


#pragma once

#include "SemanticPbnToken.h"


namespace tokens {

    enum class CommentaryFormat {
        Semicolon,
        Brace,
    };

    class Commentary : public SemanticPbnToken {
    public:
        string typeName() const override;

        Commentary(CommentaryFormat format, bool startsOnNewLine, const string &content);

    public:
        string toString() const override;


        CommentaryFormat format;
        bool startsOnNewLine;
        string content;
    };

} // tokens
