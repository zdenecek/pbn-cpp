// using static library
#include <boost/test/unit_test.hpp>

#include "PbnParser.h"

#include "EmptyLine.h"
#include "Commentary.h"

#include <string>
#include <sstream>
#include <istream>

using namespace tokens;
using namespace std;

struct ParserTest
{

    friend class PbnParser;

    PbnParser parser;

    auto parseToken(const std::string &line)
    {
        auto l = line;
        std::istringstream s;
        return parser.parseToken(l, s, true);
    }

    auto parseToken(std::string &line, std::istream &inputstream)
    {
        return parser.parseToken(line, inputstream, true);
    }

    auto parseToken(std::string &line)
    {
        std::istringstream ss;
        return parser.parseToken(line, ss, true);
    }

    template <typename T, typename... U>
        requires requires { T::typeName; } bool
    testCreatedTokenType(U &&...args)
    {
        return parseToken(args...)->getTypeName() == T::typeName;
    }

    ParserTest() : parser() {}

    ~ParserTest() = default;
};

BOOST_FIXTURE_TEST_SUITE(BasicParsing, ParserTest)

BOOST_AUTO_TEST_CASE(emptyLine)
{
    BOOST_CHECK(testCreatedTokenType<EmptyLine>(""s));
    BOOST_CHECK(testCreatedTokenType<EmptyLine>(" "s));
    BOOST_CHECK(testCreatedTokenType<EmptyLine>("    "s));
    BOOST_CHECK(!testCreatedTokenType<EmptyLine>("a"s));
}

BOOST_AUTO_TEST_CASE(parseTagWithTrailingText)
{
    string line = "[ Tag \"\" ]test";
    BOOST_CHECK(testCreatedTokenType<Tag>(line));
    BOOST_CHECK_EQUAL(line, string("test"));
}

BOOST_AUTO_TEST_CASE(parseTagWithLeadingWhitespace)
{
    string line = " [ Tag \"Value\" ] test";
    BOOST_CHECK(testCreatedTokenType<Tag>(line));
    BOOST_CHECK_EQUAL(line, string("test"));
}

BOOST_AUTO_TEST_CASE(parseTagWithLeadingAndTrailingWhitespace)
{
    string line = " [ Tag \"Value\" ] test ";
    BOOST_CHECK(testCreatedTokenType<Tag>(line));
    BOOST_CHECK_EQUAL(line, string("test "));
}

BOOST_AUTO_TEST_CASE(parseTagWithEmptyAttributeValue)
{
    string line = "[Tag \"\"]";
    BOOST_CHECK(testCreatedTokenType<Tag>(line));
}

BOOST_AUTO_TEST_CASE(parseTagWithAttributeValue)
{
    string line = "[Tag \" value \"]";
    BOOST_CHECK(testCreatedTokenType<Tag>(line));
}


BOOST_AUTO_TEST_CASE(parseSingleLineComment)
{
    BOOST_CHECK(testCreatedTokenType<Commentary>("; This is a single line comment"));
}

BOOST_AUTO_TEST_CASE(parseMultiLineComment)
{
    string line = "{";
    istringstream s ("This is\na\nmulti-line comment }");
    BOOST_CHECK(testCreatedTokenType<Commentary>(line, s));
}

BOOST_AUTO_TEST_CASE(noNestedMultiline)
{
    string line = "{ {";
    istringstream s (" { { This is\na\nmulti-line comment }");
    BOOST_CHECK(testCreatedTokenType<Commentary>(line, s));
}

BOOST_AUTO_TEST_SUITE_END()