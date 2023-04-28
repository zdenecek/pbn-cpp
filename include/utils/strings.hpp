#pragma once

#include <vector>
#include <string>
#include <functional>


/**
 * @brief Split a string into a vector of strings by spaces
 *
 * Does not produce empty strings
 *
 * @param string The string to split
 * @return The vector of strings
 */
std::vector<std::string> split_str(const std::string &string);

/**
 * @brief Split a string into a vector of strings by provided delimiter character
 *
 * Does not produce empty strings
 *
 * @param string The string to split
 * @param delim The delimiter character
 * @return The vector of strings
 */
std::vector<std::string> split_str(const std::string &string, char delim);

/**
 * @brief Split a string into a vector of strings by provided delimiter function
 *
 * Does not produce empty strings
 *
 * @param string The string to split
 * @param is_delim The function that returns true if the character is a delimiter
 * @return The vector of strings
 */
std::vector<std::string> split_str(const std::string &string, std::function<bool(char)> is_delim);

/**
 * @brief Split a string into a vector of strings by spaces and saves them into a vector
 *
 * Does not produce empty strings
 *
 * @param string The string to split
 * @param into[out] The vector to put the strings into
 */
void split_str(const std::string &string, std::vector<std::string> &into);

/**
 * @brief Split a string into a vector of strings by provided delimiter function and saves them into a vector
 *
 * Does not produce empty strings
 *
 * @param string The string to split
 * @param is_delim The function that returns true if the character is a delimiter
 * @param into[out] The vector to put the strings into
 */
void split_str(const std::string &string, std::vector<std::string> &into, std::function<bool(char)> is_delim);

/**
 * @brief Left trim a string, remove whitespace from the beginning.
 *
 * @param string The string to trim
 */
void ltrim(std::string &string);

/**
 * @brief Right trim a string, remove trailing whitespace from the end.
 *
 * @param string The string to trim
 */
void rtrim(std::string &string);

/**
 * @brief Trim a string, remove whitespace from the end and the beginning.
 *
 * @param string The string to trim
 */
void trim(std::string &string);