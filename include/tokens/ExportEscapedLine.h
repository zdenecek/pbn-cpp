
#pragma  once

#include <string>

#include "EscapedLine.h"

namespace tokens {

    class ExportEscapedLine : public tokens::EscapedLine {
        bool isExport() const override;

    public:
        std::string typeName() const override;

    private:

        bool isVersion() const override;

        std::string toString() const override;
    };

    bool ExportEscapedLine::isExport() const {
        return true;
    }

    bool ExportEscapedLine::isVersion() const {
        return false;
    }

    std::string ExportEscapedLine::toString() const {
        return std::string(exportLine);
    }

    std::string ExportEscapedLine::typeName() const {
        return "Export Directive";
    }
}
