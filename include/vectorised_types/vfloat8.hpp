#pragma once
#if !defined(_VFLOAT8_HPP_)
#define _VFLOAT8_HPP_

#include <immintrin.h>
#include <iostream>
#include <typeinfo>

/**
    @struct vfloat8
    @brief  Packed single-precision type
**/
struct vfloat8
{
  private:
    __m256 pack;

  public:
    using value_type = float;
    constexpr static std::size_t length = sizeof(__m256) / sizeof(value_type);

    vfloat8(){};
    explicit vfloat8(const __m256 x) : pack(x)
    {
    }
    vfloat8(float x) : pack(_mm256_set1_ps(x))
    {
    }
    vfloat8(float x0, float x1, float x2, float x3, float x4, float x5, float x6, float x7)
        : pack(_mm256_setr_ps(x0, x1, x2, x3, x4, x5, x6, x7))
    {
    }

    const value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(&pack)[idx];
    }

    value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(&pack)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vfloat8 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << "," << x[4] << "," << x[5] << ","
                   << x[6] << "," << x[7] << ")";
    }
};

#endif //_VFLOAT8_HPP_
