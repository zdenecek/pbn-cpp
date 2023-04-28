#pragma once

#include <string>
#include <ostream>

namespace tokens
{
    /// @brief Represents a token of a PbnFile.
    /// @details This is the base class for all tokens. It is used to represent a token of a PbnFile.
    class SemanticPbnToken
    {
    public:
        virtual ~SemanticPbnToken() noexcept = default;

        /// @return The string serialization of the token, excluding newline at the end.
        std::string toString() const;

        /// Print the tag in export format to a stream.
        /// @param stream A stream to print to.
        virtual void serialize(std::ostream &to) const = 0;

        /// @return Custom typename used by the program internally.
        virtual std::string getTypeName() const = 0;

        /// @brief Helper method to check if the token is a tag.
        /// @return True if the token is any tag, false otherwise.
        virtual bool isTag() const { return false; };
        /// @brief Helper method to check if the token is a commentary.
        /// @return True if the token is a commentary, false otherwise.
        virtual bool isCommentary() const { return false; };
        /// @brief Helper method to check if the token is an escaped line.
        /// @return True if the token is an escaped line, false otherwise.
        virtual bool isEscapedLine() const { return false; };
        /// @brief Helper method to check if the token is a unrecognized text line.
        /// @return True if the token is an unrecognized text line, false otherwise.
        virtual bool isTextLine() const { return false; };
    };

}