
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s);
void split(const std::string& s, std::vector<std::string>& into);

// trim from start (in place)
void ltrim(std::string &s);

// trim from end (in place)
void rtrim(std::string &s);

// trim from both ends (in place)
void trim(std::string &s);