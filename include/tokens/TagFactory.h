#pragma once


#include <memory>
#include <string>
#include <vector>
#include "Tag.h"

class TagFactory {

public:
    std::shared_ptr<Tag> createTag(std::string tagName, std::string tagContent);
    std::shared_ptr<Tag> createTableTag(std::string tagName, std::string tagContent, std::vector<std::string> &&values);

    bool isTableTag(const std::string &tagName);
};
