
#pragma  once

#include "EscapedLine.h"

namespace tokens {

    class ExportEscapedLine : public tokens::EscapedLine {
        bool isExport() const override;

    public:
        string typeName() const override;

    private:

        bool isVersion() const override;

        string toString() const override;
    };

    bool ExportEscapedLine::isExport() const {
        return true;
    }

    bool ExportEscapedLine::isVersion() const {
        return false;
    }

    string ExportEscapedLine::toString() const {
        return string(exportLine);
    }

    string ExportEscapedLine::typeName() const {
        return "Export Directive";
    }
}
