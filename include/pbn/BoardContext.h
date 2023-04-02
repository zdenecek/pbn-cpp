#pragma once

#include <string>
#include <memory>
#include <vector>

#include "tokens/Tag.h"

using tokens::Tag;
using tokens::SemanticPbnToken;

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
    void initId();
    void applyTag(std::shared_ptr<Tag> token);
    void unapplyTag(std::shared_ptr<Tag> token);

public:
    BoardContext(BoardNumber boardNumber, PbnFile &pbnFile) : boardNumber(boardNumber), pbnFile(pbnFile) {
        initId();
    }
    explicit BoardContext(PbnFile &pbnFile) : BoardContext(0, pbnFile) {}

    [[nodiscard]] BoardNumber getBoardNumber() const;

    struct context_tokens
    {
        friend class BoardContext;
        friend class PbnFile;

    private:
        const BoardContext &context;
        explicit context_tokens(const BoardContext &context) : context(context) {}

    public:
        std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator begin();
        std::vector<std::shared_ptr<SemanticPbnToken>>::const_iterator end();
    };

    [[nodiscard]] context_tokens getTokens() const;
};

