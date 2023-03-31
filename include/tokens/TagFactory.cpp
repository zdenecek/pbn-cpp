
#include <set>
#include <string>
#include <memory>

#include "TagFactory.h"


std::set<std::string> tableTags = {"ActionTable",
                            "AuctionTimeTable",
                            "InstantScoreTable",
                            "OptimumPlayTable",
                            "OptimumResultTable",
                            "PlayTimeTable",
                            "ScoreTable",
                            "TotalScoreTable"};

bool TagFactory::isTableTag(const std::string& tagName) {

    return tableTags.contains(tagName);
}

std::shared_ptr<Tag> TagFactory::createTableTag(std::string tagName, std::string tagContent, std::vector<std::string> &&values) {
    return make_shared<Tag>(tagName, tagContent);
}

std::shared_ptr<Tag> TagFactory::createTag(std::string tagName, std::string tagContent) {
    return make_shared<Tag>(tagName, tagContent);
}
