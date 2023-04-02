#pragma once

#include <string>
#include <memory>
#include <vector>

#include "tokens/Tag.h"

using tokens::SemanticPbnToken;
using tokens::Tag;

/// @brief Represent board number in the game of bridge
using BoardNumber = size_t;

/// @brief Represent type of internal type id. Id is used to identify a board context at runtime and is never persisted.
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

    /// @brief Apply the given token to this context. Used to validate file state.
    void applyTag(std::shared_ptr<Tag> token);
    /// @brief Remove tag from this context. Used to validate file state.
    void unapplyTag(std::shared_ptr<Tag> token);

public:
    BoardContext(BoardNumber boardNumber, PbnFile &pbnFile) : boardNumber(boardNumber), pbnFile(pbnFile)
    {
        initId();
    }
    explicit BoardContext(PbnFile &pbnFile) : BoardContext(0, pbnFile) {}

    /// @brief Returns the board number of this context.
    [[nodiscard]] BoardNumber getBoardNumber() const;

    /// @brief A context_tokens object is used to iterate over all tokens in a context.
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

    /// @brief Returns a context_tokens object that can be used to iterate over all tokens in this context.
    [[nodiscard]] context_tokens getTokens() const;
};
