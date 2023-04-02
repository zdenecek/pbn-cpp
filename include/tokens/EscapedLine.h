#pragma once

#include "SemanticPbnToken.h"

#include <memory>
#include <regex>
#include <string>

namespace tokens
{

    constexpr char escapeCharacter = '%';
    /**
     * As per 2.4  Escape mechanism / Proposed uses (1) and (2)
     */
    constexpr std::string_view versionLinePrefix = "% PBN";
    constexpr std::string_view exportLine = "% EXPORT";

    class EscapedLine : public SemanticPbnToken
    {
    public:
        static std::shared_ptr<EscapedLine> create(const std::string &contents);

        bool isEscapedLine() const override;
        
        /// @brief Returns true if the token is a version directive token or an export directive token.
        bool isDirective() const;
        /// @brief Returns true if the token is an export directive token ("% EXPORT")
        [[nodiscard]] virtual bool isExport() const = 0;
        /// @brief Returns true if the token is a version directive token ("% PBN X.Y")
        [[nodiscard]] virtual bool isVersion() const = 0;
    };

} // tokens
