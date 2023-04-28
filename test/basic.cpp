#define BOOST_TEST_MODULE Tests
// using static library
#include <boost/test/unit_test.hpp>

#include "PbnParser.hpp"
#include "PbnParser.hpp"

// Other test are included at the end of this file

BOOST_AUTO_TEST_SUITE(BasicSuite)

BOOST_AUTO_TEST_CASE(checkFileCanBeInstantiated)
{
    PbnFile file;
}

BOOST_AUTO_TEST_CASE(checkParserCanBeInstantiated)
{
    PbnParser p;
}

BOOST_AUTO_TEST_SUITE_END()

#include "parser.hpp"
#include "file_token_manipulation.hpp"
