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

    constexpr vfloat8(){};
    constexpr vfloat8(const __m256 x) : pack(x)
    {
    }
    vfloat8(float x) : pack(_mm256_set1_ps(x))
    {
    }
    vfloat8(float x0, float x1, float x2, float x3, float x4, float x5, float x6, float x7)
        : pack(_mm256_setr_ps(x0, x1, x2, x3, x4, x5, x6, x7))
    {
    }

    inline operator __m256() const
    {
        return pack;
    }

    const inline value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(&pack)[idx];
    }

    inline value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(&pack)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vfloat8 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << "," << x[4] << "," << x[5] << ","
                   << x[6] << "," << x[7] << ")";
    }

    inline vfloat8 &operator+=(const vfloat8 x)
    {
        pack = _mm256_add_ps(pack, x);
        return *this;
    }

    inline vfloat8 &operator-=(const vfloat8 x)
    {
        pack = _mm256_sub_ps(pack, x);
        return *this;
    }

    inline vfloat8 &operator*=(const vfloat8 x)
    {
        pack = _mm256_mul_ps(pack, x);
        return *this;
    }

    inline vfloat8 &operator/=(const vfloat8 x)
    {
        pack = _mm256_div_ps(pack, x);
        return *this;
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
static inline const vfloat8 operator-(const vfloat8 x)
{
    return _mm256_xor_ps(x, _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000)));
}
/**
    @brief  operator+
    @param  x - vfloat8 arg
    @retval   - return plus of x
**/
static inline const vfloat8 operator+(const vfloat8 x)
{
    return x;
}

// ================== bitwise operations ===================
/**
    @brief  bitwise not
    @param  x - vfloat8 arg
    @retval   - return bitwise not of x
**/
static inline const vfloat8 operator~(const vfloat8 x)
{
    return _mm256_xor_ps(x, _mm256_castsi256_ps(_mm256_set1_epi32(0xffffffff)));
}

// ================== logical operations ===================
/**
    @brief  logical not
    @param  x - vfloat8 arg
    @retval   - return logical not of x
**/
static inline const vfloat8 operator!(const vfloat8 x)
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
static inline const vfloat8 operator*(const vfloat8 x, const vfloat8 y)
{
    return _mm256_mul_ps(x, y);
}

/**
    @brief  operator/
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return division of x and y
**/
static inline const vfloat8 operator/(const vfloat8 x, const vfloat8 y)
{
    return _mm256_div_ps(x, y);
}
/**
    @brief  operator+
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return sum of x and y
**/
static inline const vfloat8 operator+(const vfloat8 x, const vfloat8 y)
{
    return _mm256_add_ps(x, y);
}
/**
    @brief  operator-
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return subtraction of x and y
**/
static inline const vfloat8 operator-(const vfloat8 x, const vfloat8 y)
{
    return _mm256_sub_ps(x, y);
}
/**
    @brief  minimum of x and y
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return minimum of x and y
**/
static inline const vfloat8 min(const vfloat8 x, const vfloat8 y)
{
    return _mm256_min_ps(x, y);
}
/**
    @brief  maximum of x and y
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return maximum of x and y
**/
static inline const vfloat8 max(const vfloat8 x, const vfloat8 y)
{
    return _mm256_max_ps(x, y);
}

/**
    @brief  operator%
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return x mod y
**/
static inline const vfloat8 operator%(const vfloat8 x, const vfloat8 y)
{
    return _mm256_fmod_ps(x, y);
}

// ================== bitwise operations ===================

/**
    @brief  operator&
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise AND of x and y
**/
static inline const vfloat8 operator&(const vfloat8 x, const vfloat8 y)
{
    return _mm256_and_ps(x, y);
}
/**
    @brief  operator|
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise OR of x and y
**/
static inline const vfloat8 operator|(const vfloat8 x, const vfloat8 y)
{
    return _mm256_or_ps(x, y);
}
/**
    @brief  operator^
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return bitwise XOR of x and y
**/
static inline const vfloat8 operator^(const vfloat8 x, const vfloat8 y)
{
    return _mm256_xor_ps(x, y);
}

/**
    @brief  operator<<
    @param  x - operand to be shifted (must be castable to packed int)
    @param  n - operand containing ints specifying by how many bits to shift x left
    @retval   - return shifted-left result as packed floating-point number
**/
static inline const vfloat8 operator<<(const vfloat8 x, const vfloat8 n)
{
    return _mm256_castsi256_ps(_mm256_sllv_epi32(_mm256_castps_si256(x), _mm256_castps_si256(n)));
}

/**
    @brief  operator>>
    @param  x - operand to be shifted (must be castable to packed int)
    @param  n - operand containing ints specifying by how many bits to shift x right
    @retval   - return shifted-right result as packed floating-point number
**/
static inline const vfloat8 operator>>(const vfloat8 x, const vfloat8 n)
{
    return _mm256_castsi256_ps(_mm256_srlv_epi32(_mm256_castps_si256(x), _mm256_castps_si256(n)));
}

// ================== logical operations ===================

/**
    @brief  operator&&
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return logical AND of x and y
**/
static inline const vfloat8 operator&&(const vfloat8 x, const vfloat8 y)
{
    return x & y;
}
/**
    @brief  operator||
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - return logical OR of x and y
**/
static inline const vfloat8 operator||(const vfloat8 x, const vfloat8 y)
{
    return x | y;
}

// ================== comparison operations ===================

/**
    @brief  operator<
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is less than right
**/
static inline const vfloat8 operator<(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_LT_OS);
}
/**
    @brief  operator>=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is greater or equal than right
**/
static inline const vfloat8 operator>=(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_GE_OS);
}
/**
    @brief  operator>
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is greater than right
**/
static inline const vfloat8 operator>(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_GT_OS);
}
/**
    @brief  operator<=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if left object is less or equal than right
**/
static inline const vfloat8 operator<=(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_LE_OS);
}
/**
    @brief  operator==
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if objects are equal
**/
static inline const vfloat8 operator==(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_EQ_OS);
}
/**
    @brief  operator!=
    @param  x - vfloat8 arg
    @param  y - vfloat8 arg
    @retval   - true, if objects are not equal
**/
static inline const vfloat8 operator!=(const vfloat8 x, const vfloat8 y)
{
    return _mm256_cmp_ps(x, y, _CMP_NEQ_OS);
}

// ======================================================================
// ========================== TENARY operators ==========================
// ======================================================================

/**
    @brief  if merge operartor
    @param  then   - branch triggered when ifmask TRUE
    @param  els    - branch triggered when ifmask FALSE
    @param  ifmask - mask containing only 0s or 1s
    @retval        - return merged packed result
**/
static inline const vfloat8 blend(const vfloat8 then, const vfloat8 els, const vfloat8 ifmask)
{
    return _mm256_blendv_ps(els, then, ifmask);
}

// ======================================================================
// =========================== OTHER functions ==========================
// ======================================================================

#endif //_VFLOAT8_HPP_
