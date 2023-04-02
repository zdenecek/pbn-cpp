#define BOOST_TEST_MODULE BasicTest
// using static library
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(VariantsSuite)

BOOST_AUTO_TEST_CASE(checkPass)
{
    
}

BOOST_AUTO_TEST_CASE(checkFailure)
{
    BOOST_CHECK(4 == 5);
}

BOOST_AUTO_TEST_SUITE_END()