#if !defined(_VDOUBLE4_HPP_)
#define _VDOUBLE4_HPP_

#include <immintrin.h>
#include <iostream>
#include <typeinfo>

#define HEX_ABS_MASK 0x8000000000000000

/**
    @struct vdouble4
    @brief  Packed double-precision type
**/
struct vdouble4 : public __m256d
{
  public:
    using value_type = double;
    constexpr static std::size_t length = sizeof(__m256d) / sizeof(value_type);

    vdouble4(){};
    vdouble4(const __m256d x) : __m256d(x)
    {
    }
    vdouble4(double x) : __m256d(_mm256_set1_pd(x))
    {
    }
    vdouble4(double x0, double x1, double x2, double x3) : __m256d(_mm256_setr_pd(x0, x1, x2, x3))
    {
    }

    const value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(this)[idx];
    }

    value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(this)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vdouble4 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << ")";
    }

    vdouble4 &operator+=(const vdouble4 x)
    {
        *this = _mm256_add_pd(*this, x);
        return *this;
    }

    vdouble4 &operator-=(const vdouble4 x)
    {
        *this = _mm256_sub_pd(*this, x);
        return *this;
    }

    vdouble4 &operator*=(const vdouble4 x)
    {
        *this = _mm256_mul_pd(*this, x);
        return *this;
    }

    vdouble4 &operator/=(const vdouble4 x)
    {
        *this = _mm256_div_pd(*this, x);
        return *this;
    }
};

// ========================== UNARY operators ===========================

const vdouble4 operator-(const vdouble4 x)
{
    return _mm256_xor_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
}

const vdouble4 operator+(const vdouble4 x)
{
    return x;
}

// ========================== BINARY operators ==========================

const vdouble4 operator*(const vdouble4 x, const vdouble4 y)
{
    return _mm256_mul_pd(x, y);
}

const vdouble4 operator/(const vdouble4 x, const vdouble4 y)
{
    return _mm256_div_pd(x, y);
}

const vdouble4 operator+(const vdouble4 x, const vdouble4 y)
{
    return _mm256_add_pd(x, y);
}

const vdouble4 operator-(const vdouble4 x, const vdouble4 y)
{
    return _mm256_sub_pd(x, y);
}

#endif //_VDOUBLE4_HPP_
