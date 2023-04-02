#include "PbnStripper.h"

#include <vector>

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
    }
) {}

void PbnStripper::strip(PbnFile &file)
{
    for(auto& token : file.getTokens()) {
        if(token->isTag()) {

        }
    }
}