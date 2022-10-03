#pragma once
#if !defined(_VARRAY_TRAITS_HPP_)
#define _VARRAY_TRAITS_HPP_

#include "vsd4.hpp"
#include "vsf8.hpp"
#include <immintrin.h>
#include <type_traits>

template <typename T> struct packed
{
    using value_type = T;
    static constexpr std::size_t length = 1ULL;
};

template <> struct packed<vsf8>
{
    using value_type = vsf8::value_type;
    static constexpr std::size_t length = vsf8::length;
};

template <> struct packed<vsd4>
{
    using value_type = vsd4::value_type;
    static constexpr std::size_t length = vsd4::length;
};

template <typename T> using packed_t = typename packed<T>::value_type;

template <typename T, typename... Ts> inline constexpr bool is_any_of_v = std::disjunction_v<std::is_same<T, Ts>...>;

template <typename T>
inline constexpr bool is_floating_point_ext_v =
    is_any_of_v<std::remove_cv_t<T>, float, double, long double, vsd4, vsf8>;

template <typename T>
concept floating_point_ext = is_floating_point_ext_v<T>;

#endif //_VARRAY_TRAITS_HPP_
