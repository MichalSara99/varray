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

    vdouble4(){};
    explicit vdouble4(const __m256d x) : __m256d(x)
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
};

#endif //_VDOUBLE4_HPP_
