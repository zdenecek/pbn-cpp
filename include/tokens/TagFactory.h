//
// Created by zdnek on 12/03/2023.
//


#pragma once


#include <memory>
#include <string>
#include <vector>
#include "Tag.h"


using namespace std;
class TagFactory {

public:
    shared_ptr<Tag> createTag(string tagName, string tagContent);
    shared_ptr<Tag> createTableTag(string tagName, string tagContent, vector<string> &&values);

    bool isTableTag(const string &tagName);
};
