#pragma once

#include <string>
#include <memory>
#include <vector>
#include <ranges>
#include <span>

#include "tokens/Tag.hpp"
#include "BoardNumber.hpp"
#include "SemanticPbnToken.hpp"
#include "observer.hpp"


/* Identification section is defined as follows:
 (1) Event      (the name of the tournament or match)
 (2) Site       (the location of the event)
 (3) Date       (the starting date of the game)
 (4) Board      (the board number)
 (5) West       (the west player)
 (6) North      (the north player)
 (7) East       (the east player)
 (8) South      (the south player)
 (9) Dealer     (the dealer)
(10) Vulnerable (the situation of vulnerability)
(11) Deal       (the dealt cards)
(12) Scoring    (the scoring method)
(13) Declarer   (the declarer of the contract)
(14) Contract   (the contract)
(15) Result     (the result of the game)
*/

using tokens::SemanticPbnToken;
using tokens::Tag;

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
    BoardNumber boardNumber = 0;
    PbnFile &pbnFile;

    /// @brief Apply the given token to this context. Used to validate file state.
    void applyTag(observer_ptr<Tag> token);
    /// @brief Remove tag from this context. Used to validate file state.
    void unapplyTag(observer_ptr<Tag> token);
    
    bool acceptsToken(size_t atIndex, observer_ptr<SemanticPbnToken> token) const;

public:
    
    BoardContext(BoardContextId id, PbnFile &pbnFile) : id(id), pbnFile(pbnFile) {}
    
    /// @brief Returns the board number of this context.
    [[nodiscard]] BoardNumber getBoardNumber() const;

    /**
     * @brief Returns the tokens that are part of this context.
     * Invalidates when a token is added or removed from this context.
     * @return A span of tokens.
     */
    [[nodiscard]] std::span<std::unique_ptr<tokens::SemanticPbnToken>> tokens() const;
};
