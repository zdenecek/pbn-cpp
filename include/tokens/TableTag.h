#pragma once

#include <vector>
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
};

class TableTag  : public Tag {

public:

    struct row_iterator {
        std::vector<std::string>::iterator it;
        int column_count;

        row_iterator(std::vector<std::string>::iterator it, int column_count) : it(it), column_count(column_count) {}

        row_iterator &operator++();

        row_iterator operator++(int);

        bool operator==(const row_iterator &rhs) const;

        bool operator!=(const row_iterator &rhs) const;

        std::string &operator*();

        std::string *operator->();
    };

    TableTag(const std::string &tagname, const std::string &content, std::vector<std::string> &&values);

    [[nodiscard]] const std::vector<std::string> &getValues() const;

    bool isTableTag() const override;

    std::string toString() const override;

private:

    std::vector<std::string> values;
    int column_count;

    void parse_column_info();
};
