#if !defined(_VMATH_HPP_)
#define _VMATH_HPP_

#include "vdouble4.hpp"
#include "vfloat8.hpp"

/**
    @brief  absolute value function
    @param  x - vfloat8 arg
    @retval   - return absolute value
**/
static inline vfloat8 abs(const vfloat8 &x)
{
    return _mm256_and_ps(x, _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff)));
}
/**
    @brief  absolute value function
    @param  x - vdouble4 arg
    @retval   - return absolute value
**/
static inline vdouble4 abs(const vdouble4 &x)
{
    return _mm256_and_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0x7fffffffffffffff)));
}
/**
    @brief  square root function
    @param  x - vfloat8 arg
    @retval   - return square root
**/
static inline vfloat8 sqrt(const vfloat8 &x)
{
    return _mm256_sqrt_ps(x);
}
/**
    @brief  square root function
    @param  x - vdouble4 arg
    @retval   - return square root
**/
static inline vdouble4 sqrt(const vdouble4 &x)
{
    return _mm256_sqrt_pd(x);
}
/**
    @brief  inverse square root function
    @param  x - vfloat8 arg
    @retval   - return inverse square root
**/
static inline vfloat8 invsqrt(const vfloat8 &x)
{
    return _mm256_invsqrt_ps(x);
}
/**
    @brief  inverse square root function
    @param  x - vdouble4 arg
    @retval   - return inverse square root
**/
static inline vdouble4 invsqrt(const vdouble4 &x)
{
    return _mm256_invsqrt_pd(x);
}
/**
    @brief  cubic root function
    @param  x - vfloat8 arg
    @retval   - return cubic root
**/
static inline vfloat8 cbrt(const vfloat8 &x)
{
    return _mm256_cbrt_ps(x);
}
/**
    @brief  cubic root function
    @param  x - vdouble4 arg
    @retval   - return cubic root
**/
static inline vdouble4 cbrt(const vdouble4 &x)
{
    return _mm256_cbrt_pd(x);
}
/**
    @brief  inverse cubic root function
    @param  x - vfloat8 arg
    @retval   - return inverse cubic root
**/
static inline vfloat8 invcbrt(const vfloat8 &x)
{
    return _mm256_invcbrt_ps(x);
}
/**
    @brief  inverse cubic root function
    @param  x - vdouble4 arg
    @retval   - return inverse cubic root
**/
static inline vdouble4 invcbrt(const vdouble4 &x)
{
    return _mm256_invcbrt_pd(x);
}
/**
    @brief ceil function
    @param  x - vfloat8 arg
    @retval   - return ceil
**/
static inline vfloat8 ceil(const vfloat8 &x)
{
    return _mm256_ceil_ps(x);
}
/**
    @brief ceil function
    @param  x - vdouble4 arg
    @retval   - return ceil
**/
static inline vdouble4 ceil(const vdouble4 &x)
{
    return _mm256_ceil_pd(x);
}
/**
    @brief floor function
    @param  x - vfloat8 arg
    @retval   - return ceil
**/
static inline vfloat8 floor(const vfloat8 &x)
{
    return _mm256_floor_ps(x);
}
/**
    @brief floor function
    @param  x - vdouble4 arg
    @retval   - return ceil
**/
static inline vdouble4 floor(const vdouble4 &x)
{
    return _mm256_floor_pd(x);
}
/**
    @brief trunc function
    @param  x - vfloat8 arg
    @retval   - return trunc
**/
static inline vfloat8 trunc(const vfloat8 &x)
{
    return _mm256_trunc_ps(x);
}
/**
    @brief trunc function
    @param  x - vdouble4 arg
    @retval   - return trunc
**/
static inline vdouble4 trunc(const vdouble4 &x)
{
    return _mm256_trunc_pd(x);
}
/**
    @brief  pow function
    @param  x - exponent vfloat8 arg
    @param  y - power vfloat8 arg
    @retval   - return pow
**/
static inline vfloat8 pow(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_pow_ps(x, y);
}
/**
    @brief  pow function
    @param  x - exponent vdouble4 arg
    @param  y - power vdouble4 arg
    @retval   - return pow
**/
static inline vdouble4 pow(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_pow_pd(x, y);
}
/**
    @brief  exponential function
    @param  x - vfloat8 arg
    @retval   - return exponential value
**/
static inline vfloat8 exp(const vfloat8 &x)
{
    return _mm256_exp_ps(x);
}
/**
    @brief  exponential function
    @param  x - vdouble4 arg
    @retval   - return exponential value
**/
static inline vdouble4 exp(const vdouble4 &x)
{
    return _mm256_exp_pd(x);
}
/**
    @brief  exponential function
    @param  x - vfloat8 arg
    @retval   - return exponential value
**/
static inline vfloat8 exp10(const vfloat8 &x)
{
    return _mm256_exp10_ps(x);
}
/**
    @brief  exponential function
    @param  x - vdouble4 arg
    @retval   - return exponential value
**/
static inline vdouble4 exp10(const vdouble4 &x)
{
    return _mm256_exp10_pd(x);
}
/**
    @brief  exponential function
    @param  x - vfloat8 arg
    @retval   - return exponential value
**/
static inline vfloat8 exp2(const vfloat8 &x)
{
    return _mm256_exp2_ps(x);
}
/**
    @brief  exponential function
    @param  x - vdouble4 arg
    @retval   - return exponential value
**/
static inline vdouble4 exp2(const vdouble4 &x)
{
    return _mm256_exp2_pd(x);
}
/**
    @brief  exponential function minus one
    @param  x - vfloat8 arg
    @retval   - return exponential value minus one
**/
static inline vfloat8 expm1(const vfloat8 &x)
{
    return _mm256_expm1_ps(x);
}
/**
    @brief  exponential function minus one
    @param  x - vdouble4 arg
    @retval   - return exponential value minus one
**/
static inline vdouble4 expm1(const vdouble4 &x)
{
    return _mm256_expm1_pd(x);
}
/**
    @brief  natural log function
    @param  x - vfloat8 arg
    @retval   - return natural log value
**/
static inline vfloat8 log(const vfloat8 &x)
{
    return _mm256_log_ps(x);
}
/**
    @brief  natural log function
    @param  x - vdouble4 arg
    @retval   - return natural log value
**/
static inline vdouble4 log(const vdouble4 &x)
{
    return _mm256_log_pd(x);
}
/**
    @brief  log2 function
    @param  x - vfloat8 arg
    @retval   - return log2 value
**/
static inline vfloat8 log2(const vfloat8 &x)
{
    return _mm256_log2_ps(x);
}
/**
    @brief  log2 function
    @param  x - vdouble4 arg
    @retval   - return log2 value
**/
static inline vdouble4 log2(const vdouble4 &x)
{
    return _mm256_log2_pd(x);
}
/**
    @brief  log10 function
    @param  x - vfloat8 arg
    @retval   - return log10 value
**/
static inline vfloat8 log10(const vfloat8 &x)
{
    return _mm256_log10_ps(x);
}
/**
    @brief  log10 function
    @param  x - vdouble4 arg
    @retval   - return log10 value
**/
static inline vdouble4 log10(const vdouble4 &x)
{
    return _mm256_log10_pd(x);
}
/**
    @brief  sine function
    @param  x - vfloat8 arg
    @retval   - return sine value
**/
static inline vfloat8 sin(const vfloat8 &x)
{
    return _mm256_sin_ps(x);
}
/**
    @brief  sine function
    @param  x - vdouble4 arg
    @retval   - return sine value
**/
static inline vdouble4 sin(const vdouble4 &x)
{
    return _mm256_sin_pd(x);
}
/**
    @brief  cosine function
    @param  x - vfloat8 arg
    @retval   - return cosine value
**/
static inline vfloat8 cos(const vfloat8 &x)
{
    return _mm256_cos_ps(x);
}
/**
    @brief  cosine function
    @param  x - vdouble4 arg
    @retval   - return cosine value
**/
static inline vdouble4 cos(const vdouble4 &x)
{
    return _mm256_cos_pd(x);
}
/**
    @brief  tangens function
    @param  x - vfloat8 arg
    @retval   - return tangens value
**/
static inline vfloat8 tan(const vfloat8 &x)
{
    return _mm256_tan_ps(x);
}
/**
    @brief  tangens function
    @param  x - vdouble4 arg
    @retval   - return tangens value
**/
static inline vdouble4 tan(const vdouble4 &x)
{
    return _mm256_tan_pd(x);
}
/**
    @brief  arc sine function
    @param  x - vfloat8 arg
    @retval   - return arc sine value
**/
static inline vfloat8 asin(const vfloat8 &x)
{
    return _mm256_asin_ps(x);
}
/**
    @brief  arc sine function
    @param  x - vdouble4 arg
    @retval   - return arc sine value
**/
static inline vdouble4 asin(const vdouble4 &x)
{
    return _mm256_asin_pd(x);
}
/**
    @brief  arc cosine function
    @param  x - vfloat8 arg
    @retval   - return arc cosine value
**/
static inline vfloat8 acos(const vfloat8 &x)
{
    return _mm256_acos_ps(x);
}
/**
    @brief  arc cosine function
    @param  x - vdouble4 arg
    @retval   - return arc cosine value
**/
static inline vdouble4 acos(const vdouble4 &x)
{
    return _mm256_acos_pd(x);
}
/**
    @brief  arc tangens function
    @param  x - vfloat8 arg
    @retval   - return arc tangens value
**/
static inline vfloat8 atan(const vfloat8 &x)
{
    return _mm256_atan_ps(x);
}
/**
    @brief  arc tangens function
    @param  x - vdouble4 arg
    @retval   - return arc tangens value
**/
static inline vdouble4 atan(const vdouble4 &x)
{
    return _mm256_atan_pd(x);
}

/**
    @brief  arc tangens function of x/y
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return arc tangens value
**/
static inline vfloat8 atan2(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_atan2_ps(x, y);
}
/**
    @brief  arc tangens function of x/y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return arc tangens value
**/
static inline vdouble4 atan2(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_atan2_pd(x, y);
}
/**
    @brief  hyperbolic sine function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic sine value
**/
static inline vfloat8 sinh(const vfloat8 &x)
{
    return _mm256_sinh_ps(x);
}
/**
    @brief  hyperbolic sine function
    @param  x - vdouble4 arg
    @retval   - return hyperbolic sine value
**/
static inline vdouble4 sinh(const vdouble4 &x)
{
    return _mm256_sinh_pd(x);
}
/**
    @brief  hyperbolic cosine function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic cosine value
**/
static inline vfloat8 cosh(const vfloat8 &x)
{
    return _mm256_cosh_ps(x);
}
/**
    @brief  hyperbolic cosine function
    @param  x - vdouble4 arg
    @retval   - return hyperbolic cosine value
**/
static inline vdouble4 cosh(const vdouble4 &x)
{
    return _mm256_cosh_pd(x);
}
/**
    @brief  hyperbolic tangens function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic tangens value
**/
static inline vfloat8 tanh(const vfloat8 &x)
{
    return _mm256_tanh_ps(x);
}
/**
    @brief  hyperbolic tangens function
    @param  x - vdouble4 arg
    @retval   - return hyperbolic tangens value
**/
static inline vdouble4 tanh(const vdouble4 &x)
{
    return _mm256_tanh_pd(x);
}
/**
    @brief  inverse hyperbolic sine function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic sine value
**/
static inline vfloat8 asinh(const vfloat8 &x)
{
    return _mm256_asinh_ps(x);
}
/**
    @brief  inverse hyperbolic sine function
    @param  x - vdouble4 arg
    @retval   - return inverse hyperbolic sine value
**/
static inline vdouble4 asinh(const vdouble4 &x)
{
    return _mm256_asinh_pd(x);
}
/**
    @brief  inverse hyperbolic cosine function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic cosine value
**/
static inline vfloat8 acosh(const vfloat8 &x)
{
    return _mm256_acosh_ps(x);
}
/**
    @brief  inverse hyperbolic cosine function
    @param  x - vdouble4 arg
    @retval   - return inverse hyperbolic cosine value
**/
static inline vdouble4 acosh(const vdouble4 &x)
{
    return _mm256_acosh_pd(x);
}
/**
    @brief  inverse hyperbolic tangens function
    @param  x - vfloat8 arg
    @retval   - return hyperbolic tangens value
**/
static inline vfloat8 atanh(const vfloat8 &x)
{
    return _mm256_atanh_ps(x);
}
/**
    @brief  inverse hyperbolic tangens function
    @param  x - vdouble4 arg
    @retval   - return inverse hyperbolic tangens value
**/
static inline vdouble4 atanh(const vdouble4 &x)
{
    return _mm256_atanh_pd(x);
}
/**
    @brief  normal cumulative distribution function
    @param  x - vfloat8 arg
    @retval   - return normal cumulative distribution value
**/
static inline vfloat8 cdfnorm(const vfloat8 &x)
{
    return _mm256_cdfnorm_ps(x);
}
/**
    @brief  normal cumulative distribution function
    @param  x - vdouble4 arg
    @retval   - return normal cumulative distribution value
**/
static inline vdouble4 cdfnorm(const vdouble4 &x)
{
    return _mm256_cdfnorm_pd(x);
}
/**
    @brief  normal inverse cumulative distribution function
    @param  x - vfloat8 arg
    @retval   - return normal inverse cumulative distribution value
**/
static inline vfloat8 cdfnorminv(const vfloat8 &x)
{
    return _mm256_cdfnorminv_ps(x);
}
/**
    @brief  normal inverse cumulative distribution function
    @param  x - vdouble4 arg
    @retval   - return normal inverse cumulative distribution value
**/
static inline vdouble4 cdfnorminv(const vdouble4 &x)
{
    return _mm256_cdfnorminv_pd(x);
}
/**
    @brief  error function
    @param  x - vfloat8 arg
    @retval   - return error value
**/
static inline vfloat8 erf(const vfloat8 &x)
{
    return _mm256_erf_ps(x);
}
/**
    @brief  error function
    @param  x - vdouble4 arg
    @retval   - return error value
**/
static inline vdouble4 erf(const vdouble4 &x)
{
    return _mm256_erf_pd(x);
}
/**
    @brief  complementary error function
    @param  x - vfloat8 arg
    @retval   - return complementary error value
**/
static inline vfloat8 erfc(const vfloat8 &x)
{
    return _mm256_erfc_ps(x);
}
/**
    @brief  complementary error function
    @param  x - vdouble4 arg
    @retval   - return complementary error value
**/
static inline vdouble4 erfc(const vdouble4 &x)
{
    return _mm256_erfc_pd(x);
}

#endif ///_VMATH_HPP_
