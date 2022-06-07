#define BOOST_TEST_MODULE mytests
#include "../include/varray.hpp"
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

BOOST_AUTO_TEST_CASE(varray_operators)
{
    const auto val = std::exp(1.0);
    const auto val2 = 2.0 * val;
    varray<__m256d> v2(2, val);
    v2[1] = val2;

    auto const minus_v2 = -v2;
    BOOST_CHECK_EQUAL(minus_v2[0], -val);
    BOOST_CHECK_EQUAL(minus_v2[1], -val2);

    auto const plus_v2 = +minus_v2;
    BOOST_CHECK_EQUAL(plus_v2[0], -val);
    BOOST_CHECK_EQUAL(plus_v2[1], -val2);

    auto tmp = v2.deepcopy();
    tmp *= 2.0;
    BOOST_CHECK_EQUAL(tmp[0], 2.0 * val);
    BOOST_CHECK_EQUAL(tmp[1], 2.0 * val2);

    auto tmp1 = v2.deepcopy();
    tmp1 /= 2.0;
    BOOST_CHECK_EQUAL(tmp1[0], val / 2.0);
    BOOST_CHECK_EQUAL(tmp1[1], val2 / 2.0);

    auto tmp2 = v2.deepcopy();
    tmp2 += 2.0;
    BOOST_CHECK_EQUAL(tmp2[0], val + 2.0);
    BOOST_CHECK_EQUAL(tmp2[1], val2 + 2.0);

    auto tmp3 = v2.deepcopy();
    tmp3 -= 2.0;
    BOOST_CHECK_EQUAL(tmp3[0], val - 2.0);
    BOOST_CHECK_EQUAL(tmp3[1], val2 - 2.0);

    auto tmp4 = v2.deepcopy();
    varray<__m256d> v_mul(2, val);
    v_mul[1] = val2;
    tmp4 *= v_mul;
    BOOST_CHECK_EQUAL(tmp4[0], val * v_mul[0]);
    BOOST_CHECK_EQUAL(tmp4[1], val2 * v_mul[1]);

    auto tmp5 = v2.deepcopy();
    varray<__m256d> v_div(2, val);
    v_div[1] = val2;
    tmp5 /= v_div;
    BOOST_CHECK_EQUAL(tmp5[0], val / v_div[0]);
    BOOST_CHECK_EQUAL(tmp5[1], val2 / v_div[1]);

    auto tmp6 = v2.deepcopy();
    varray<__m256d> v_add(2, val);
    v_add[1] = val2;
    tmp6 += v_add;
    BOOST_CHECK_EQUAL(tmp6[0], val + v_add[0]);
    BOOST_CHECK_EQUAL(tmp6[1], val2 + v_add[1]);

    auto tmp7 = v2.deepcopy();
    varray<__m256d> v_sub(2, val);
    v_sub[1] = val2;
    tmp7 -= v_sub;
    BOOST_CHECK_EQUAL(tmp7[0], val - v_sub[0]);
    BOOST_CHECK_EQUAL(tmp7[1], val2 - v_sub[1]);
}

BOOST_AUTO_TEST_CASE(varray_slice)
{
    const auto val = std::exp(1.0);
    const auto val2 = 2.0 * val;
    varray<__m256d> v2(10, val);
    v2[1] = val2;
    v2[2] = 2.0 * val2;
    v2[3] = 3.0 * val2;
    v2[4] = 4.0 * val2;
    v2[5] = 5.0 * val2;
    v2[6] = 6.0 * val2;
    v2[7] = 7.0 * val2;
    v2[8] = 8.0 * val2;
    v2[9] = 9.0 * val2;

    varray<__m256d> slice1 = v2[slice(2, 2, 3)];

    BOOST_CHECK_EQUAL(slice1[0], v2[2]);
    BOOST_CHECK_EQUAL(slice1[1], v2[5]);

    decltype(v2) slice2 = v2[slice(0, 5, 2)];

    BOOST_CHECK_EQUAL(slice2[0], v2[0]);
    BOOST_CHECK_EQUAL(slice2[1], v2[2]);
    BOOST_CHECK_EQUAL(slice2[2], v2[4]);
    BOOST_CHECK_EQUAL(slice2[3], v2[6]);
    BOOST_CHECK_EQUAL(slice2[4], v2[8]);

    varray<double> arrs(10);

    arrs[0] = 1.0;
    arrs[1] = 2.0;
    arrs[2] = 3.0;
    arrs[3] = 4.0;
    arrs[4] = 5.0;
    arrs[5] = 6.0;
    arrs[6] = 7.0;
    arrs[7] = 8.0;
    arrs[8] = 9.0;
    arrs[9] = 10.0;

    decltype(arrs) slice3 = arrs[slice(0, 6, 2)];

    BOOST_CHECK_EQUAL(slice3[0], arrs[0]);
    BOOST_CHECK_EQUAL(slice3[1], arrs[2]);
    BOOST_CHECK_EQUAL(slice3[2], arrs[4]);
    BOOST_CHECK_EQUAL(slice3[3], arrs[6]);
    BOOST_CHECK_EQUAL(slice3[4], arrs[8]);
    BOOST_CHECK_SMALL(slice3[5], 0.01);
}

BOOST_AUTO_TEST_CASE(slice_operators)
{
    const auto val = std::exp(1.0);
    const auto val2 = 2.0 * val;
    varray<__m256d> v2(10, val);
    v2[1] = val2;
    v2[2] = 2.0 * val2;
    v2[3] = 3.0 * val2;
    v2[4] = 4.0 * val2;
    v2[5] = 5.0 * val2;
    v2[6] = 6.0 * val2;
    v2[7] = 7.0 * val2;
    v2[8] = 8.0 * val2;
    v2[9] = 9.0 * val2;

    const slice slc1(2, 2, 3);

    varray<__m256d> slice1 = v2[slc1];

    BOOST_CHECK(slc1 == slice(2, 2, 3));

    slice_varray<__m256d> s1 = v2[slc1];
    varray<__m256d> v3(10, -1000.5);

    s1 = v3;

    decltype(v3) v4 = s1;
    BOOST_CHECK_EQUAL(v4[0], v3[0]);
    BOOST_CHECK_EQUAL(v4[1], v3[1]);
}

BOOST_AUTO_TEST_CASE(slice_operators_1)
{
    const auto val = std::exp(1.0);
    const auto val2 = 2.0 * val;
    varray<__m256d> v2(10, val);
    v2[1] = val2;
    v2[2] = 2.0 * val2;
    v2[3] = 3.0 * val2;
    v2[4] = 4.0 * val2;
    v2[5] = 5.0 * val2;
    v2[6] = 6.0 * val2;
    v2[7] = 7.0 * val2;
    v2[8] = 8.0 * val2;
    v2[9] = 9.0 * val2;

    const slice slc1(2, 2, 3);

    varray<__m256d> slice1 = v2[slc1];

    BOOST_CHECK(slc1 == slice(2, 2, 3));

    slice_varray<__m256d> s1 = v2[slc1];

    s1 = -1000.5;

    decltype(v2) v3 = s1;
    BOOST_CHECK_EQUAL(v3[0], -1000.5);
    BOOST_CHECK_EQUAL(v3[1], -1000.5);
}

BOOST_AUTO_TEST_SUITE_END()