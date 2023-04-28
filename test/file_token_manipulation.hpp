#include <boost/test/unit_test.hpp>

#include <sstream>

#include "observer.hpp"
#include "PbnFile.hpp"
#include "SemanticPbnToken.hpp"
#include "BoardContext.hpp"
#include "CustomEscapedLine.hpp"

using namespace tokens;

BOOST_AUTO_TEST_SUITE(PbnFileTests)

BOOST_AUTO_TEST_CASE(TestAppendToken)
{
    auto file = PbnFile();
    auto token = std::make_unique<EmptyLine>();
    auto obs = ptr_to_observer(token);
    file.appendToken(std::move(token));
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file[0] == obs);
}

BOOST_AUTO_TEST_CASE(TestInsertToken)
{
    auto file = PbnFile();
    auto token1 = std::make_unique<Commentary>("Hello comment");
    auto token1obs = ptr_to_observer(token1);
    auto token2 = std::make_unique<EmptyLine>();
    auto token2obs = ptr_to_observer(token2);
    auto token3 = std::make_unique<Tag>("My tag", "3");
    auto token3obs = ptr_to_observer(token3);
    file.appendToken(std::move(token1));
    file.appendToken(std::move(token3));
    file.insertToken(1, std::move(token2));
    BOOST_TEST(file.getTokens().size() == 3);
    BOOST_TEST(file[0] == token1obs);
    BOOST_TEST(file[1] == token2obs);
    BOOST_TEST(file[2] == token3obs);
}

BOOST_AUTO_TEST_CASE(TestDeleteTokenAt)
{
    auto file = PbnFile();
    auto token1 = std::make_unique<Tag>("My tag", "1");
    auto token2 = std::make_unique<EmptyLine>();
     auto token2obs = ptr_to_observer(token2);
    file.appendToken(std::move(token1));
    file.appendToken(std::move(token2));
    file.deleteTokenAt(0);
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file[0] == token2obs);
}

BOOST_AUTO_TEST_CASE(TestReplaceToken)
{
    auto file = PbnFile();
    auto token1 = std::make_unique<CustomEscapedLine>("Mycrypticline");
     auto token1obs = ptr_to_observer(token1);
    auto token2 = std::make_unique<Commentary>("Hello comment \n twice as many lines");
    auto token3 = std::make_unique<Tag>("MyTag", "values");
     auto token3obs = ptr_to_observer(token3);
    file.appendToken(std::move(token1));
    file.appendToken(std::move(token2));
    file.replaceToken(1, std::move(token3));
    BOOST_TEST(file.getTokens().size() == 2);
    BOOST_TEST(file[0] == token1obs);
    BOOST_TEST(file[1] == token3obs);
}

BOOST_AUTO_TEST_CASE(TestDeleteTokenByPointer)
{
    auto file = PbnFile();
    auto token1 = std::make_unique<Tag>("MyTag", "values");
     auto token1obs = ptr_to_observer(token1);
    auto token2 = std::make_unique<EmptyLine>();
     auto token2obs = ptr_to_observer(token2);
    file.appendToken(std::move(token1));
    file.appendToken(std::move(token2));
    file.deleteToken(token1obs);
    BOOST_TEST(file.getTokens().size() == 1);
    BOOST_TEST(file[0] == token2obs);
}

BOOST_AUTO_TEST_CASE(SerializationTest)
{
    // Create a PbnFile object and add some tokens
    PbnFile pbnFile;

    pbnFile.appendToken(std::make_unique<Tag>("MyTag", "values"));
    pbnFile.appendToken(std::make_unique<EmptyLine>());
    pbnFile.appendToken(std::make_unique<Tag>("MyTagOther", "values 2"));
    pbnFile.appendToken(std::make_unique<EmptyLine>());
    pbnFile.appendToken(std::make_unique<CustomEscapedLine>(" Mycrypticline"));

    // Serialize the PbnFile object to a stringstream
    std::stringstream ss;
    pbnFile.serialize(ss);

    // Verify that the serialized string matches the expected output
    BOOST_CHECK_EQUAL(ss.str(), "[MyTag \"values\"]\n\n[MyTagOther \"values 2\"]\n\n% Mycrypticline\n");
}

BOOST_AUTO_TEST_SUITE_END()
