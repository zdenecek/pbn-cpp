#ifndef TOKENS_TAG_HPP_
#define TOKENS_TAG_HPP_

#include <string>
#include <ostream>

#include "SemanticPbnToken.hpp"

namespace tokens
{

    /// @brief This class represents a tag in the Semantic PBN format.
class Tag : public SemanticPbnToken
    {
    protected:
        std::string tagname;
        std::string content;

    public:
        /// @brief Construct a Tag object using a tag name and the content of the tag.  The tag name and content should not contain angle brackets or ampersands as per specification.
        Tag(const std::string &tagname, const std::string &content);

        /// @brief Returns the tagname of this tag
        [[nodiscard]] const std::string &getTagname() const;

        /// @brief This function returns a string containing the contents of the file.
        [[nodiscard]] const std::string &getContent() const;
 

        /// @brief Helper method returns true if the tag represents a so called supplementary section or a TableTag
        virtual bool isTableTag() const;

        static constexpr std::string_view typeName = "Tag";
        std::string getTypeName() const override;

        bool isTag() const override;

        void serialize(std::ostream &to) const override;
    };

}

#endif // TOKENS_TAG_HPP_
