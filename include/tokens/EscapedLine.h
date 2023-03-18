#pragma once

#include "SemanticPbnToken.h"

#include <memory>
#include <regex>

namespace tokens {

    constexpr char escapeCharacter = '%';
    /**
     * As per 2.4  Escape mechanism / Proposed uses (1) and (2)
     */
    constexpr string_view versionLinePrefix = "% PBN";
    constexpr string_view exportLine = "% EXPORT";

    class EscapedLine : public SemanticPbnToken {
    public:
        static shared_ptr<EscapedLine> create(const string &contents);

        bool isTag() const override;

        bool isDirective() const;
        [[nodiscard]] virtual bool isExport() const = 0;
        [[nodiscard]] virtual bool isVersion() const = 0;
    };


} // tokens
