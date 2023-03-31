#include <vector>
#include <string>

#include "TableTag.h"


const std::vector<std::string> &TableTag::getValues() const {
    return this->values;
}

TableTag::TableTag(const std::string &tagname, const std::string &content, std::vector<std::string> &&values) :
    Tag(tagname, content), values(values){

    this->parse_column_info();
}

bool TableTag::isTableTag() const {
    return true;
}

std::string TableTag::toString() const {
    auto s = Tag::toString();
    return s;

    // TODO
    for (auto &value : this->values) {
        s += value + ";";
    }
    return s;
}

void TableTag::parse_column_info() {
    this->column_count = count(this->content.begin(), this->content.end(), ';') + 1;
}

std::string *TableTag::row_iterator::operator->() {
    return &(*it);
}

std::string &TableTag::row_iterator::operator*() {
    return *it;
}

bool TableTag::row_iterator::operator!=(const TableTag::row_iterator &rhs) const {
    return it != rhs.it;
}

bool TableTag::row_iterator::operator==(const TableTag::row_iterator &rhs) const {
    return it == rhs.it;
}

TableTag::row_iterator TableTag::row_iterator::operator++(int) {
    row_iterator tmp = *this;
    operator++();
    return tmp;
}

TableTag::row_iterator &TableTag::row_iterator::operator++() {
    it += column_count;
    return *this;
}
