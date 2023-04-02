#include "BoardContext.h"
#include "Tags.h"
#include "PbnFile.h"

#include <stdexcept>

static int id = 0;
static int getNewId() {
    return id++;
}

void BoardContext::applyTag(std::shared_ptr<Tag> token)
{
    if(token->getTagname() == tags::BOARD && this->boardNumber != 0)
    {
        throw std::runtime_error("Internal error: Board number cannot be changed.");
    }
}

void BoardContext::initId()
{
    this->id = getNewId();
}

BoardNumber BoardContext::getBoardNumber() const
{
    return this->boardNumber;
}

BoardContext::tokens BoardContext::getTokens() const
{
    return tokens( *this);
}

std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator BoardContext::tokens::begin()
{
    auto& range = this->context.pbnFile.BoardContextIdToTokenIndex[this->context.id];
    return this->context.pbnFile.getTokens().begin() + range.StartIndex;
}

std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator BoardContext::tokens::end()
{
    auto& range = this->context.pbnFile.BoardContextIdToTokenIndex[this->context.id];
    return this->begin() + range.TokenCount;
}
