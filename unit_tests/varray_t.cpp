#define BOOST_TEST_MODULE varray_unit_tests
#include "../include/varray.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(varray_tests)

BOOST_AUTO_TEST_CASE(varray_ctors)
{
    // const auto val = 3.1415f;
    // varray<vsf8> v0(7, val);

    // BOOST_CHECK_EQUAL(v0.size(), 7);
    // BOOST_CHECK_EQUAL(v0.element_length, 8);
    // BOOST_CHECK_EQUAL(v0.vsize(), 1);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(0), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(1), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(2), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(3), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(4), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(5), val);
    //  BOOST_CHECK_EQUAL(v0.scalar_at(6), val);

    // const auto val1 = 212346.789;
    // varray<vsd4> v1(10, val1);

    // BOOST_CHECK_EQUAL(v1.size(), 10);
    // BOOST_CHECK_EQUAL(v1.element_length, 4);
    // BOOST_CHECK_EQUAL(v1.vsize(), 3);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(0), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(1), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(2), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(3), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(4), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(5), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(6), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(7), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(8), val1);
    //  BOOST_CHECK_EQUAL(v1.scalar_at(9), val1);

    // const auto val2 = std::exp(1.0);
    // varray<double> v2(11, val2);

    // BOOST_CHECK_EQUAL(v2.size(), 11);
    //  BOOST_CHECK_EQUAL(v2.element_length, 1);
    //  BOOST_CHECK_EQUAL(v2.vsize(), 11);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(0), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(1), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(2), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(3), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(4), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(5), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(6), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(7), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(8), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(9), val2);
    //   BOOST_CHECK_EQUAL(v2.scalar_at(10), val2);
}

// BOOST_AUTO_TEST_CASE(varray_operators)
//{
//     const auto val = std::exp(1.0);
//     const auto val2 = 2.0 * val;
//     varray<__m256d> v2(2, val);
//     v2[1] = val2;
//
//     auto const minus_v2 = -v2;
//     BOOST_CHECK_EQUAL(minus_v2[0], -val);
//     BOOST_CHECK_EQUAL(minus_v2[1], -val2);
//
//     auto const plus_v2 = +minus_v2;
//     BOOST_CHECK_EQUAL(plus_v2[0], -val);
//     BOOST_CHECK_EQUAL(plus_v2[1], -val2);
//
//     auto tmp = v2.deepcopy();
//     tmp *= 2.0;
//     BOOST_CHECK_EQUAL(tmp[0], 2.0 * val);
//     BOOST_CHECK_EQUAL(tmp[1], 2.0 * val2);
//
//     auto tmp1 = v2.deepcopy();
//     tmp1 /= 2.0;
//     BOOST_CHECK_EQUAL(tmp1[0], val / 2.0);
//     BOOST_CHECK_EQUAL(tmp1[1], val2 / 2.0);
//
//     auto tmp2 = v2.deepcopy();
//     tmp2 += 2.0;
//     BOOST_CHECK_EQUAL(tmp2[0], val + 2.0);
//     BOOST_CHECK_EQUAL(tmp2[1], val2 + 2.0);
//
//     auto tmp3 = v2.deepcopy();
//     tmp3 -= 2.0;
//     BOOST_CHECK_EQUAL(tmp3[0], val - 2.0);
//     BOOST_CHECK_EQUAL(tmp3[1], val2 - 2.0);
//
//     auto tmp4 = v2.deepcopy();
//     varray<__m256d> v_mul(2, val);
//     v_mul[1] = val2;
//     tmp4 *= v_mul;
//     BOOST_CHECK_EQUAL(tmp4[0], val * v_mul[0]);
//     BOOST_CHECK_EQUAL(tmp4[1], val2 * v_mul[1]);
//
//     auto tmp5 = v2.deepcopy();
//     varray<__m256d> v_div(2, val);
//     v_div[1] = val2;
//     tmp5 /= v_div;
//     BOOST_CHECK_EQUAL(tmp5[0], val / v_div[0]);
//     BOOST_CHECK_EQUAL(tmp5[1], val2 / v_div[1]);
//
//     auto tmp6 = v2.deepcopy();
//     varray<__m256d> v_add(2, val);
//     v_add[1] = val2;
//     tmp6 += v_add;
//     BOOST_CHECK_EQUAL(tmp6[0], val + v_add[0]);
//     BOOST_CHECK_EQUAL(tmp6[1], val2 + v_add[1]);
//
//     auto tmp7 = v2.deepcopy();
//     varray<__m256d> v_sub(2, val);
//     v_sub[1] = val2;
//     tmp7 -= v_sub;
//     BOOST_CHECK_EQUAL(tmp7[0], val - v_sub[0]);
//     BOOST_CHECK_EQUAL(tmp7[1], val2 - v_sub[1]);
// }
//
// BOOST_AUTO_TEST_CASE(varray_math)
//{
//     const auto val = -1.0 * std::exp(1.0);
//     const auto val2 = -2.0 * val;
//     varray<double> v2(2, val);
//     v2[1] = val2;
//     // abs
//     auto const v2_abs = abs(v2);
//     BOOST_CHECK_EQUAL(v2_abs[0], -val);
//     BOOST_CHECK_EQUAL(v2_abs[1], val2);
//
//     v2[0] = 0.854;
//     v2[1] = -0.98;
//     // acos
//     auto const v2_acos = acos(v2);
//     BOOST_CHECK_EQUAL(v2_acos[0], std::acos(v2[0]));
//     BOOST_CHECK_EQUAL(v2_acos[1], std::acos(v2[1]));
//
//     // asin
//     auto const v2_asin = asin(v2);
//     BOOST_CHECK_EQUAL(v2_asin[0], std::asin(v2[0]));
//     BOOST_CHECK_EQUAL(v2_asin[1], std::asin(v2[1]));
//
//     // atan
//     auto const v2_atan = atan(v2);
//     BOOST_CHECK_EQUAL(v2_atan[0], std::atan(v2[0]));
//     BOOST_CHECK_EQUAL(v2_atan[1], std::atan(v2[1]));
//
//     // cos
//     auto const v2_cos = cos(v2);
//     BOOST_CHECK_EQUAL(v2_cos[0], std::cos(v2[0]));
//     BOOST_CHECK_EQUAL(v2_cos[1], std::cos(v2[1]));
//
//     // cosh
//     auto const v2_cosh = cosh(v2);
//     BOOST_CHECK_EQUAL(v2_cosh[0], std::cosh(v2[0]));
//     BOOST_CHECK_EQUAL(v2_cosh[1], std::cosh(v2[1]));
//
//     // exp
//     auto const v2_exp = exp(v2);
//     BOOST_CHECK_EQUAL(v2_exp[0], std::exp(v2[0]));
//     BOOST_CHECK_EQUAL(v2_exp[1], std::exp(v2[1]));
//
//     // log
//     v2[1] = 1.0;
//     auto const v2_log = log(v2);
//     BOOST_CHECK_EQUAL(v2_log[0], std::log(v2[0]));
//     BOOST_CHECK_EQUAL(v2_log[1], std::log(v2[1]));
//
//     // log10
//     auto const v2_log10 = log10(v2);
//     BOOST_CHECK_EQUAL(v2_log10[0], std::log10(v2[0]));
//     BOOST_CHECK_EQUAL(v2_log10[1], std::log10(v2[1]));
//
//     // pow
//     varray<double> v3(2, 1.02356);
//     v3[1] = 0.9856;
//     auto const v2_pow = pow(v2, v3);
//     BOOST_CHECK_EQUAL(v2_pow[0], std::pow(v2[0], v3[0]));
//     BOOST_CHECK_EQUAL(v2_pow[1], std::pow(v2[1], v3[1]));
//
//     // sin
//     auto const v2_sin = sin(v2);
//     BOOST_CHECK_EQUAL(v2_sin[0], std::sin(v2[0]));
//     BOOST_CHECK_EQUAL(v2_sin[1], std::sin(v2[1]));
//
//     // sinh
//     auto const v2_sinh = sinh(v2);
//     BOOST_CHECK_EQUAL(v2_sinh[0], std::sinh(v2[0]));
//     BOOST_CHECK_EQUAL(v2_sinh[1], std::sinh(v2[1]));
//
//     // sqrt
//     auto const v2_sqrt = sqrt(v2);
//     BOOST_CHECK_EQUAL(v2_sqrt[0], std::sqrt(v2[0]));
//     BOOST_CHECK_EQUAL(v2_sqrt[1], std::sqrt(v2[1]));
//
//     // tan
//     auto const v2_tan = tan(v2);
//     BOOST_CHECK_EQUAL(v2_tan[0], std::tan(v2[0]));
//     BOOST_CHECK_EQUAL(v2_tan[1], std::tan(v2[1]));
//
//     // tanh
//     auto const v2_tanh = tanh(v2);
//     BOOST_CHECK_EQUAL(v2_tanh[0], std::tanh(v2[0]));
//     BOOST_CHECK_EQUAL(v2_tanh[1], std::tanh(v2[1]));
// }
//
// BOOST_AUTO_TEST_CASE(varray_packed_math)
//{
//     const auto val = -1.0 * std::exp(1.0);
//     const auto val2 = -2.0 * val;
//     varray<__m256d> v2(2, val);
//     v2[1] = val2;
//
//     // abs
//     auto const v2_abs = abs(v2);
//     BOOST_CHECK_EQUAL(v2_abs[0], -val);
//     BOOST_CHECK_EQUAL(v2_abs[1], val2);
//
//     v2[0] = 0.854;
//     v2[1] = -0.98;
//     // acos
//     auto const v2_acos = acos(v2);
//     BOOST_CHECK_CLOSE(v2_acos[0], std::acos(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_acos[1], std::acos(v2[1]), 1.0e-10);
//
//     // asin
//     auto const v2_asin = asin(v2);
//     BOOST_CHECK_CLOSE(v2_asin[0], std::asin(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_asin[1], std::asin(v2[1]), 1.0e-10);
//
//     // atan
//     auto const v2_atan = atan(v2);
//     BOOST_CHECK_CLOSE(v2_atan[0], std::atan(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_atan[1], std::atan(v2[1]), 1.0e-10);
//
//     // cos
//     auto const v2_cos = cos(v2);
//     BOOST_CHECK_CLOSE(v2_cos[0], std::cos(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_cos[1], std::cos(v2[1]), 1.0e-10);
//
//     // cosh
//     auto const v2_cosh = cosh(v2);
//     BOOST_CHECK_CLOSE(v2_cosh[0], std::cosh(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_cosh[1], std::cosh(v2[1]), 1.0e-10);
//
//     // exp
//     auto const v2_exp = exp(v2);
//     BOOST_CHECK_CLOSE(v2_exp[0], std::exp(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_exp[1], std::exp(v2[1]), 1.0e-10);
//
//     // log
//     v2[1] = 1.0;
//     auto const v2_log = log(v2);
//     BOOST_CHECK_CLOSE(v2_log[0], std::log(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_log[1], std::log(v2[1]), 1.0e-10);
//
//     // log10
//     auto const v2_log10 = log10(v2);
//     BOOST_CHECK_CLOSE(v2_log10[0], std::log10(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_log10[1], std::log10(v2[1]), 1.0e-10);
//
//     // pow
//     varray<__m256d> v3(2, 1.02356);
//     v3[1] = 0.9856;
//     auto const v2_pow = pow(v2, v3);
//     BOOST_CHECK_CLOSE(v2_pow[0], std::pow(v2[0], v3[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_pow[1], std::pow(v2[1], v3[1]), 1.0e-10);
//
//     // sin
//     auto const v2_sin = sin(v2);
//     BOOST_CHECK_CLOSE(v2_sin[0], std::sin(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_sin[1], std::sin(v2[1]), 1.0e-10);
//
//     // sinh
//     auto const v2_sinh = sinh(v2);
//     BOOST_CHECK_CLOSE(v2_sinh[0], std::sinh(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_sinh[1], std::sinh(v2[1]), 1.0e-10);
//
//     // sqrt
//     auto const v2_sqrt = sqrt(v2);
//     BOOST_CHECK_CLOSE(v2_sqrt[0], std::sqrt(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_sqrt[1], std::sqrt(v2[1]), 1.0e-10);
//
//     // tan
//     auto const v2_tan = tan(v2);
//     BOOST_CHECK_CLOSE(v2_tan[0], std::tan(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_tan[1], std::tan(v2[1]), 1.0e-10);
//
//     // tanh
//     auto const v2_tanh = tanh(v2);
//     BOOST_CHECK_CLOSE(v2_tanh[0], std::tanh(v2[0]), 1.0e-10);
//     BOOST_CHECK_CLOSE(v2_tanh[1], std::tanh(v2[1]), 1.0e-10);
// }
//
// BOOST_AUTO_TEST_CASE(varray_slice)
//{
//     const auto val = std::exp(1.0);
//     const auto val2 = 2.0 * val;
//     varray<__m256d> v2(10, val);
//     v2[1] = val2;
//     v2[2] = 2.0 * val2;
//     v2[3] = 3.0 * val2;
//     v2[4] = 4.0 * val2;
//     v2[5] = 5.0 * val2;
//     v2[6] = 6.0 * val2;
//     v2[7] = 7.0 * val2;
//     v2[8] = 8.0 * val2;
//     v2[9] = 9.0 * val2;
//
//     varray<__m256d> slice1 = v2[slice(2, 2, 3)];
//
//     BOOST_CHECK_EQUAL(slice1[0], v2[2]);
//     BOOST_CHECK_EQUAL(slice1[1], v2[5]);
//
//     decltype(v2) slice2 = v2[slice(0, 5, 2)];
//
//     BOOST_CHECK_EQUAL(slice2[0], v2[0]);
//     BOOST_CHECK_EQUAL(slice2[1], v2[2]);
//     BOOST_CHECK_EQUAL(slice2[2], v2[4]);
//     BOOST_CHECK_EQUAL(slice2[3], v2[6]);
//     BOOST_CHECK_EQUAL(slice2[4], v2[8]);
//
//     varray<double> arrs(10);
//
//     arrs[0] = 1.0;
//     arrs[1] = 2.0;
//     arrs[2] = 3.0;
//     arrs[3] = 4.0;
//     arrs[4] = 5.0;
//     arrs[5] = 6.0;
//     arrs[6] = 7.0;
//     arrs[7] = 8.0;
//     arrs[8] = 9.0;
//     arrs[9] = 10.0;
//
//     decltype(arrs) slice3 = arrs[slice(0, 6, 2)];
//
//     BOOST_CHECK_EQUAL(slice3[0], arrs[0]);
//     BOOST_CHECK_EQUAL(slice3[1], arrs[2]);
//     BOOST_CHECK_EQUAL(slice3[2], arrs[4]);
//     BOOST_CHECK_EQUAL(slice3[3], arrs[6]);
//     BOOST_CHECK_EQUAL(slice3[4], arrs[8]);
//     BOOST_CHECK_SMALL(slice3[5], 0.01);
// }
//
// BOOST_AUTO_TEST_CASE(slice_operators)
//{
//     const auto val = std::exp(1.0);
//     const auto val2 = 2.0 * val;
//     varray<__m256d> v2(10, val);
//     v2[1] = val2;
//     v2[2] = 2.0 * val2;
//     v2[3] = 3.0 * val2;
//     v2[4] = 4.0 * val2;
//     v2[5] = 5.0 * val2;
//     v2[6] = 6.0 * val2;
//     v2[7] = 7.0 * val2;
//     v2[8] = 8.0 * val2;
//     v2[9] = 9.0 * val2;
//
//     const slice slc1(2, 2, 3);
//
//     varray<__m256d> slice1 = v2[slc1];
//
//     BOOST_CHECK(slc1 == slice(2, 2, 3));
//
//     slice_varray<__m256d> s1 = v2[slc1];
//     varray<__m256d> v3(10, -1000.5);
//
//     s1 = v3;
//
//     decltype(v3) v4 = s1;
//     BOOST_CHECK_EQUAL(v4[0], v3[0]);
//     BOOST_CHECK_EQUAL(v4[1], v3[1]);
// }
//
// BOOST_AUTO_TEST_CASE(slice_operators_1)
//{
//     const auto val = std::exp(1.0);
//     const auto val2 = 2.0 * val;
//     varray<__m256d> v2(10, val);
//     v2[1] = val2;
//     v2[2] = 2.0 * val2;
//     v2[3] = 3.0 * val2;
//     v2[4] = 4.0 * val2;
//     v2[5] = 5.0 * val2;
//     v2[6] = 6.0 * val2;
//     v2[7] = 7.0 * val2;
//     v2[8] = 8.0 * val2;
//     v2[9] = 9.0 * val2;
//
//     const slice slc1(2, 2, 3);
//
//     varray<__m256d> slice1 = v2[slc1];
//
//     BOOST_CHECK(slc1 == slice(2, 2, 3));
//
//     slice_varray<__m256d> s1 = v2[slc1];
//
//     s1 = -1000.5;
//
//     decltype(v2) v3 = s1;
//     BOOST_CHECK_EQUAL(v3[0], -1000.5);
//     BOOST_CHECK_EQUAL(v3[1], -1000.5);
// }
//
// BOOST_AUTO_TEST_CASE(slice_operators_2)
//{
//     const auto val = std::exp(1.0);
//     varray<__m256d> v2(10, val);
//     v2[1] = 1.0;
//     v2[2] = 2.0;
//     v2[3] = 3.0;
//     v2[4] = 4.0;
//     v2[5] = 5.0;
//     v2[6] = 6.0;
//     v2[7] = 7.0;
//     v2[8] = 8.0;
//     v2[9] = 9.0;
//
//     const slice slc1(2, 3, 3);
//
//     auto slice1 = v2[slc1];
//     varray<__m256d> cpy(slice1);
//     varray<__m256d> tmp(11, 1.0);
//
//     slice1 = tmp;
//     varray<__m256d> cpy1(slice1);
//
//     BOOST_CHECK_EQUAL(cpy1[0], 1.0);
//     BOOST_CHECK_EQUAL(cpy1[1], 1.0);
//     BOOST_CHECK_EQUAL(cpy1[2], 1.0);
//
//     slice1 = 2345.6789;
//     varray<__m256d> cpy2(slice1);
//
//     BOOST_CHECK_EQUAL(cpy2[0], 2345.6789);
//     BOOST_CHECK_EQUAL(cpy2[1], 2345.6789);
//     BOOST_CHECK_EQUAL(cpy2[2], 2345.6789);
// }

BOOST_AUTO_TEST_SUITE_END()
