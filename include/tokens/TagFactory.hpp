#ifndef TOKENS_TAGFACTORY_HPP_
#define TOKENS_TAGFACTORY_HPP_


#include <memory>
#include <string>
#include <vector>
#include "Tag.hpp"

namespace tokens
{
    /// @brief Class containing factory methods for creating Tag tokens.
    class TagFactory
    {

    public:
        std::unique_ptr<Tag> createTag(std::string tagName, std::string tagContent);
        std::unique_ptr<Tag> createTableTag(std::string tagName, std::string tagContent, std::vector<std::string> &&values);


        /// @brief Check if provided tag name corresponds to a supplementary section tag.
        /// @see TableTag
        bool isTableTag(const std::string &tagName);
    };
}

#endif // TOKENS_TAGFACTORY_HPP_
