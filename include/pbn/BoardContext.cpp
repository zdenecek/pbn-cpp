#include "BoardContext.h"
#include "BoardTag.h"
#include "Tags.h"
#include "PbnFile.h"

#include <stdexcept>
#include <cassert>
#include <iostream>

using namespace tokens;
using namespace tokens::tags;


 std::span<std::shared_ptr<SemanticPbnToken>> BoardContext::tokens() const
{
    auto& range = this->pbnFile.BoardContextIdToTokenIndex.at(this->id) ;
    return std::span{ this->pbnFile.tokens.begin() + range.StartIndex, range.TokenCount };
}

bool BoardContext::acceptsToken(size_t atIndex, std::shared_ptr<SemanticPbnToken> token) const {
    
    if( !token->isTag()) return true;

    auto tag = std::dynamic_pointer_cast<Tag>(token);
    if( isTagRecognized(tag->getTagname()) && doesTagHaveToBelongToBoardContext(tag->getTagname()) ) {
        return !std::any_of(this->tokens().begin(), this->tokens().end(), [tag](auto &token) {
            if( !token->isTag() ) return false;
            auto tokenTag = std::dynamic_pointer_cast<Tag>(token);
            return tokenTag->getTagname() == tag->getTagname();
        });
    }

    return true;
}


void BoardContext::applyTag(std::shared_ptr<Tag> token)
{
    if (token->getTagname() == tokens::tags::BOARD )
    {
        assert( this->boardNumber == 0 && "Internal error: Board number is already set." );        
        this->boardNumber = std::dynamic_pointer_cast<BoardTag>(token)->getBoardNumber();
    }
}

void BoardContext::unapplyTag(std::shared_ptr<Tag> token)
{
    assert( (token->getTagname() != tokens::tags::BOARD || this->boardNumber != 0) && "Internal error: Board number cannot be changed.");

    if (token->getTagname() == tokens::tags::BOARD)
    {
        this->boardNumber = 0;
    }
}
BoardNumber BoardContext::getBoardNumber() const
{
    return this->boardNumber;
}