#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

#include "../tokens/SemanticPbnToken.h"
#include "DealContext.h"

using DealContextObs = DealContext*;

class PbnFile
{
    friend class PbnParser;

protected:
	std::vector<std::shared_ptr<SemanticPbnToken>> tokens;
    std::vector<DealContext> deals;
    std::map<int, DealContext*> dealsByNumber;

public:

    [[nodiscard]] const std::vector<DealContext>& getDeals() const;
    [[nodiscard]] bool hasDealWithNumber(size_t number) const;

    [[nodiscard]] DealContextObs getDeal(size_t number);
    [[nodiscard]] std::vector<std::shared_ptr<SemanticPbnToken>>& getTokens();

    void normalize();
    void insertToken(std::shared_ptr<SemanticPbnToken> token);
	
};

