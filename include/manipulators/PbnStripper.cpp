#include "PbnStripper.h"
#include "EscapedLine.h"
#include <vector>
#include <memory>

namespace manipulators {


PbnStripper::PbnStripper() : PbnStripper(
                                 {
                                     "Generator",
                                     "Board",
                                     "Dealer",
                                     "Vulnerable",
                                     "Deal",
                                     "Ability",
                                     "Minimax",
                                     "OptimumScore",
                                     "OptimumResultTable",
                                 })
{
}

void PbnStripper::strip(PbnFile &file)
{
    for (size_t i = 0; i < file.getTokens().size(); i++)
    {
        auto token = file.getTokens()[i];

        if (token->isEscapedLine() && std::static_pointer_cast<tokens::EscapedLine>(token)->isDirective())
            continue;

        if (token->isTag() && std::find(allowed_tags.begin(), allowed_tags.end(), std::static_pointer_cast<tokens::Tag>(token)->getTagname()) != allowed_tags.end())
            continue;

        file.deleteToken(token);
        i--;
    }
}
}