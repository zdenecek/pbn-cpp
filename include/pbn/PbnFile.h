#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

#include "../tokens/SemanticPbnToken.h"
#include "DealContext.h"

using namespace std;

using DealContextObs = DealContext*;

class PbnFile
{
    friend class PbnParser;

protected:
	vector<shared_ptr<SemanticPbnToken>> tokens;
    vector<DealContext> deals;
    map<int, DealContext*> dealsByNumber;

public:

    [[nodiscard]] const vector<DealContext>& getDeals() const;
    [[nodiscard]] bool hasDealWithNumber(size_t number) const;

    [[nodiscard]] DealContextObs getDeal(size_t number);
    [[nodiscard]] vector<shared_ptr<SemanticPbnToken>>& getTokens();

    void normalize();
    void insertToken(shared_ptr<SemanticPbnToken> token);
	
};

