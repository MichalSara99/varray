#if !defined(_VARRAY_MATH_HPP_)
#define _VARRAY_MATH_HPP_

#include <cmath>
#include <immintrin.h>
#include <type_traits>

const __int32 pos_mask32 = 0x7fffffff;
const __int64 pos_mask64 = 0x7fffffffffffffff;

template <typename T> _NODISCARD T gabs(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::abs(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_and_ps(val, _mm256_castsi256_ps(_mm256_set_epi32(pos_mask32)));
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_and_pd(val, _mm256_castsi256_pd(_mm256_set1_epi64x(pos_mask64)));
    else
        static_assert(false, "gabs: This cannot happen");
}

template <typename T> _NODISCARD T gacos(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::acos(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_acos_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_acos_pd(val);
    else
        static_assert(false, "gacos: This cannot happen");
}

template <typename T> _NODISCARD T gasin(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::asin(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_asin_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_asin_pd(val);
    else
        static_assert(false, "gasin: This cannot happen");
}

template <typename T> _NODISCARD T gatan(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::atan(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_atan_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_atan_pd(val);
    else
        static_assert(false, "gatan: This cannot happen");
}

template <typename T> _NODISCARD T gatan2(T valY, T valX)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::atan2(valY, valX);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_atan2_ps(valY, valX);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_atan2_pd(valY, valX);
    else
        static_assert(false, "gatan2: This cannot happen");
}

template <typename T> _NODISCARD T gcos(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::cos(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_cos_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_cos_pd(val);
    else
        static_assert(false, "gcos: This cannot happen");
}

template <typename T> _NODISCARD T gcosh(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::cosh(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_cosh_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_cosh_pd(val);
    else
        static_assert(false, "gcosh: This cannot happen");
}

template <typename T> _NODISCARD T gexp(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::exp(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_exp_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_exp_pd(val);
    else
        static_assert(false, "gexp: This cannot happen");
}

template <typename T> _NODISCARD T glog(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::log(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_log_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_log_pd(val);
    else
        static_assert(false, "glog: This cannot happen");
}

template <typename T> _NODISCARD T glog10(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::log10(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_log10_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_log10_pd(val);
    else
        static_assert(false, "glog10: This cannot happen");
}

template <typename T> _NODISCARD T gpow(T valY, T valX)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::pow(valY, valX);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_pow_ps(valY, valX);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_pow_pd(valY, valX);
    else
        static_assert(false, "gpow: This cannot happen");
}

template <typename T> _NODISCARD T gsin(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::sin(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_sin_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_sin_pd(val);
    else
        static_assert(false, "gsin: This cannot happen");
}

template <typename T> _NODISCARD T gsinh(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::sinh(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_sinh_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_sinh_pd(val);
    else
        static_assert(false, "gsinh: This cannot happen");
}

template <typename T> _NODISCARD T gsqrt(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::sqrt(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_sqrt_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_sqrt_pd(val);
    else
        static_assert(false, "gsqrt: This cannot happen");
}

template <typename T> _NODISCARD T gtan(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::tan(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_tan_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_tan_pd(val);
    else
        static_assert(false, "gtan: This cannot happen");
}

template <typename T> _NODISCARD T gtanh(T val)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return std::tanh(val);
    else if constexpr (std::is_same<T, __m256>::value)
        return _mm256_tanh_ps(val);
    else if constexpr (std::is_same<T, __m256d>::value)
        return _mm256_tanh_pd(val);
    else
        static_assert(false, "gtanh: This cannot happen");
}

#endif ///_VARRAY_MATH_HPP_
