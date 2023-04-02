#pragma once

#include <string>
#include <ostream>
#include "SemanticPbnToken.h"


namespace tokens
{

    /// @brief This enum represents the format of a commentary token.
    /// Either Multiline (delimited {}, not nested) or Singleline (preceded by ;) as per specification.
    enum class CommentaryFormat
    {
        Singleline,
        Multiline,
    };

    /// @brief This class represents a commentary token as per specification.
    /// Both multiline and single lines comments are represented by Commentary
    /// @see tokens::CommentaryFormat
    class Commentary : public SemanticPbnToken
    {
    public:
        static constexpr std::string_view typeName = "Commentary";
        std::string getTypeName() const override;
        

        Commentary(CommentaryFormat format, bool startsOnNewLine, const std::string &content);
        
        /// @brief Create commentary. Multiline/singleline format is decided by presence of newline characters.
        Commentary(const std::string &content);
        
        void serialize(std::ostream &to) const override;
        bool isCommentary() const override;

        /// @brief Format, either Multiline (delimited {}, not nested) or Singleline (preceded by ;) as per specification.
        CommentaryFormat format;
        bool startsOnNewLine;
        /// @brief Content of the commentary token, excluding the delimiters
        std::string content;
    };

} // tokens
