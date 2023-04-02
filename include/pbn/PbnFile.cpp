#include "PbnFile.h"
#include "Tag.h"
#include "TableTag.h"
#include "Tags.h"

#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>




bool PbnFile::hasBoardWithNumber(BoardNumber number) const
{

    return std::any_of(this->boardContexts.begin(), this->boardContexts.end(), [number](const BoardContext &context)
                       { return context.getBoardNumber() == number; });
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

    if (tag->getTagname() == tags::BOARD)
    {
        auto number = std::stoi(tag->getContent());
        auto& board = this->boardContexts.emplace_back(number, *this);
        this->BoardContextIdToTokenIndex[board.id] = { this->tokens.size() - 1, 1 };
    }
    else if (this->boardContexts.size() > 0)
    {
        auto& bc = this->boardContexts.back();
        this->BoardContextIdToTokenIndex[bc.id].TokenCount++;
        bc.applyTag(tag);   
    }
}

void PbnFile::insertToken(size_t at, std::shared_ptr<SemanticPbnToken> token)
{
    throw std::runtime_error("Inserting tokens not supported yet");
    this->tokens.insert(this->tokens.begin() + at, token);
}

void PbnFile::replaceToken(size_t at, std::shared_ptr<SemanticPbnToken> with)
{
    throw std::runtime_error("Replacing tokens not supported yet");
    // TODO
}

void PbnFile::replaceToken(std::shared_ptr<SemanticPbnToken> from, std::shared_ptr<SemanticPbnToken> to)
{
    throw std::runtime_error("Replacing tokens not supported yet");
    // TODO
}

void PbnFile::deleteToken(size_t at)
{
    throw std::runtime_error("Deleting tokens not supported yet");
    // TODO
}

void PbnFile::deleteToken(std::shared_ptr<SemanticPbnToken> token)
{
    throw std::runtime_error("Deleting tokens not supported yet");
    // TODO
}

void PbnFile::serialize(std::ostream &stream) const
{
    for (auto &token : this->getTokens())
    {
        token->serialize(stream);
    }
}

