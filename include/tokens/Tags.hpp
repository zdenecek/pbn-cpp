
#ifndef TOKENS_TAGS_HPP_
#define TOKENS_TAGS_HPP_

#include <algorithm>
#include <array>
#include <string>

#include "arrays.hpp"

namespace tokens
{

    class SemanticPbnToken;
    class Tag;
}

namespace tokens::tags
{
    // Known tags
    constexpr std::string_view EVENT = "Event";
    constexpr std::string_view SITE = "Site";
    constexpr std::string_view DATE = "Date";
    constexpr std::string_view BOARD = "Board";
    constexpr std::string_view WEST = "West";
    constexpr std::string_view NORTH = "North";
    constexpr std::string_view EAST = "East";
    constexpr std::string_view SOUTH = "South";
    constexpr std::string_view DEALER = "Dealer";
    constexpr std::string_view VULNERABLE = "Vulnerable";
    constexpr std::string_view DEAL = "Deal";
    constexpr std::string_view SCORING = "Scoring";
    constexpr std::string_view DECLARER = "Declarer";
    constexpr std::string_view CONTRACT = "Contract";
    constexpr std::string_view RESULT = "Result";
    constexpr std::string_view BC_FLAGS = "BCFlags";
    constexpr std::string_view DOUBLE_DUMMY_TRICKS = "DoubleDummyTricks";
    constexpr std::string_view OPTIMUM_SCORE = "OptimumScore";
    constexpr std::string_view OPTIMUM_RESULT_TABLE = "OptimumResultTable";

    constexpr std::array IDENTIFICATION_SECTION_TAGS = { EVENT, SITE, DATE, BOARD, WEST, NORTH, EAST, SOUTH, DEALER, VULNERABLE, DEAL, SCORING, DECLARER, CONTRACT, RESULT };

    constexpr std::array OTHER_TAGS = { DOUBLE_DUMMY_TRICKS, OPTIMUM_SCORE, OPTIMUM_RESULT_TABLE };
    
    constexpr std::array RECOGNIZED_TAGS = concat(IDENTIFICATION_SECTION_TAGS, OTHER_TAGS);

    inline bool isIdentificationSectionTag(const std::string &tag)
    {
        return std::any_of(IDENTIFICATION_SECTION_TAGS.begin(), IDENTIFICATION_SECTION_TAGS.end(), [&tag](const auto &knownTag) { return knownTag == tag; });
    }

    inline bool identificationSectionTagPrecedence(const std::string &tag)
    {
        return std::find(IDENTIFICATION_SECTION_TAGS.begin(), IDENTIFICATION_SECTION_TAGS.end(), tag) - IDENTIFICATION_SECTION_TAGS.begin();
    }

    inline bool doesTagHaveToBelongToBoardContext(const std::string &tag)
    {
        // TODO
        return true;
    }

    inline bool isTagRecognized(const std::string &tag)
    {
        return std::any_of(RECOGNIZED_TAGS.begin(), RECOGNIZED_TAGS.end(), [&tag](const auto &knownTag) { return knownTag == tag; });
    }

}

#endif // TOKENS_TAGS_HPP_
