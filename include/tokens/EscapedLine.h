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

        bool isDirective() const;
        [[nodiscard]] virtual bool isExport() const = 0;
        [[nodiscard]] virtual bool isVersion() const = 0;
    };

} // tokens
