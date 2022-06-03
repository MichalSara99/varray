#pragma once
#if !defined(_VARRAY_UTILS_HPP_)
#define _VARRAY_UTILS_HPP_

#include "varray_traits.hpp"
#include <immintrin.h>
#include <memory>

template <typename T>
using enable_if_packed = std::enable_if<std::is_same<T, __m256>::value || std::is_same<T, __m256d>::value>;

template <typename T> constexpr size_t length_of_type()
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return 1;
    else if constexpr (std::is_same<T, __m256>::value)
        return sizeof(T) / sizeof(float);
    else if constexpr (std::is_same<T, __m256d>::value)
        return sizeof(T) / sizeof(double);
    else
        static_assert(false, "length_of_type: This cannot happen");
}

template <typename T> const underlying_type_t<T> &getr(const std::shared_ptr<T[]> &ptr, const std::size_t &idx)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return ptr[idx];
    else if constexpr (std::is_same<T, __m256>::value)
    {
        const std::size_t pack_idx = idx / length_of_type<T>();
        const std::size_t inner_idx = idx % length_of_type<T>();
        return ptr[pack_idx].m256_f32[inner_idx];
    }
    else if constexpr (std::is_same<T, __m256d>::value)
    {
        const std::size_t pack_idx = idx / length_of_type<T>();
        const std::size_t inner_idx = idx % length_of_type<T>();
        return ptr[pack_idx].m256d_f64[inner_idx];
    }
    else
        static_assert(false, "index: This cannot happen");
}

template <typename T> underlying_type_t<T> &getw(const std::shared_ptr<T[]> &ptr, const std::size_t &idx)
{
    if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
        return ptr[idx];
    else if constexpr (std::is_same<T, __m256>::value)
    {
        const std::size_t pack_idx = idx / length_of_type<T>();
        const std::size_t inner_idx = idx % length_of_type<T>();
        return ptr[pack_idx].m256_f32[inner_idx];
    }
    else if constexpr (std::is_same<T, __m256d>::value)
    {
        const std::size_t pack_idx = idx / length_of_type<T>();
        const std::size_t inner_idx = idx % length_of_type<T>();
        return ptr[pack_idx].m256d_f64[inner_idx];
    }
    else
        static_assert(false, "index: This cannot happen");
}

template <typename T> auto _mm256_set1(T val)
{
    if constexpr (std::is_same<T, float>::value)
        return _mm256_set1_ps(val);
    else if constexpr (std::is_same<T, double>::value)
        return _mm256_set1_pd(val);
    else
        static_assert(false, "_mm256_set1: This cannot happen");
}

#endif ///_VARRAY_UTILS_HPP_
