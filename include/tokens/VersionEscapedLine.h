#pragma once

#include <cassert>
#include <regex>
#include "EscapedLine.h"
#include "../trim.h"

namespace tokens {

    class VersionEscapedLine : public tokens::EscapedLine {


        string versionString;
    public:
        explicit VersionEscapedLine(const string &versionString);

        string getVersionString() const;

        bool isExport() const override;

        string typeName() const override;

        bool isVersion() const override;

        string toString() const override;

    };

    inline string extractVersionString(const string &line) {
        string result = line.substr(versionLinePrefix.length());
        trim(result);
        return result;
    }

    bool VersionEscapedLine::isExport() const {
        return false;
    }

    bool VersionEscapedLine::isVersion() const {
        return false;
    }

    string VersionEscapedLine::toString() const {
        return string();
    }

    string VersionEscapedLine::getVersionString() const {
        return this->versionString;
    }

    VersionEscapedLine::VersionEscapedLine(const string &content) {
        this->versionString = extractVersionString(content);
    }

    string VersionEscapedLine::typeName() const {
        return "Version Directive";
    }

}

