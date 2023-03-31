#pragma once

#include "Tag.h"

#include <vector>
#include <string>


enum class ColumnOrdering {
    Default,
    Ascending,
    Descending,
};

enum class ColumnAlignment {
    left,
    right,
    none
};

struct ColumnAlignmentSpecification {
    int minWidth;
    ColumnAlignment alignment;
};

struct ColumnSpecification {
    std::string name;
    ColumnOrdering ordering;
    ColumnAlignmentSpecification alignment;

};

class SupplementSectionTag : public Tag {

public:
    std::vector<ColumnSpecification> Columns;
};
