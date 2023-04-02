#include "BoardContext.h"
#include "Tags.h"
#include "PbnFile.h"

#include <stdexcept>
#include <cassert>

static BoardContextId id = 0;
static BoardContextId getNewId()
{
    return id++;
}

void BoardContext::applyTag(std::shared_ptr<Tag> token)
{
    if (token->getTagname() == tokens::tags::BOARD && this->boardNumber != 0)
    {
        throw std::runtime_error("Internal error: Board number cannot be changed.");
    }
}

void BoardContext::unapplyTag(std::shared_ptr<Tag> token)
{
    assert(token->getTagname() != tokens::tags::BOARD || this->boardNumber != 0 && "Internal error: Board number cannot be changed.");

    if (token->getTagname() == tokens::tags::BOARD)
    {
        this->boardNumber = 0;
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

BoardContext::context_tokens BoardContext::getTokens() const
{
    return context_tokens(*this);
}

std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator BoardContext::context_tokens::begin()
{
    auto &range = this->context.pbnFile.BoardContextIdToTokenIndex[this->context.id];
    return this->context.pbnFile.getTokens().begin() + range.StartIndex;
}

std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator BoardContext::context_tokens::end()
{
    auto &range = this->context.pbnFile.BoardContextIdToTokenIndex[this->context.id];
    return this->begin() + range.TokenCount;
}
