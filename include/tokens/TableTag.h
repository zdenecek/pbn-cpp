//
// Created by zdnek on 17/03/2023.
//


#pragma once


#include <vector>
#include "Tag.h"

using namespace std;


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

    string name;
    Ordering ordering;
    Alignment alignment;
    size_t alignment_width;
};

class TableTag  : public Tag {

public:

    struct row_iterator {
        vector<string>::iterator it;
        int column_count;

        row_iterator(vector<string>::iterator it, int column_count) : it(it), column_count(column_count) {}

        row_iterator &operator++();

        row_iterator operator++(int);

        bool operator==(const row_iterator &rhs) const;

        bool operator!=(const row_iterator &rhs) const;

        string &operator*();

        string *operator->();
    };

    TableTag(const string &tagname, const string &content, vector<string> &&values);

    [[nodiscard]] const vector<string> &getValues() const;

    bool isTableTag() const override;

    [[nodiscard]] string typeName() const override;

    string toString() const override;

private:

    vector<string> values;
    int column_count;

    void parse_column_info();
};
