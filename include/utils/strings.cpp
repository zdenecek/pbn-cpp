#include "strings.h"

#include <algorithm>
#include <cctype>
#include <locale>
#include <vector>

// split copied from source
// https://stackoverflow.com/questions/8425214/splitting-string-into-a-vectorstring-of-words
void split(const std::string &s, std::vector<std::string> &into) {
    using string_size = std::string::size_type ;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size())
    {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j)is a space
        while (j != s.size() && !isspace(s[j]))
            j++;
        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            into.push_back(s.substr(i, j - i));
            i = j;
        }
    }
}

std::vector<std::string> split(const std::string &s) {
    std::vector<std::string> into;
    split(s, into);
    return into;
}

// trims copied from
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

