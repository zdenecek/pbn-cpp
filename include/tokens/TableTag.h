#pragma once

#include <vector>
#include <ostream>

#include "Tag.h"

struct ColumnInfo {
    enum class Ordering {
        Ascending,
        Descending,
        None
    };

    enum class Alignment {
        Left,
        Right,
        None
    };

    std::string name;
    Ordering ordering;
    Alignment alignment;
    size_t alignment_width;

    ColumnInfo() : ordering(Ordering::None), alignment(Alignment::None) {}

    void setFormatting(std::ostream& to) const;
};

class TableTag  : public Tag {

public:
    struct rows {

    private:
        const std::vector<std::string>& values;
        size_t column_count;

    public:
        explicit rows(const std::vector<std::string>& values, size_t columns) : values(values), column_count(columns) {}

        struct iterator {
                private:
                std::vector<std::string>::const_iterator it;
                size_t column_count;
                public:

                iterator(std::vector<std::string>::const_iterator it, size_t column_count) : it(it), column_count(column_count) {}

                iterator &operator++();

                iterator operator++(int);

                bool operator==(const iterator &rhs) const;

                bool operator!=(const iterator &rhs) const;

                std::vector<std::string> operator*();
        };

        [[nodiscard]] iterator begin() const;
        [[nodiscard]] iterator end() const;
    };


    TableTag(const std::string &tagname, const std::string &content, std::vector<std::string> &&values);

    [[nodiscard]] const std::vector<std::string> &getValues() const;
    [[nodiscard]] rows getRows() const;

    bool isTableTag() const override;

    void serialize(std::ostream& to) const override;
    std::string typeName() const override;


private:

    std::vector<std::string> values;
    std::vector<ColumnInfo> column_info;
    int column_count;

    void parse_column_info();
};
