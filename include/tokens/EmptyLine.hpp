#ifndef TOKENS_EMPTYLINE_HPP_
#define TOKENS_EMPTYLINE_HPP_

#include "SemanticPbnToken.hpp"
#include <string>
#include <ostream>

namespace tokens
{
    /// @brief Represent an empty line used for spacing in the file.
    class EmptyLine : public SemanticPbnToken
    {
    public:
        static constexpr std::string_view typeName = "Empty Line";

        std::string getTypeName() const override;
        bool isTag() const override;
        void serialize(std::ostream &to) const override;
    };

}

#endif // TOKENS_EMPTYLINE_HPP_
