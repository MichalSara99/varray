#if !defined(_VDOUBLE4_HPP_)
#define _VDOUBLE4_HPP_

#include <immintrin.h>
#include <iostream>
#include <typeinfo>

/**
    @struct vdouble4
    @brief  Packed double-precision type
**/
struct vdouble4 : public __m256d
{

  public:
    using value_type = double;
    constexpr static std::size_t length = sizeof(__m256d) / sizeof(value_type);

    constexpr vdouble4(){};
    constexpr vdouble4(const __m256d x) : __m256d(x)
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

// ======================================================================
// ========================== UNARY operators ===========================
// ======================================================================

// ================== fundamental operations ===================

/**
    @brief  operator-
    @param  x - vdouble4 arg
    @retval   - return minus of x
**/
static inline const vdouble4 operator-(const vdouble4 x)
{
    return _mm256_xor_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
}
/**
    @brief  operator+
    @param  x - vdouble4 arg
    @retval   - return plus of x
**/
static inline const vdouble4 operator+(const vdouble4 x)
{
    return x;
}

// ================== bitwise operations ===================
/**
    @brief  bitwise not
    @param  x - vdouble4 arg
    @retval   - return bitwise not of x
**/
static inline const vdouble4 operator~(const vdouble4 x)
{
    return _mm256_xor_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0xffffffffffffffff)));
}

// ================== logical operations ===================
/**
    @brief  logical not
    @param  x - vdouble4 arg
    @retval   - return logical not of x
**/
static inline const vdouble4 operator!(const vdouble4 x)
{
    return ~x;
}

// ======================================================================
// ========================== BINARY operators ==========================
// ======================================================================

// ================== fundamental operations ===================
/**
    @brief  operator*
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return multiplication of x and y
**/
static inline const vdouble4 operator*(const vdouble4 x, const vdouble4 y)
{
    return _mm256_mul_pd(x, y);
}
/**
    @brief  operator/
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return division of x and y
**/
static inline const vdouble4 operator/(const vdouble4 x, const vdouble4 y)
{
    return _mm256_div_pd(x, y);
}
/**
    @brief  operator+
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return sum of x and y
**/
static inline const vdouble4 operator+(const vdouble4 x, const vdouble4 y)
{
    return _mm256_add_pd(x, y);
}
/**
    @brief  operator-
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return subtraction of x and y
**/
static inline const vdouble4 operator-(const vdouble4 x, const vdouble4 y)
{
    return _mm256_sub_pd(x, y);
}
/**
    @brief  minimum of x and y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return minimum of x and y
**/
static inline const vdouble4 min(const vdouble4 x, const vdouble4 y)
{
    return _mm256_min_pd(x, y);
}
/**
    @brief  maximum of x and y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return maximum of x and y
**/
static inline const vdouble4 max(const vdouble4 x, const vdouble4 y)
{
    return _mm256_max_pd(x, y);
}

/**
    @brief  operator%
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return x mod y
**/
static inline const vdouble4 operator%(const vdouble4 x, const vdouble4 y)
{
    return _mm256_fmod_pd(x, y);
}

// ================== bitwise operations ===================

/**
    @brief  operator&
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise AND of x and y
**/
static inline const vdouble4 operator&(const vdouble4 x, const vdouble4 y)
{
    return _mm256_and_pd(x, y);
}
/**
    @brief  operator|
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise OR of x and y
**/
static inline const vdouble4 operator|(const vdouble4 x, const vdouble4 y)
{
    return _mm256_or_pd(x, y);
}
/**
    @brief  operator^
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise XOR of x and y
**/
static inline const vdouble4 operator^(const vdouble4 x, const vdouble4 y)
{
    return _mm256_xor_pd(x, y);
}

/**
    @brief  operator<<
    @param  x - operand to be shifted (must be castable to packed int64t)
    @param  n - operand containing int64ts specifying by how many bits to shift x left
    @retval   - return shifted-left result as packed floating-point number
**/
static inline const vdouble4 operator<<(const vdouble4 x, const vdouble4 n)
{
    return _mm256_castsi256_pd(_mm256_sllv_epi64(_mm256_castpd_si256(x), _mm256_castpd_si256(n)));
}

/**
    @brief  operator>>
    @param  x - operand to be shifted (must be castable to packed int64t)
    @param  n - operand containing int64ts specifying by how many bits to shift x right
    @retval   - return shifted-right result as packed floating-point number
**/
static inline const vdouble4 operator>>(const vdouble4 x, const vdouble4 n)
{
    return _mm256_castsi256_pd(_mm256_srlv_epi64(_mm256_castpd_si256(x), _mm256_castpd_si256(n)));
}

// ================== logical operations ===================

/**
    @brief  operator&&
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return logical AND of x and y
**/
static inline const vdouble4 operator&&(const vdouble4 x, const vdouble4 y)
{
    return x & y;
}
/**
    @brief  operator||
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return logical OR of x and y
**/
static inline const vdouble4 operator||(const vdouble4 x, const vdouble4 y)
{
    return x | y;
}

// ================== comparison operations ===================

/**
    @brief  operator<
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is less than right
**/
static inline const vdouble4 operator<(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_LT_OS);
}
/**
    @brief  operator>=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is greater or equal than right
**/
static inline const vdouble4 operator>=(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_GE_OS);
}
/**
    @brief  operator>
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is greater than right
**/
static inline const vdouble4 operator>(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_GT_OS);
}
/**
    @brief  operator<=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is less or equal than right
**/
static inline const vdouble4 operator<=(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_LE_OS);
}
/**
    @brief  operator==
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if objects are equal
**/
static inline const vdouble4 operator==(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_EQ_OS);
}
/**
    @brief  operator!=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if objects are not equal
**/
static inline const vdouble4 operator!=(const vdouble4 x, const vdouble4 y)
{
    return _mm256_cmp_pd(x, y, _CMP_NEQ_OS);
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
static inline const vdouble4 blend(const vdouble4 then, const vdouble4 els, const vdouble4 ifmask)
{
    return _mm256_blendv_pd(els, then, ifmask);
}

// ======================================================================
// =========================== OTHER functions ==========================
// ======================================================================

#endif //_VDOUBLE4_HPP_
