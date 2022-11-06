#pragma once
#if !defined(_VFLOAT8_HPP_)
#define _VFLOAT8_HPP_

#include <format>
#include <immintrin.h>
#include <iostream>
#include <typeinfo>

namespace
{

struct vfloat8Base
{
    inline operator __m256() const noexcept
    {
        return pack;
    }

    __m256 pack;
};

struct vint8Base
{
    inline operator __m256i() const noexcept
    {
        return pack;
    }

    __m256i pack;
};

} // namespace

/**
    @struct vfloat8
    @brief  Packed single-precision type
**/
struct vfloat8 : public vfloat8Base
{

    using value_type = float;
    constexpr static std::size_t length = sizeof(__m256) / sizeof(value_type);

    constexpr vfloat8(){};

    vfloat8(const __m256 x) : vfloat8Base{x}
    {
    }

    vfloat8(value_type x) : vfloat8Base{_mm256_set1_ps(x)}
    {
    }

    vfloat8(value_type x0, value_type x1, value_type x2, value_type x3, value_type x4, value_type x5, value_type x6,
            value_type x7)
        : vfloat8Base{_mm256_setr_ps(x0, x1, x2, x3, x4, x5, x6, x7)}
    {
    }

    const inline value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(this)[idx];
    }

    inline value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(this)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vfloat8 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << "," << x[4] << "," << x[5] << ","
                   << x[6] << "," << x[7] << ")";
    }

    inline vfloat8 &operator+=(const vfloat8 &x)
    {
        *this = _mm256_add_ps(*this, x);
        return *this;
    }

    inline vfloat8 &operator-=(const vfloat8 &x)
    {
        *this = _mm256_sub_ps(*this, x);
        return *this;
    }

    inline vfloat8 &operator*=(const vfloat8 &x)
    {
        *this = _mm256_mul_ps(*this, x);
        return *this;
    }

    inline vfloat8 &operator/=(const vfloat8 &x)
    {
        *this = _mm256_div_ps(*this, x);
        return *this;
    }
};

/**
    @struct vint8
    @brief Packed 8 32-bit int type
**/
struct vint8 : public vint8Base
{
    using value_type = int32_t;
    constexpr static std::size_t length = sizeof(__m256i) / sizeof(value_type);

    constexpr vint8(){};

    vint8(const __m256i x) : vint8Base{x}
    {
    }

    vint8(value_type x) : vint8Base{_mm256_set1_epi32(x)}
    {
    }

    vint8(value_type x0, value_type x1, value_type x2, value_type x3, value_type x4, value_type x5, value_type x6,
          value_type x7)
        : vint8Base{_mm256_setr_epi32(x0, x1, x2, x3, x4, x5, x6, x7)}
    {
    }

    const inline value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(this)[idx];
    }

    inline value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(this)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vint8 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << "," << x[4] << "," << x[5] << ","
                   << x[6] << "," << x[7] << ")";
    }

    inline vint8 &operator+=(const vint8 &x)
    {
        *this = _mm256_add_epi32(*this, x);
        return *this;
    }

    inline vint8 &operator-=(const vint8 &x)
    {
        *this = _mm256_sub_epi32(*this, x);
        return *this;
    }
};

/**
    @struct vbool8
    @brief Packed 8 bool type
**/
struct vbool8 : public vint8
{
    using value_type = bool;

    vbool8() = default;
    vbool8(value_type x) : vint8(-vint8::value_type(x))
    {
    }

    vbool8(value_type x0, value_type x1, value_type x2, value_type x3, value_type x4, value_type x5, value_type x6,
           value_type x7)
        : vint8(-vint8::value_type(x0), -vint8::value_type(x1), -vint8::value_type(x2), -vint8::value_type(x3),
                -vint8::value_type(x4), -vint8::value_type(x5), -vint8::value_type(x6), -vint8::value_type(x7))
    {
    }

    vbool8(vint8 x) : vbool8(x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7])
    {
    }
};

// ======================================================================
// ========================== UNARY operators ===========================
// ======================================================================

// ================== fundamental operations ===================

/**
    @brief  operator-
    @param  x - vfloat8 arg
    @retval   - return minus of x
**/
static inline vfloat8 operator-(const vfloat8 &x)
{
    return _mm256_xor_ps(x, _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000)));
}

/**
    @brief  operator-
    @param  x - vint8 arg
    @retval   - return minus of x
**/
static inline vint8 operator-(const vint8 &x)
{
    return _mm256_sub_epi32(_mm256_set1_epi32(0), x);
}

/**
    @brief  operator+
    @param  x - vfloat8 arg
    @retval   - return plus of x
**/
static inline vfloat8 operator+(const vfloat8 &x)
{
    return x;
}

/**
    @brief  operator+
    @param  x - vint8 arg
    @retval   - return plus of x
**/
static inline vint8 operator+(const vint8 &x)
{
    return x;
}

// ================== bitwise operations ===================
/**
    @brief  bitwise not
    @param  x - vfloat8 arg
    @retval   - return bitwise not of x
**/
static inline vfloat8 operator~(const vfloat8 &x)
{
    return _mm256_xor_ps(x, _mm256_castsi256_ps(_mm256_set1_epi32(0xffffffff)));
}

/**
    @brief  bitwise not
    @param  x - vint8 arg
    @retval   - return bitwise not of x
**/
static inline vint8 operator~(const vint8 &x)
{
    return _mm256_xor_si256(x, _mm256_set1_epi32(0xffffffff));
}

/**
    @brief  bitwise not
    @param  x - vbool8 arg
    @retval   - return bitwise not of x
**/
static inline vbool8 operator~(const vbool8 &x)
{
    return vint8(_mm256_xor_si256(x, _mm256_set1_epi32(0xffffffff)));
}

// ================== logical operations ===================
/**
    @brief  logical not
    @param  x - vbool8 arg
    @retval   - return logical not of x
**/
static inline vbool8 operator!(const vbool8 &x)
{
    return ~x;
}

// ======================================================================
// ========================== BINARY operators ==========================
// ======================================================================

// ================== fundamental operations ===================
/**
    @brief  operator*
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return multiplication of x and y
**/
static inline vfloat8 operator*(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_mul_ps(x, y);
}

/**
    @brief  operator/
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return division of x and y
**/
static inline vfloat8 operator/(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_div_ps(x, y);
}

/**
    @brief  operator+
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return sum of x and y
**/
static inline vfloat8 operator+(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_add_ps(x, y);
}

/**
    @brief  operator+
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return sum of x and y
**/
static inline vint8 operator+(const vint8 &x, const vint8 &y)
{
    return _mm256_add_epi32(x, y);
}

/**
    @brief  operator-
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return subtraction of x and y
**/
static inline vfloat8 operator-(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_sub_ps(x, y);
}

/**
    @brief  operator-
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return subtraction of x and y
**/
static inline vint8 operator-(const vint8 &x, const vint8 &y)
{
    return _mm256_sub_epi32(x, y);
}

/**
    @brief  minimum of x and y
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return minimum of x and y
**/
static inline vfloat8 min(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_min_ps(x, y);
}

/**
    @brief  minimum of x and y
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return minimum of x and y
**/
static inline vint8 min(const vint8 &x, const vint8 &y)
{
    return _mm256_min_epi32(x, y);
}

/**
    @brief  maximum of x and y
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return maximum of x and y
**/
static inline vfloat8 max(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_max_ps(x, y);
}

/**
    @brief  maximum of x and y
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return maximum of x and y
**/
static inline vint8 max(const vint8 &x, const vint8 &y)
{
    return _mm256_max_epi32(x, y);
}

/**
    @brief  operator%
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return x mod y
**/
static inline vfloat8 operator%(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_fmod_ps(x, y);
}

// ================== bitwise operations ===================

/**
    @brief  bitwise AND
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise AND of x and y
**/
static inline vfloat8 operator&(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_and_ps(x, y);
}

/**
    @brief  bitwise AND
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return bitwise AND of x and y
**/
static inline vint8 operator&(const vint8 &x, const vint8 &y)
{
    return _mm256_and_si256(x, y);
}

/**
    @brief  bitwise AND
    @param  x - vbool8 arg
    @param  y - vbool8 arg
    @retval   - return bitwise AND of x and y
**/
static inline vbool8 operator&(const vbool8 &x, const vbool8 &y)
{
    return vint8(_mm256_and_si256(x, y));
}

/**
    @brief  logical AND
    @param  x - vbool8 arg
    @param  y - vbool8 arg
    @retval   - return logical AND of x and y
**/
static inline vbool8 operator&&(const vbool8 &x, const vbool8 &y)
{
    return x & y;
}

/**
    @brief  bitwise OR
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise OR of x and y
**/
static inline vfloat8 operator|(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_or_ps(x, y);
}

/**
    @brief  bitwise OR
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return bitwise OR of x and y
**/
static inline vint8 operator|(const vint8 &x, const vint8 &y)
{
    return _mm256_or_si256(x, y);
}

/**
    @brief  bitwise OR
    @param  x - vbool8 arg
    @param  y - vbool8 arg
    @retval   - return bitwise OR of x and y
**/
static inline vbool8 operator|(const vbool8 &x, const vbool8 &y)
{
    return vint8(_mm256_or_si256(x, y));
}

/**
    @brief  logical OR
    @param  x - vbool8 arg
    @param  y - vbool8 arg
    @retval   - return logical OR of x and y
**/
static inline vbool8 operator||(const vbool8 &x, const vbool8 &y)
{
    return x | y;
}

/**
    @brief  bitwise XOR
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vfloat8 operator^(const vfloat8 &x, const vfloat8 &y)
{
    return _mm256_xor_ps(x, y);
}

/**
    @brief  bitwise XOR
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vint8 operator^(const vint8 &x, const vint8 &y)
{
    return _mm256_xor_si256(x, y);
}

/**
    @brief  bitwise XOR
    @param  x - vint8 arg
    @param  y - vint8 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vbool8 operator^(const vbool8 &x, const vbool8 &y)
{
    return vint8(_mm256_xor_si256(x, y));
}

/**
    @brief  left shift <<
    @param  x - vint8 arg
    @param  n - vint8 arg
    @retval   - return x << n
**/
static inline vint8 operator<<(const vint8 &x, const vint8 &n)
{
    return _mm256_sllv_epi32(x, n);
}

/**
    @brief  right shift >>
    @param  x - vint8 arg
    @param  n - vint8 arg
    @retval   - return x >> n
**/
static inline vint8 operator>>(const vint8 &x, const vint8 &n)
{
    return _mm256_srlv_epi32(x, n);
}

// ================== comparison operations ===================

/**
    @brief  operator<
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is less than right
**/
static inline vbool8 operator<(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_LT_OS)));
}
/**
    @brief  operator>=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is greater or equal than right
**/
static inline vbool8 operator>=(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_GE_OS)));
}
/**
    @brief  operator>
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is greater than right
**/
static inline vbool8 operator>(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_GT_OS)));
}
/**
    @brief  operator<=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is less or equal than right
**/
static inline vbool8 operator<=(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_LE_OS)));
}
/**
    @brief  operator==
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if objects are equal
**/
static inline vbool8 operator==(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_EQ_OS)));
}
/**
    @brief  operator!=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if objects are not equal
**/
static inline vbool8 operator!=(const vfloat8 &x, const vfloat8 &y)
{
    return vint8(_mm256_castps_si256(_mm256_cmp_ps(x, y, _CMP_NEQ_OS)));
}

// ======================================================================
// ========================== TENARY operators ==========================
// ======================================================================

/**
    @brief  if merge operartor
    @param  thenExpr    - vfloat8
    @param  elseExpr    - vfloat8
    @param  ifExpr      - vbool8
    @retval             - return merged packed result
**/
static inline vfloat8 blend(const vfloat8 &thenExpr, const vfloat8 &elseExpr, const vbool8 &ifExpr)
{
    return _mm256_blendv_ps(elseExpr, thenExpr, _mm256_castsi256_ps(ifExpr));
}

// ======================================================================
// =========================== OTHER functions ==========================
// ======================================================================

namespace
{
static inline size_t countMaskZeros(const vbool8 &x)
{
    return (vbool8::length - _mm_popcnt_u64(_mm256_movemask_ps(_mm256_castsi256_ps(x))));
}
} // namespace

/**
    @brief  Are all elements of the packed bool TRUE
    @param  x - vbool8 arg
    @retval   -
**/
static inline bool all(const vbool8 &x)
{
    return (countMaskZeros(x) == 0);
}

/**
    @brief  Are any elements of the packed bool TRUE
    @param  x -  vbool8 arg
    @retval   -
**/
static inline bool any(const vbool8 &x)
{
    return (countMaskZeros(x) != vbool8::length);
}

/**
    @brief  Are all elements of the packed bool FALSE
    @param  x -  vbool8 arg
    @retval   -
**/
static inline bool none(const vbool8 &x)
{
    return (countMaskZeros(x) == vbool8::length);
}

#endif //_VFLOAT8_HPP_
