#pragma once
#if !defined(_VARRAY_TRAITS_HPP_)
#define _VARRAY_TRAITS_HPP_

#include <immintrin.h>

template <typename T> struct underlying_type
{
    using type = void;
};

template <> struct underlying_type<float>
{
    using type = float;
};

template <> struct underlying_type<double>
{
    using type = double;
};

template <> struct underlying_type<__m256>
{
    using type = float;
};

template <> struct underlying_type<__m256d>
{
    using type = double;
};

template <typename T> using underlying_type_t = typename underlying_type<T>::type;

#endif //_VARRAY_TRAITS_HPP_
