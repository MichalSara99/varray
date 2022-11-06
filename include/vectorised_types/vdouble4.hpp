#if !defined(_VDOUBLE4_HPP_)
#define _VDOUBLE4_HPP_

#include <immintrin.h>
#include <iostream>
#include <typeinfo>

namespace
{

struct vint4Base
{
    inline operator __m256i() const noexcept
    {
        return pack;
    }

    __m256i pack;
};

} // namespace

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
    vdouble4(value_type x) : __m256d(_mm256_set1_pd(x))
    {
    }
    vdouble4(value_type x0, value_type x1, value_type x2, value_type x3) : __m256d(_mm256_setr_pd(x0, x1, x2, x3))
    {
    }

    vdouble4(const vdouble4 &) = default;
    vdouble4(vdouble4 &&) = default;
    vdouble4 &operator=(const vdouble4 &) = default;
    vdouble4 &operator=(vdouble4 &&) = default;

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

    inline vdouble4 &operator+=(const vdouble4 &x)
    {
        *this = _mm256_add_pd(*this, x);
        return *this;
    }

    inline vdouble4 &operator-=(const vdouble4 &x)
    {
        *this = _mm256_sub_pd(*this, x);
        return *this;
    }

    inline vdouble4 &operator*=(const vdouble4 &x)
    {
        *this = _mm256_mul_pd(*this, x);
        return *this;
    }

    inline vdouble4 &operator/=(const vdouble4 &x)
    {
        *this = _mm256_div_pd(*this, x);
        return *this;
    }
};

/**
    @struct vint4
    @brief Packed 4 64-bit int type
**/
struct vint4 : public vint4Base
{
    using value_type = int64_t;
    constexpr static std::size_t length = sizeof(__m256i) / sizeof(value_type);

    constexpr vint4(){};
    constexpr vint4(const __m256i x) : vint4Base{x}
    {
    }

    vint4(value_type x) : vint4Base{_mm256_set1_epi64x(x)}
    {
    }

    vint4(value_type x0, value_type x1, value_type x2, value_type x3) : vint4Base{_mm256_setr_epi64x(x0, x1, x2, x3)}
    {
    }

    vint4(const vint4 &) = default;
    vint4(vint4 &&) = default;
    vint4 &operator=(const vint4 &) = default;
    vint4 &operator=(vint4 &&) = default;

    const inline value_type &operator[](std::size_t idx) const
    {
        return reinterpret_cast<const value_type *>(this)[idx];
    }

    inline value_type &operator[](std::size_t idx)
    {
        return reinterpret_cast<value_type *>(this)[idx];
    }

    friend std::ostream &operator<<(std::ostream &out, const vint4 &x)
    {
        return out << "(" << x[0] << "," << x[1] << "," << x[2] << "," << x[3] << ")";
    }

    inline vint4 &operator+=(const vint4 &x)
    {
        *this = _mm256_add_epi64(*this, x);
        return *this;
    }

    inline vint4 &operator-=(const vint4 &x)
    {
        *this = _mm256_sub_epi64(*this, x);
        return *this;
    }
};

/**
    @struct vbool4
    @brief Packed 4 bool type
**/
struct vbool4 : public vint4
{
    using value_type = bool;

    vbool4() = default;
    vbool4(vint4 x) : vbool4(x[0], x[1], x[2], x[3])
    {
    }

    vbool4(value_type x) : vint4(-vint4::value_type(x))
    {
    }

    vbool4(value_type x0, value_type x1, value_type x2, value_type x3)
        : vint4(-vint4::value_type(x0), -vint4::value_type(x1), -vint4::value_type(x2), -vint4::value_type(x3))
    {
    }

    vbool4(const vbool4 &) = default;
    vbool4(vbool4 &&) = default;
    vbool4 &operator=(const vbool4 &) = default;
    vbool4 &operator=(vbool4 &&) = default;
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
static inline vdouble4 operator-(const vdouble4 &x)
{
    return _mm256_xor_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
}

/**
    @brief  operator-
    @param  x - vint4 arg
    @retval   - return minus of x
**/
static inline vint4 operator-(const vint4 &x)
{
    return _mm256_sub_epi64(_mm256_set1_epi64x(0), x);
}

/**
    @brief  operator+
    @param  x - vdouble4 arg
    @retval   - return plus of x
**/
static inline vdouble4 operator+(const vdouble4 &x)
{
    return x;
}

/**
    @brief  operator+
    @param  x - vint4 arg
    @retval   - return plus of x
**/
static inline vint4 operator+(const vint4 &x)
{
    return x;
}

// ================== bitwise operations ===================
/**
    @brief  bitwise not
    @param  x - vdouble4 arg
    @retval   - return bitwise not of x
**/
static inline vdouble4 operator~(const vdouble4 &x)
{
    return _mm256_xor_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0xffffffffffffffff)));
}

/**
    @brief  bitwise not
    @param  x - vint4 arg
    @retval   - return bitwise not of x
**/
static inline vint4 operator~(const vint4 &x)
{
    return _mm256_xor_si256(x, _mm256_set1_epi64x(0xffffffffffffffff));
}

/**
    @brief  bitwise not
    @param  x - vbool4 arg
    @retval   - return bitwise not of x
**/
static inline vbool4 operator~(const vbool4 &x)
{
    return vint4(_mm256_xor_si256(x, _mm256_set1_epi64x(0xffffffffffffffff)));
}

// ================== logical operations ===================
/**
    @brief  logical not
    @param  x - vdouble4 arg
    @retval   - return logical not of x
**/
static inline vbool4 operator!(const vbool4 &x)
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
static inline vdouble4 operator*(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_mul_pd(x, y);
}

/**
    @brief  operator/
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return division of x and y
**/
static inline vdouble4 operator/(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_div_pd(x, y);
}

/**
    @brief  operator+
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return sum of x and y
**/
static inline vdouble4 operator+(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_add_pd(x, y);
}

/**
    @brief  operator+
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return sum of x and y
**/
static inline vint4 operator+(const vint4 &x, const vint4 &y)
{
    return _mm256_add_epi64(x, y);
}

/**
    @brief  operator-
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return subtraction of x and y
**/
static inline vdouble4 operator-(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_sub_pd(x, y);
}

/**
    @brief  operator-
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return subtraction of x and y
**/
static inline vint4 operator-(const vint4 &x, const vint4 &y)
{
    return _mm256_sub_epi64(x, y);
}

/**
    @brief  minimum of x and y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return minimum of x and y
**/
static inline vdouble4 min(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_min_pd(x, y);
}

/**
    @brief  minimum of x and y
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return minimum of x and y
**/
static inline vint4 min(const vint4 &x, const vint4 &y)
{
    return _mm256_min_epi64(x, y);
}

/**
    @brief  maximum of x and y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return maximum of x and y
**/
static inline vdouble4 max(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_max_pd(x, y);
}

/**
    @brief  maximum of x and y
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return maximum of x and y
**/
static inline vint4 max(const vint4 &x, const vint4 &y)
{
    return _mm256_max_epi64(x, y);
}

/**
    @brief  operator%
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return x mod y
**/
static inline vdouble4 operator%(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_fmod_pd(x, y);
}

// ================== bitwise operations ===================

/**
    @brief  bitwise AND
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise AND of x and y
**/
static inline vdouble4 operator&(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_and_pd(x, y);
}

/**
    @brief  bitwise AND
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return bitwise AND of x and y
**/
static inline vint4 operator&(const vint4 &x, const vint4 &y)
{
    return _mm256_and_si256(x, y);
}

/**
    @brief  bitwise AND
    @param  x - vbool4 arg
    @param  y - vbool4 arg
    @retval   - return bitwise AND of x and y
**/
static inline vbool4 operator&(const vbool4 &x, const vbool4 &y)
{
    return vint4(_mm256_and_si256(x, y));
}

/**
    @brief  logical AND
    @param  x - vbool4 arg
    @param  y - vbool4 arg
    @retval   - return bitwise AND of x and y
**/
static inline vbool4 operator&&(const vbool4 &x, const vbool4 &y)
{
    return x & y;
}

/**
    @brief  bitwise OR
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise OR of x and y
**/
static inline vdouble4 operator|(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_or_pd(x, y);
}

/**
    @brief  bitwise OR
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return bitwise OR of x and y
**/
static inline vint4 operator|(const vint4 &x, const vint4 &y)
{
    return _mm256_or_si256(x, y);
}

/**
    @brief  bitwise OR
    @param  x - vbool4 arg
    @param  y - vbool4 arg
    @retval   - return bitwise OR of x and y
**/
static inline vbool4 operator|(const vbool4 &x, const vbool4 &y)
{
    return vint4(_mm256_or_si256(x, y));
}

/**
    @brief  logical OR
    @param  x - vbool4 arg
    @param  y - vbool4 arg
    @retval   - return bitwise OR of x and y
**/
static inline vbool4 operator||(const vbool4 &x, const vbool4 &y)
{
    return x | y;
}

/**
    @brief  bitwise XOR
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vdouble4 operator^(const vdouble4 &x, const vdouble4 &y)
{
    return _mm256_xor_pd(x, y);
}

/**
    @brief  bitwise XOR
    @param  x - vint4 arg
    @param  y - vint4 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vint4 operator^(const vint4 &x, const vint4 &y)
{
    return _mm256_xor_si256(x, y);
}

/**
    @brief  bitwise XOR
    @param  x - vbool4 arg
    @param  y - vbool4 arg
    @retval   - return bitwise XOR of x and y
**/
static inline vbool4 operator^(const vbool4 &x, const vbool4 &y)
{
    return vint4(_mm256_xor_si256(x, y));
}

/**
    @brief  left shift <<
    @param  x - vint4 arg
    @param  n - vint4 arg
    @retval   - return x << n
**/
static inline vint4 operator<<(const vint4 &x, const vint4 &n)
{
    return _mm256_sllv_epi64(x, n);
}

/**
    @brief  right shift >>
    @param  x - vint4 arg
    @param  n - vint4 arg
    @retval   - return x >> n
**/
static inline vint4 operator>>(const vint4 &x, const vint4 &n)
{
    return _mm256_srlv_epi64(x, n);
}

// ================== comparison operations ===================

/**
    @brief  operator<
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is less than right
**/
static inline vbool4 operator<(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_LT_OS)));
}
/**
    @brief  operator>=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is greater or equal than right
**/
static inline vbool4 operator>=(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_GE_OS)));
}
/**
    @brief  operator>
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is greater than right
**/
static inline vbool4 operator>(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_GT_OS)));
}
/**
    @brief  operator<=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if left object is less or equal than right
**/
static inline vbool4 operator<=(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_LE_OS)));
}
/**
    @brief  operator==
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if objects are equal
**/
static inline vbool4 operator==(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_EQ_OS)));
}
/**
    @brief  operator!=
    @param  x - vdouble4 arg
    @param  y - vdouble4 arg
    @retval   - true, if objects are not equal
**/
static inline vbool4 operator!=(const vdouble4 &x, const vdouble4 &y)
{
    return vint4(_mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_NEQ_OS)));
}

// ======================================================================
// ========================== TENARY operators ==========================
// ======================================================================

/**
    @brief  if merge operartor
    @param  thenExpr    - vdouble4
    @param  elseExpr    - vdouble4
    @param  ifExpr      - vbool4
    @retval             - return merged packed result
**/
static inline const vdouble4 blend(const vdouble4 &thenExpr, const vdouble4 &elseExpr, const vbool4 &ifExpr)
{
    return _mm256_blendv_pd(elseExpr, thenExpr, _mm256_castsi256_pd(ifExpr));
}

// ======================================================================
// =========================== OTHER functions ==========================
// ======================================================================
namespace
{
static inline size_t countMaskZeros(const vbool4 &x)
{
    return (vbool4::length - _mm_popcnt_u64(_mm256_movemask_pd(_mm256_castsi256_pd(x))));
}
} // namespace

/**
    @brief  Are all elements of the packed bool TRUE
    @param  x - vbool4 arg
    @retval   -
**/
static inline bool all(const vbool4 &x)
{
    return (countMaskZeros(x) == 0);
}

/**
    @brief  Are any elements of the packed bool TRUE
    @param  x -  vbool4 arg
    @retval   -
**/
static inline bool any(const vbool4 &x)
{
    return (countMaskZeros(x) != vbool4::length);
}

/**
    @brief  Are all elements of the packed bool FALSE
    @param  x -  vbool4 arg
    @retval   -
**/
static inline bool none(const vbool4 &x)
{
    return (countMaskZeros(x) == vbool4::length);
}
#endif //_VDOUBLE4_HPP_
