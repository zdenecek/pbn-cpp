
#pragma once

#include "PbnFile.hpp"

#include <string>
#include <vector>
#include <memory>

namespace manipulators {


/// @brief Used to execute the --strip command. Used to purge a pbn file of unwanted tokens.
class PbnStripper
{

public:
    std::vector<std::string> allowed_tags;

    /// @brief Creates a file stripper with predefined allowed tags.
    /// The striper removes all tokens except directives and allowed tags.
    /// Predefined tags are:  Generator, Board, Dealer, Vulnerable, Deal, Ability, Minimax, OptimumScore, OptimumResultTable, 
    PbnStripper();

    /// @brief Creates a file stripper with the given allowed tags.
    /// The stripper removes all tokens except directives and allowed tags.
    explicit PbnStripper(std::vector<std::string> allowed_tags) : allowed_tags(allowed_tags) {}

    /// @brief The strip method removes all tokens except directives and allowed tags.
    /// @param file file to strip.
    void strip(PbnFile &file);
};

}