#pragma once

#include <istream>

#include "PbnFile.h"
#include "Tag.h"
#include "TagFactory.h"

using tokens::TagFactory;

class PbnParser
{

public:
    enum class RecoveryMode
    {
        /**
         * @brief Strict mode. If the parser encounters an error, it will throw an exception.
         */
        Strict,
        /**
         * @brief Relaxed mode, if an error is encountered, the parser will try to recover and parse next tag.
         */
        SkipToNextTag,
        /**
         * @brief Relaxed mode, if an error is encountered, the parser will try to recover and parse next board.
         * If there is no board context and an error is encountered, parser will try to skip and parse next tag.
         */
        SkipToNextBoard
    };

    PbnParser() : PbnParser(RecoveryMode::Strict) {}

    explicit PbnParser(RecoveryMode mode) : mode(mode)
    {
        if (mode != RecoveryMode::Strict)
            throw std::runtime_error("Only strict mode is supported at the moment");
    }

    PbnFile parse(std::istream &inputStream);

private:
    RecoveryMode mode;

    TagFactory tagFactory;

    void parseToken(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);
    std::string parseMultilineComment(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);

    void parseTag(PbnFile &file, std::string &line, std::istream &inputStream, bool startedOnNewLine);
    std::vector<std::string> getTableValues(std::string &line, std::istream &inputStream);
};
