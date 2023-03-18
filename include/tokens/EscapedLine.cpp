//
// Created by zdnek on 03/03/2023.
//

#include "EscapedLine.h"
#include "VersionEscapedLine.h"
#include "ExportEscapedLine.h"
#include "CustomEscapedLine.h"

#include <string>
#include <regex>
#include <cassert>

namespace tokens {

    const regex versionRegex(R"--(^\% PBN\s+(\d+\.\d+)\s*$)--");

    inline bool isVersionLine(const string &line) {
        if (!line.starts_with(versionLinePrefix))
            return false;
        else
            return regex_match(line, versionRegex);
    }

    shared_ptr<EscapedLine> EscapedLine::create(const string &contents) {
        if (contents == exportLine)
            return make_shared<ExportEscapedLine>();
        if (isVersionLine(contents))
            return make_shared<VersionEscapedLine>(contents);

        return make_shared<CustomEscapedLine>(contents.substr(1));
    }

    bool EscapedLine::isTag() const {
        return false;
    }

    bool EscapedLine::isDirective() const {
        return this->isDirective() || this->isExport();
    }


} // tokens