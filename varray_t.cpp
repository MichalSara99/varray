#define BOOST_TEST_MODULE mytests
#include "include/varray.hpp"
#include <boost/test/included/unit_test.hpp>
#include <immintrin.h>

BOOST_AUTO_TEST_SUITE(varray_tests)

BOOST_AUTO_TEST_CASE(varray_ctors)
{
    const auto val = 3.1415f;
    varray<__m256> v0(7, _mm256_set1_ps(val));

    BOOST_CHECK_EQUAL(v0.size(), 7);
    BOOST_CHECK_EQUAL(v0.length_type, 8);
    BOOST_CHECK_EQUAL(v0.vsize(), 1);
    BOOST_CHECK_EQUAL(v0[0], val);
    BOOST_CHECK_EQUAL(v0[1], val);
    BOOST_CHECK_EQUAL(v0[2], val);
    BOOST_CHECK_EQUAL(v0[3], val);
    BOOST_CHECK_EQUAL(v0[4], val);
    BOOST_CHECK_EQUAL(v0[5], val);
    BOOST_CHECK_EQUAL(v0[6], val);

    const auto val1 = 212346.789;
    varray<__m256d> v1(10, val1);

    BOOST_CHECK_EQUAL(v1.size(), 10);
    BOOST_CHECK_EQUAL(v1.length_type, 4);
    BOOST_CHECK_EQUAL(v1.vsize(), 3);
    BOOST_CHECK_EQUAL(v1[0], val1);
    BOOST_CHECK_EQUAL(v1[1], val1);
    BOOST_CHECK_EQUAL(v1[2], val1);
    BOOST_CHECK_EQUAL(v1[3], val1);
    BOOST_CHECK_EQUAL(v1[4], val1);
    BOOST_CHECK_EQUAL(v1[5], val1);
    BOOST_CHECK_EQUAL(v1[6], val1);
    BOOST_CHECK_EQUAL(v1[7], val1);
    BOOST_CHECK_EQUAL(v1[8], val1);
    BOOST_CHECK_EQUAL(v1[9], val1);

    const auto val2 = std::exp(1.0);
    varray<double> v2(11, val2);

    BOOST_CHECK_EQUAL(v2.size(), 11);
    BOOST_CHECK_EQUAL(v2.length_type, 1);
    BOOST_CHECK_EQUAL(v2.vsize(), 11);
    BOOST_CHECK_EQUAL(v2[0], val2);
    BOOST_CHECK_EQUAL(v2[1], val2);
    BOOST_CHECK_EQUAL(v2[2], val2);
    BOOST_CHECK_EQUAL(v2[3], val2);
    BOOST_CHECK_EQUAL(v2[4], val2);
    BOOST_CHECK_EQUAL(v2[5], val2);
    BOOST_CHECK_EQUAL(v2[6], val2);
    BOOST_CHECK_EQUAL(v2[7], val2);
    BOOST_CHECK_EQUAL(v2[8], val2);
    BOOST_CHECK_EQUAL(v2[9], val2);
    BOOST_CHECK_EQUAL(v2[10], val2);
}

BOOST_AUTO_TEST_SUITE_END()
