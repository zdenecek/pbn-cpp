#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

#include "TableTag.h"
#include "strings.h"

constexpr auto LEFT_ALIGN_CHAR = 'L';
constexpr auto RIGHT_ALIGN_CHAR = 'R';
constexpr auto ORDERING_INFO_SEPARATOR = '\\';
constexpr auto ASCENDING_ORDERING_CHAR = '+';
constexpr auto DESCENDING_ORDERING_CHAR = '-';

ColumnInfo parse_single_column_info(const std::string &info)
{

    auto str = info;

    ColumnInfo col_info{};

    // Ordering
    if (str[0] == ASCENDING_ORDERING_CHAR || str[0] == DESCENDING_ORDERING_CHAR)
    {
        col_info.ordering = str[0] == ASCENDING_ORDERING_CHAR ? ColumnInfo::Ordering::Ascending : ColumnInfo::Ordering::Descending;
        str = str.substr(1);
    }

    // Alignment
    if (str.find(ORDERING_INFO_SEPARATOR) != std::string::npos)
    {
        auto parts = split(str, ORDERING_INFO_SEPARATOR);
        if (parts.size() != 2)
            throw std::runtime_error("Invalid column format: " + info);
        col_info.name = parts[0];

        if (parts[1].back() == RIGHT_ALIGN_CHAR || parts[1].back() == LEFT_ALIGN_CHAR)
        {
            col_info.alignment = parts[1].back() == LEFT_ALIGN_CHAR ? ColumnInfo::Alignment::Left : ColumnInfo::Alignment::Right;
            parts[1].pop_back();
        }
        try
        {
            col_info.alignment_width = std::stoi(parts[1]);
        }
        catch (std::invalid_argument &e)
        {
            throw std::runtime_error("Invalid column format: " + info);
        }

        // No aligment specified
    }
    else
    {
        col_info.name = str;
    }

    return col_info;
}

const std::vector<std::string> &TableTag::getValues() const
{
    return this->values;
}

TableTag::TableTag(const std::string &tagname, const std::string &content, std::vector<std::string> &&values) : Tag(tagname, content),
                                                                                                                values(values),
                                                                                                                column_info()
{
    this->parse_column_info();
    if (values.size() % column_count != 0)
        throw std::runtime_error("Invalid number of values for table: " + tagname);
}

bool TableTag::isTableTag() const
{
    return true;
}

std::string TableTag::typeName() const
{
    return "TableTag";
}

TableTag::rows TableTag::getRows() const
{
    return rows(this->values, this->column_count);
}

void TableTag::serialize(std::ostream& to) const 
{
    
    auto ostream_state { to.flags() }; // save stream configuration
    Tag::serialize(to);
    auto rows = this->getRows();

    for (auto &&row : rows)
    {
        to << "\n";
        bool first = true;
        for (auto i = 0; i < this->column_count; i++) {
            if(first) 
                first = false;
            else 
                to << " ";


            this->column_info[i].setFormatting(to);
            to << row[i];
        }
    }
    to.flags(ostream_state);  // restore stream configuration
    to << "\n";
}

void TableTag::parse_column_info()
{
    this->column_count = count(this->content.begin(), this->content.end(), ';') + 1;

    auto infos = split(this->content, ';');

    if (infos.empty())
    {
        throw std::runtime_error("Invalid column format: " + this->content);
    }

    for (auto col_info : infos)
    {
        this->column_info.push_back(parse_single_column_info(col_info));
    }

    auto ordered = std::count_if(this->column_info.begin(), this->column_info.end(), [](auto &info)
                                 { return info.ordering != ColumnInfo::Ordering::None; });
    if (ordered > 1)
        throw std::runtime_error("Only one column can be ordered: " + this->content);
}

std::vector<std::string> TableTag::rows::iterator::operator*()
{
    return std::vector<std::string>(this->it, this->it + this->column_count);
}

bool TableTag::rows::iterator::operator!=(const TableTag::rows::iterator &rhs) const
{
    return it != rhs.it;
}

bool TableTag::rows::iterator::operator==(const TableTag::rows::iterator &rhs) const
{
    return it == rhs.it;
}

TableTag::rows::iterator TableTag::rows::iterator::operator++(int)
{
    TableTag::rows::iterator tmp = *this;
    operator++();
    return tmp;
}

TableTag::rows::iterator &TableTag::rows::iterator::operator++()
{
    it += column_count;
    return *this;
}

TableTag::rows::iterator TableTag::rows::begin() const
{
    return TableTag::rows::iterator(this->values.begin(), this->column_count);
}

TableTag::rows::iterator TableTag::rows::end() const
{
    return TableTag::rows::iterator(this->values.end(), this->column_count);
}

void ColumnInfo::setFormatting(std::ostream &to) const
{
    if(this->alignment == Alignment::None) return;

    if(this->alignment == Alignment::Left) {
        to << std::left;
    }
    if(this->alignment == Alignment::Right)  {
        to << std::right;
    }
    to << std::setw(this->alignment_width);
}
