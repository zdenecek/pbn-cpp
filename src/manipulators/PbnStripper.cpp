#include "PbnStripper.hpp"
#include "EscapedLine.hpp"
#include "observer.hpp"

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
        auto& token = file.getTokens()[i];

        if (token->isEscapedLine() && dynamic_cast<observer_ptr<tokens::EscapedLine>>(token.get())->isDirective())
            continue;

        if (token->isTag() && std::find(allowed_tags.begin(), allowed_tags.end(), dynamic_cast<observer_ptr<tokens::Tag>>(token.get())->getTagname()) != allowed_tags.end())
            continue;

        file.deleteToken(token.get());
        i--;
    }
}
}