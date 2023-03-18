
#include <vector>
#include <string>


using namespace std;

vector<string> split(const string& s);
void split(const string& s, vector<string>& into);

// trim from start (in place)
void ltrim(std::string &s);

// trim from end (in place)
void rtrim(std::string &s);

// trim from both ends (in place)
void trim(std::string &s);