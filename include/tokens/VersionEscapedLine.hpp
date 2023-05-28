#ifndef TOKENS_VERSIONESCAPEDLINE_HPP_
#define TOKENS_VERSIONESCAPEDLINE_HPP_



#include <cassert>
#include <regex>
#include <string>
#include <ostream>

#include "EscapedLine.hpp"
#include "utils/strings.hpp"

namespace tokens
{
    /// @brief Represent a version directive, which is a line in the format "% PBN X.Y"
    class VersionEscapedLine : public tokens::EscapedLine
    {

        std::string versionString;

    public:
        static constexpr std::string_view typeName = "Version Directive";

        explicit VersionEscapedLine(const std::string &versionString);

        std::string getVersionString() const;

        bool isExport() const override;

        std::string getTypeName() const override;

        bool isVersion() const override;

        void serialize(std::ostream &to) const override;
    };

    inline std::string extractVersionString(const std::string &line)
    {
        std::string result = line.substr(versionLinePrefix.length());
        trim(result);
        return result;
    }

    bool VersionEscapedLine::isExport() const
    {
        return false;
    }

    bool VersionEscapedLine::isVersion() const
    {
        return true;
    }

    void VersionEscapedLine::serialize(std::ostream &to) const
    {
        to << versionLinePrefix << " " << this->versionString;
    }

    std::string VersionEscapedLine::getVersionString() const
    {
        return this->versionString;
    }

    VersionEscapedLine::VersionEscapedLine(const std::string &content)
    {
        this->versionString = extractVersionString(content);
    }

    std::string VersionEscapedLine::getTypeName() const
    {
        return std::string(this->typeName);
    }
}

#endif // TOKENS_VERSIONESCAPEDLINE_HPP_
