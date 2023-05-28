#ifndef PBN_PBNPARSER_HPP_
#define PBN_PBNPARSER_HPP_

#include <istream>
#include <optional>

#include "PbnFile.hpp"
#include "Tag.hpp"
#include "TagFactory.hpp"
#include "SemanticPbnToken.hpp"
#include "Commentary.hpp"

/// @brief Class used to parse a pbn file from an input stream.
class PbnParser
{

public:

    /// @brief Represents the recovery mode of the parser, what it should do when a lexical or syntactical error is encountered
    /// @see PbnParser::PbnParser(RecoveryMode mode)
    /// Only strict mode is supported at the moment
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

    /// @brief Parser a pbn file from input stream.
    PbnFile parse(std::istream &inputStream);

    /// @brief Parse a token from the given line, or more lines.
    /// If the line is not consumed completely by the parser, line contents will be updated to contain the remaining
    /// part of the line. If the line is consumed completely, line will be empty on return.
    /// @param line Line to parse from.
    /// @param inputStream Input stream to get more lines from, if necessary.
    /// @param startedOnNewLine True if line is a line from the original file. False if line is a continuation of a previous line, a part of it being already parsed.
    /// @throw std::runtime_error if the parser encounters an error and the recovery mode is set to strict.
    /// @return unique_ptr to the parsed token
    std::unique_ptr<tokens::SemanticPbnToken> parseToken(std::string &line, std::istream &inputStream, bool startedOnNewLine);

private:
    RecoveryMode mode;

    size_t curr_line = 0;
    
    std::istream & getline(std::istream &inputStream, std::string &line);

    tokens::TagFactory tagFactory;

    std::unique_ptr<tokens::Commentary> parseMultilineComment(std::string &line, std::istream &inputStream, bool startedOnNewLine);

    std::unique_ptr<tokens::Tag> parseTag(std::string &line, std::istream &inputStream, bool startedOnNewLine);
    std::vector<std::string> getTableValues(std::string &line, std::istream &inputStream);
};

#endif // PBN_PBNPARSER_HPP_
