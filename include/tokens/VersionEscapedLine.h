#pragma once

#include <cassert>
#include <regex>
#include <string>
#include <ostream>


#include "EscapedLine.h"
#include "utils/strings.h"

namespace tokens {

    class VersionEscapedLine : public tokens::EscapedLine {

        std::string versionString;
    public:
        explicit VersionEscapedLine(const std::string &versionString);

        std::string getVersionString() const;

        bool isExport() const override;

        std::string typeName() const override;

        bool isVersion() const override;

        void serialize(std::ostream& to) const override;

    };

    inline std::string extractVersionString(const std::string &line) {
        std::string result = line.substr(versionLinePrefix.length());
        trim(result);
        return result;
    }

    bool VersionEscapedLine::isExport() const {
        return false;
    }

    bool VersionEscapedLine::isVersion() const {
        return false;
    }

    void VersionEscapedLine::serialize(std::ostream& to) const  {
        to << versionLinePrefix << " " << this->versionString;
    }

    std::string VersionEscapedLine::getVersionString() const {
        return this->versionString;
    }

    VersionEscapedLine::VersionEscapedLine(const std::string &content) {
        this->versionString = extractVersionString(content);
    }

    std::string VersionEscapedLine::typeName() const {
        return "Version Directive";
    }

}

