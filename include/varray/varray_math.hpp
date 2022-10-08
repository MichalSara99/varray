#if !defined(_VARRAY_MATH_HPP_)
#define _VARRAY_MATH_HPP_

#include "../macros/macros.hpp"
#include "../vectorised_types/vmath.hpp"
#include "varray.hpp"
#include <type_traits>

template <typename T> _NODISCARD static inline varray<T> abs(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = abs(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> sqrt(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = sqrt(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> invsqrt(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = invsqrt(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> cbrt(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = cbrt(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> invcbrt(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = invcbrt(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> ceil(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = ceil(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> floor(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = floor(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> trunc(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = trunc(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> pow(const varray<T> &valx, const varray<T> &valy)
{
    const size_t sz = valx.vsize();
    VERIFY(sz == valy.vsize(), "vsize of valx and valy differs");
    varray<T> ans(valx.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = pow(valx[idx], valy[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> exp(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = exp(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> exp10(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = exp10(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> exp2(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = exp2(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> expm1(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = expm1(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> log(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = log(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> log2(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = log2(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> log10(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = log10(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> sin(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = sin(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> cos(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = cos(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> tan(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = tan(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> asin(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = asin(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> acos(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = acos(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> atan(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = atan(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> atan2(const varray<T> &valx, const varray<T> &valy)
{
    const size_t sz = valx.vsize();
    VERIFY(sz == valy.vsize(), "vsize of valx and valy differs");
    varray<T> ans(valx.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = atan2(valx[idx], valy[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> sinh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = sinh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> cosh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = cosh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> tanh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = tanh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> asinh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = asinh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> acosh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = acosh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> atanh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = atanh(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> erf(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = erf(val[idx]);
    }
    return ans;
}

template <typename T> _NODISCARD static inline varray<T> erfc(const varray<T> &val)
{
    const size_t sz = val.vsize();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx++)
    {
        ans[idx] = erfc(val[idx]);
    }
    return ans;
}

#endif ///_VARRAY_MATH_HPP_
