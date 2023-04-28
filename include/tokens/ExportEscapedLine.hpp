
#pragma once

#include <string>
#include <ostream>

#include "EscapedLine.hpp"

namespace tokens
{

    /// @brief Represent an export directive, which is a line in the format "% EXPORT"
    class ExportEscapedLine : public tokens::EscapedLine
    {
        bool isExport() const override;

    public:
        static constexpr std::string_view typeName = "Export Directive";
        std::string getTypeName() const override;

    private:
        bool isVersion() const override;

        void serialize(std::ostream &to) const override;
    };

    bool ExportEscapedLine::isExport() const
    {
        return true;
    }

    bool ExportEscapedLine::isVersion() const
    {
        return false;
    }

    void ExportEscapedLine::serialize(std::ostream &to) const
    {
        to << exportLine;
    }

    std::string ExportEscapedLine::getTypeName() const
    {
        return std::string(this->typeName);
    }
}
