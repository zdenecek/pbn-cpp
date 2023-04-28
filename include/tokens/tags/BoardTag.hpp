
#include "Tag.hpp"
#include "BoardNumber.hpp"

#include <string>
#include <vector>
#include <memory>

namespace tokens
{
    
    class BoardTag : public Tag
    {
    private:
        BoardNumber boardNumber;

    public:
        BoardTag(std::string value);
        BoardTag(BoardNumber number);

        BoardNumber getBoardNumber() const;
        void setBoardNumber(BoardNumber number);
    };
}