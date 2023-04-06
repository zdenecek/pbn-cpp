#include "PbnFile.h"
#include "Tag.h"
#include "TableTag.h"
#include "Tags.h"

#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <optional>
#include <iostream>
#include <memory>
#include <cassert>
#include <algorithm>

using namespace tokens::tags;


bool PbnFile::hasBoardWithNumber(BoardNumber number) const
{

    return std::any_of(this->boardContexts.begin(), this->boardContexts.end(), [number](const BoardContext &context)
                       { return context.getBoardNumber() == number; });
}

BoardContextId PbnFile::getNewBoardContextId()
{
    return this->nextBoardContextId++;
}

const BoardContext &PbnFile::getBoard(BoardNumber number) const
{
    auto board = std::find_if(this->boardContexts.begin(), this->boardContexts.end(),
                              [number](const BoardContext &context)
                              { return context.getBoardNumber() == number; });

    if (board == this->boardContexts.end())
        throw std::out_of_range("File does not contain deal number " + std::to_string(number));
    return *board;
}

const std::vector<BoardContext> &PbnFile::getBoards() const
{
    return this->boardContexts;
}

const std::vector<std::shared_ptr<SemanticPbnToken>> &PbnFile::getTokens() const
{
    return this->tokens;
}

void PbnFile::appendToken(std::shared_ptr<SemanticPbnToken> token)
{
    this->tokens.push_back(token);

    if (!token->isTag())
        return;

    auto tag = std::dynamic_pointer_cast<Tag>(token);

    // We create new board context if 
    // 1) There is no board context yet and the tag creates board context
    // 2) The last board context cannot accept the board
    bool createNew = false;


    if(this->boardContexts.empty() && doesTagHaveToBelongToBoardContext(tag->getTagname()))
        createNew = true;
    else {
        auto& bc = this->boardContexts.back();
        if(!bc.acceptsToken(bc.tokens().size(), tag))
            createNew = true;
    }

    if (createNew)
    {
        auto &new_bc = this->boardContexts.emplace_back(this->getNewBoardContextId(), *this);
        this->BoardContextIdToTokenIndex[new_bc.id] = {this->tokens.size() - 1, 1};
        new_bc.applyTag(tag);
    }
    else
    {
        auto& bc = this->boardContexts.back();

        this->BoardContextIdToTokenIndex[bc.id].TokenCount++;
        bc.applyTag(tag);
    }


}

void PbnFile::insertToken(size_t at, std::shared_ptr<SemanticPbnToken> token)
{
    assert(at < this->tokens.size() && "Insert token: Index out of range");

    for (auto &[id, range] : this->BoardContextIdToTokenIndex)
    {
        if (range.StartIndex >= at)
            range.StartIndex++;
        else if (range.StartIndex + range.TokenCount > at)
        {
            range.TokenCount++;
            if (token->isTag())
                this->boardContexts[id].applyTag(std::dynamic_pointer_cast<Tag>(token));
        }
    }

    this->tokens.insert(this->tokens.begin() + at, token);

    // validate state
    // tokens are always appended to ranges, needs to change to check, whether we dont want to prepend
}

void PbnFile::replaceToken(size_t at, std::shared_ptr<SemanticPbnToken> with)
{
    assert(at < this->tokens.size() && "Replace token: Index out of range");

    auto& from = this->tokens[at];
    auto id = this->findRange(from);
    if (id.has_value())
    {
        if (from->isTag())
        {
            auto tag = std::dynamic_pointer_cast<Tag>(from);
            this->boardContexts[id.value()].unapplyTag(tag);
        }
        if (with->isTag())
        {
            auto tag = std::dynamic_pointer_cast<Tag>(with);
            this->boardContexts[id.value()].applyTag(tag);
        }
    }
    std::swap(from, with);
}

void PbnFile::replaceToken(std::shared_ptr<SemanticPbnToken> from, std::shared_ptr<SemanticPbnToken> to)
{
    auto it = std::find(this->tokens.begin(), this->tokens.end(), from);
    assert( it >= this->tokens.begin() && it < this->tokens.end() && "Replace token: Token not found in token vector");
    this->replaceToken(it - this->tokens.begin(), to);
}

void PbnFile::deleteToken(size_t at)
{
    assert(at < this->tokens.size() && "Delete token: Index out of range");
    this->deleteToken(this->tokens.begin() + at);
}

void PbnFile::deleteToken(std::shared_ptr<SemanticPbnToken> token)
{
    auto it = std::find(this->tokens.begin(), this->tokens.end(), token);
    assert(it != this->tokens.end() && "Delete token: Token not found in token vector");
    this->deleteToken(it);
}

void PbnFile::serialize(std::ostream &stream) const
{
    for (auto &token : this->getTokens())
    {
        token->serialize(stream);
        stream << "\n";
    }
}

void PbnFile::deleteToken(const std::vector<std::shared_ptr<SemanticPbnToken>>::iterator &it)
{
    assert(this->tokens.begin() <= it && it < this->tokens.end() && "Iterator is outside of token vector");

    size_t index = it - this->tokens.begin();
    tokens.erase(it);

    for (auto &[id, range] : this->BoardContextIdToTokenIndex)
    {
        if (range.StartIndex > index)
            range.StartIndex--;
        else if (range.StartIndex <= index && range.StartIndex + range.TokenCount > index)
        {
            range.TokenCount--;
            if ((*it)->isTag())
                this->boardContexts[id].unapplyTag(std::dynamic_pointer_cast<Tag>(*it));
        }
    }
    // TODO validate state
}

std::optional<BoardContextId> PbnFile::findRange(size_t token_index) const
{
    for (auto &[id, range] : this->BoardContextIdToTokenIndex)
    {
        if (range.StartIndex <= token_index && range.StartIndex + range.TokenCount > token_index)
            return {id};
    }
    return {};
}

std::optional<BoardContextId> PbnFile::findRange(std::shared_ptr<SemanticPbnToken> token) const
{
    auto it = std::find(this->tokens.begin(), this->tokens.end(), token);
    assert(it != this->tokens.end() && "Token not found in token vector");
    return this->findRange(it - this->tokens.begin());
}
