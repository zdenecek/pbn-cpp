#pragma once

#include <array>

// https://stackoverflow.com/questions/45287195/combine-two-or-more-arrays-of-different-size-to-one-array-at-compiletime
/// @brief Concatenates two arrays. 
template <typename T, std::size_t N1, std::size_t N2>
constexpr std::array<T, N1 + N2> concat(std::array<T, N1> lhs, std::array<T, N2> rhs)
{
    std::array<T, N1 + N2> result{};
    std::size_t index = 0;

    for (auto& el : lhs) {
        result[index] = std::move(el);
        ++index;
    }
    for (auto& el : rhs) {
        result[index] = std::move(el);
        ++index;
    }

    return result;
}
