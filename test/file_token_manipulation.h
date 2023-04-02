#include <boost/test/unit_test.hpp>

#include <sstream>

#include "PbnFile.h"
#include "SemanticPbnToken.h"
#include "BoardContext.h"
#include "CustomEscapedLine.h"

using namespace tokens;

BOOST_AUTO_TEST_SUITE(PbnFileTests)

BOOST_AUTO_TEST_CASE(TestAppendToken)
{
    auto file = PbnFile();
    auto token = std::make_shared<EmptyLine>();
    file.appendToken(token);
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file.getTokens()[0] == token);
}

BOOST_AUTO_TEST_CASE(TestInsertToken)
{
    auto file = PbnFile();
    auto token1 = std::make_shared<Commentary>("Hello comment");
    auto token2 = std::make_shared<EmptyLine>();
    auto token3 = std::make_shared<Tag>("My tag", "3");
    file.appendToken(token1);
    file.appendToken(token3);
    file.insertToken(1, token2);
    BOOST_TEST(file.getTokens().size() == 3);
    BOOST_TEST(file.getTokens()[0] == token1);
    BOOST_TEST(file.getTokens()[1] == token2);
    BOOST_TEST(file.getTokens()[2] == token3);
}

BOOST_AUTO_TEST_CASE(TestDeleteToken)
{
    auto file = PbnFile();
    auto token1 = std::make_shared<Tag>("My tag", "1");
    auto token2 = std::make_shared<EmptyLine>();
    file.appendToken(token1);
    file.appendToken(token2);
    file.deleteToken(0);
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file.getTokens()[0] == token2);
}

BOOST_AUTO_TEST_CASE(TestReplaceToken)
{
    auto file = PbnFile();
    auto token1 = std::make_shared<CustomEscapedLine>("Mycrypticline");
    auto token2 = std::make_shared<Commentary>("Hello comment \n twice as many lines");
    auto token3 = std::make_shared<Tag>("MyTag", "values");
    file.appendToken(token1);
    file.appendToken(token2);
    file.replaceToken(1, token3);
    BOOST_TEST(file.getTokens().size() == 2);
    BOOST_TEST(file.getTokens()[0] == token1);
    BOOST_TEST(file.getTokens()[1] == token3);
}

BOOST_AUTO_TEST_CASE(TestDeleteTokenByPointer)
{
    auto file = PbnFile();
    auto token1 = std::make_shared<Tag>("MyTag", "values");
    auto token3 = std::make_shared<Tag>("MyTagOther", "values 2");
    auto token2 = std::make_shared<EmptyLine>();
    file.appendToken(token1);
    file.appendToken(token2);
    file.deleteToken(token1);
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file.getTokens()[0] == token2);
}

BOOST_AUTO_TEST_CASE(SerializationTest)
{
    // Create a PbnFile object and add some tokens
    PbnFile pbnFile;

    pbnFile.appendToken(std::make_shared<Tag>("MyTag", "values"));
    pbnFile.appendToken(std::make_shared<EmptyLine>());
    pbnFile.appendToken(std::make_shared<Tag>("MyTagOther", "values 2"));
    pbnFile.appendToken(std::make_shared<EmptyLine>());
    pbnFile.appendToken(std::make_shared<CustomEscapedLine>(" Mycrypticline"));

    // Serialize the PbnFile object to a stringstream
    std::stringstream ss;
    pbnFile.serialize(ss);

    // Verify that the serialized string matches the expected output
    BOOST_CHECK_EQUAL(ss.str(), "[MyTag \"values\"]\n\n[MyTagOther \"values 2\"]\n\n% Mycrypticline\n");
}


BOOST_AUTO_TEST_SUITE_END()
