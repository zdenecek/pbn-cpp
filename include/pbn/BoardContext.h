#pragma once

#include <string>
#include <memory>
#include <vector>

#include "tokens/Tag.h"

using BoardNumber = size_t;
using BoardContextId = size_t;

class PbnFile;

/// @brief A BoardContext is a collection of tags in a PbnFile that are relevant for a single board.
class BoardContext
{
    friend class PbnFile;
    friend class Debug;

private:
    BoardContextId id;
    BoardNumber boardNumber;
    PbnFile &pbnFile;
    void applyTag(std::shared_ptr<Tag> token);
    void initId();

public:
    std::shared_ptr<Tag> boardTag;

    /// @brief Pointer to the deal tag
    /// Stored here for convenience
    std::shared_ptr<Tag> dealTag;

    BoardContext(BoardNumber boardNumber, PbnFile &pbnFile) : boardNumber(boardNumber), pbnFile(pbnFile) {
        initId();
    }
    explicit BoardContext(PbnFile &pbnFile) : BoardContext(0, pbnFile) {}

    [[nodiscard]] BoardNumber getBoardNumber() const;

    struct tokens
    {
        friend class BoardContext;
        friend class PbnFile;

    private:
        const BoardContext &context;
        explicit tokens(const BoardContext &context) : context(context) {}

    public:
        std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator begin();
        std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator end();
    };

    [[nodiscard]] tokens getTokens() const;
};
