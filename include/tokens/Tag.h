#pragma once

#include <string>
#include <ostream>

#include "SemanticPbnToken.h"

namespace tokens
{

    // This class represents a tag in the Semantic PBN format.
    class Tag : public SemanticPbnToken
    {
    protected:
        std::string tagname;
        std::string content;

    public:
        // Construct a Tag object using a tag name and the content of
        // the tag.  The tag name and content should not contain angle
        // brackets or ampersands.
        Tag(const std::string &tagname, const std::string &content);

        // Returns the tagname of this tag
        [[nodiscard]] const std::string &getTagname() const;

        // This function returns a string containing the contents of the file.
        [[nodiscard]] const std::string &getContent() const;

        virtual bool isTableTag() const;

        static constexpr std::string_view typeName = "Tag";
        std::string getTypeName() const override;

        bool isTag() const override;

        void serialize(std::ostream &to) const override;
    };

}