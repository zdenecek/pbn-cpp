#include "BoardTag.h"
#include "Tags.h"

namespace tokens
{

    BoardTag::BoardTag(std::string value) : Tag(std::string(tokens::tags::BOARD), value), boardNumber(std::stoi(value))
    {
    }

    BoardTag::BoardTag(BoardNumber number) : Tag(std::string(tokens::tags::BOARD), std::to_string(number)), boardNumber(number)
    {
    }

    BoardNumber BoardTag::getBoardNumber() const
    {
        return this->boardNumber;
    }

    void BoardTag::setBoardNumber(BoardNumber number)
    {
        this->boardNumber = number;
        this->content = std::to_string(number);
    }
}