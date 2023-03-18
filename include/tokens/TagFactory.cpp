//
// Created by zdnek on 12/03/2023.
//

#include <set>
#include "TagFactory.h"

using namespace std;

set<string> tableTags = {"ActionTable",
                            "AuctionTimeTable",
                            "InstantScoreTable",
                            "OptimumPlayTable",
                            "OptimumResultTable",
                            "PlayTimeTable",
                            "ScoreTable",
                            "TotalScoreTable"};

bool TagFactory::isTableTag(const string& tagName) {

    return tableTags.contains(tagName);
}

shared_ptr<Tag> TagFactory::createTableTag(string tagName, string tagContent, vector<string> &&values) {
    return make_shared<Tag>(tagName, tagContent);
}

shared_ptr<Tag> TagFactory::createTag(string tagName, string tagContent) {
    return make_shared<Tag>(tagName, tagContent);
}
