#include "BoardContext.hpp"
#include "BoardTag.hpp"
#include "Tags.hpp"
#include "PbnFile.hpp"
#include "observer.hpp"

#include <stdexcept>
#include <cassert>
#include <iostream>

using namespace tokens;
using namespace tokens::tags;


 std::span<std::unique_ptr<SemanticPbnToken>> BoardContext::tokens() const
{
    auto& range = this->pbnFile.BoardContextIdToTokenIndex.at(this->id) ;

    return std::span{ this->pbnFile.tokens.begin() + range.StartIndex, range.TokenCount };
}

bool BoardContext::acceptsToken(size_t atIndex, observer_ptr<SemanticPbnToken> token) const {
    
    if( !token->isTag()) return true;

    auto tag = dynamic_cast<observer_ptr<Tag>>(token);
    if( isTagRecognized(tag->getTagname()) && doesTagHaveToBelongToBoardContext(tag->getTagname()) ) {
        return !std::any_of(this->tokens().begin(), this->tokens().end(), [tag](std::unique_ptr<SemanticPbnToken>& token) {
            if( !token->isTag() ) return false;
            auto&& tokenTag = dynamic_cast<observer_ptr<Tag>>(token.get());
            return tokenTag->getTagname() == tag->getTagname();
        });
    }

    return true;
}


void BoardContext::applyTag(observer_ptr<Tag> token)
{
    if (token->getTagname() == tokens::tags::BOARD )
    {
        assert( this->boardNumber == 0 && "Internal error: Board number is already set." );        
        this->boardNumber = dynamic_cast<observer_ptr<BoardTag>>(token)->getBoardNumber();
    }
}

void BoardContext::unapplyTag(observer_ptr<Tag> token)
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