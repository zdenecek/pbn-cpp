#include "EscapedLine.h"
#include "VersionEscapedLine.h"
#include "ExportEscapedLine.h"
#include "CustomEscapedLine.h"

#include <string>
#include <regex>
#include <cassert>

namespace tokens {

    const std::regex versionRegex(R"--(^\% PBN\s+(\d+\.\d+)\s*$)--");

    inline bool isVersionLine(const std::string &line) {
        if (!line.starts_with(versionLinePrefix))
            return false;
        else
            return std::regex_match(line, versionRegex);
    }

    std::shared_ptr<EscapedLine> EscapedLine::create(const std::string &contents) {
        if (contents == exportLine)
            return std::make_shared<ExportEscapedLine>();
        if (isVersionLine(contents))
            return std::make_shared<VersionEscapedLine>(contents);

        return make_shared<CustomEscapedLine>(contents.substr(1));
    }

    bool EscapedLine::isEscapedLine() const {
        return true;
    }

    bool EscapedLine::isDirective() const {
        return this->isVersion() || this->isExport();
    }


} // tokens