#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <ostream>
#include <tuple>
#include <optional>
#include <ranges>


#include "observer.h"
#include "tokens/SemanticPbnToken.h"
#include "BoardContext.h"
#include "PbnVersion.h"

using tokens::SemanticPbnToken;

/// @brief Represents a .pbn file
class PbnFile
{
    friend class BoardContext;
    friend class Debug;

public:
    PbnFile() : tokens(), boardContexts(), BoardContextIdToTokenIndex() {}

    /**
     * @brief Returns all boards contexts in the file.
     *
     * @see BoardContext
     */
    [[nodiscard]] const std::vector<BoardContext> &getBoards() const;

    /// @brief return true if the file is in EXPORT format and contains the export directive.
    [[nodiscard]] bool isExportFormat() const;

    /// @brief Returns true if at least one board with the given number is present in the file.
    [[nodiscard]] bool hasBoardWithNumber(BoardNumber number) const;

    /**
     * @brief Returns the deal with the given number.
     * @throws std::out_of_range if the file does not contain a deal with the given number.
     */
    [[nodiscard]] const BoardContext &getBoard(BoardNumber number) const;

    /**
     * @brief All the tokens of a file
     */
    [[nodiscard]] const std::vector<std::unique_ptr<SemanticPbnToken>> &getTokens() const;

    /**
     * @brief Returns observer ptr of the token at specified index.
     * @param index Index of the token.
     * @throws std::out_of_range_error if the index is out of range.
     */
   const observer_ptr<SemanticPbnToken> operator[](size_t index) const;

    /**
     * @brief Appends a token to the end of the file.
     *
     * @param token The token to append.
     */
    void appendToken(std::unique_ptr<SemanticPbnToken>&& token);

    /**
     * @brief Inserts a token at the given index.
     *
     * @param at
     * @param token
     */
    void insertToken(size_t at, std::unique_ptr<SemanticPbnToken>&& token);

    /**
     * @brief Deletes the token at the given index.
     *
     * @param at The index of the token to delete.
     * @throws std::out_of_range_error if the index is out of range.
     */
    void deleteTokenAt(size_t at);

    /**
     * @brief Replaces the token at the given index with the given token.
     *
     * @param at The index of the token to be replaced.
     * @param with Shared pointer to the new token to be used as replacement
     */
    void replaceToken(size_t at, std::unique_ptr<SemanticPbnToken>&& with);

    /**
     * @brief Replaces the given token  with the given token.
     *
     * @param from Shared pointer to the old token.
     * @param to Shared pointer to the new token to be used as replacement.
     */
    void replaceToken(observer_ptr<SemanticPbnToken> from, std::unique_ptr<SemanticPbnToken>&& to);

    /**
     * @brief Delete given token
     * Does nothing if token is not in the file.
     * @param token shared pointer to the token to delete, the token has to be the same object in the memory.
     */
    void deleteToken(observer_ptr<SemanticPbnToken> token);

    /**
     * @brief Print file contents to the stream in export format;
     * @param stream Stream to print to.
     */
    void serialize(std::ostream &stream) const;

private:
    /// @brief All tokens in the file.
    std::vector<std::unique_ptr<SemanticPbnToken>> tokens;

    /// @brief All board contexts in the file.
    std::vector<BoardContext> boardContexts;

    PbnVersion version = PbnVersion::NotSpecified;
    bool isExport = false;
    
    BoardContextId nextBoardContextId = 0;

    BoardContextId getNewBoardContextId();

    /// @brief Maps board context id to token ranges, tuples represent in order: start index, number of tokens
    struct TokenRange
    {
        /// @brief Index of the first token in the range in the tokens vector.
        size_t StartIndex;
        /// @brief Number of tokens in the range, starting at 1.
        size_t TokenCount;
    };

    /// @brief Maps board context id to token ranges, tuples represent in order: start index, number of tokens
    std::map<BoardContextId, TokenRange>
        BoardContextIdToTokenIndex;

    /// @brief Returns the range of the token at the given index.
    std::optional<BoardContextId> findRange(size_t token_index) const;
    /// @brief Returns the range of the token given.
    std::optional<BoardContextId> findRange(observer_ptr<SemanticPbnToken> token) const;

    auto rangeTokens(BoardContextId id) const;

    /**
     * @brief Delete given token
     * Does nothing if token is not in the file.
     */
    void deleteToken(const std::vector<std::unique_ptr<SemanticPbnToken>>::iterator &it);
};
