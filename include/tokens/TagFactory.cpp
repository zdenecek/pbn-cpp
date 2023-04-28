
#include <set>
#include <string>
#include <memory>

#include "TagFactory.h"
#include "Tag.h"
#include "TableTag.h"

#include "Tags.h"
#include "BoardTag.h"

using namespace tokens::tags;

namespace tokens
{

    std::set<std::string> tableTags = {"ActionTable",
                                       "AuctionTimeTable",
                                       "InstantScoreTable",
                                       "OptimumPlayTable",
                                       "OptimumResultTable",
                                       "PlayTimeTable",
                                       "ScoreTable",
                                       "TotalScoreTable"};

    bool TagFactory::isTableTag(const std::string &tagName)
    {

        return tableTags.contains(tagName);
    }

    std::unique_ptr<Tag> TagFactory::createTableTag(std::string tagName, std::string tagContent, std::vector<std::string> &&values)
    {
        return std::make_unique<TableTag>(tagName, tagContent, std::move(values));
    }

    std::unique_ptr<Tag> TagFactory::createTag(std::string tagName, std::string tagContent)
    {
        if(tagName == BOARD) {
            return std::make_unique<BoardTag>(tagContent);
        }
        return std::make_unique<Tag>(tagName, tagContent);
    }

}