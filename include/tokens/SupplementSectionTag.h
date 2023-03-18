//
// Created by zdnek on 12/03/2023.
//


#pragma once


#include "Tag.h"

#include <vector>
#include <string>

using namespace std;

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
    string name;
    ColumnOrdering ordering;
    ColumnAlignmentSpecification alignment;

};

class SupplementSectionTag : public Tag {

public:
    vector<ColumnSpecification> Columns;
};
