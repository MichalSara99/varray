#if !defined(_VARRAY_HPP_)
#define _VARRAY_HPP_

#include "macros.hpp"
#include "varray_math.hpp"
#include "varray_traits.hpp"
#include "varray_utils.hpp"
#include <memory>

// FORWARD REFERENCES:
struct slice;

template <typename T> struct slice_varray;

/**

    @class   varray
    @brief   array that supports vectorised intrinsics types __m256,__256d (AVX, AVX2)
    @details ~
    @tparam  T - double, float, __m256, __m256d

**/
template <typename T> class varray
{

  private:
    std::size_t size_;
    std::size_t vsize_;
    std::shared_ptr<T[]> ptr_;

  public:
    using value_type = T;
    using dependent_type = underlying_type_t<T>;
    static constexpr size_t length_type = length_of_type<T>();

    varray() noexcept
    {
        init_();
    }

    varray(std::size_t size) noexcept
    {
        init_();
        grow_(size);
    }

    varray(std::size_t size, T val) noexcept
    {
        init_();
        grow_(size, val);
    }

    template <typename = enable_if_packed<T>> varray(std::size_t size, dependent_type val) noexcept
    {
        init_();
        grow_(size, val);
    }

    varray(const slice_varray<T> &slicearr)
    {
        init_();
        *this = slicearr;
    }

    varray(varray<T> const &) = default;
    varray(varray<T> &&) = default;

    varray deepcopy() const
    {
        varray tmp(size());
        for (std::size_t i = 0; i < tmp.size(); ++i)
            tmp[i] = this->operator[](i);
        return tmp;
    }

    varray &operator=(varray<T> const &) = default;
    varray &operator=(varray<T> &&) = default;

    ~varray()
    {
    }

    varray &operator=(const slice_varray<T> &slicearr)
    {
        init_();
        grow_(slicearr.count, slicearr._ptr(), slicearr.start, slicearr.inc);
        return *this;
    }

    varray operator+() const
    {
        const size_t sz = size();
        varray<T> ans(sz);
        for (size_t idx = 0; idx < sz; ++idx)
        {
            ans[idx] = +getr<T>(ptr_, idx);
        }
        return ans;
    }

    varray operator-() const
    {
        const size_t sz = size();
        varray<T> ans(sz);
        for (size_t idx = 0; idx < sz; ++idx)
        {
            ans[idx] = -getr<T>(ptr_, idx);
        }
        return ans;
    }

    varray operator~() const
    {
        const size_t sz = size();
        varray<T> ans(sz);
        for (size_t idx = 0; idx < sz; ++idx)
        {
            ans[idx] = ~getr<T>(ptr_, idx);
        }
        return ans;
    }

    //_Boolarray operator!() const
    //{
    //    const size_t _Size = size();
    //    valarray<bool> _Ans(_Size);
    //    for (size_t _Idx = 0; _Idx < _Size; ++_Idx)
    //    {
    //        _Ans[_Idx] = !_Myptr[_Idx];
    //    }
    //    return _Ans;
    //}

    varray &operator*=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) *= right;
        }
        return *this;
    }

    varray &operator/=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) /= right;
        }
        return *this;
    }

    varray &operator%=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) %= right;
        }
        return *this;
    }

    varray &operator+=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) += right;
        }
        return *this;
    }

    varray &operator-=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) -= right;
        }
        return *this;
    }

    varray &operator^=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) ^= right;
        }
        return *this;
    }

    varray &operator&=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) &= right;
        }
        return *this;
    }

    varray &operator|=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) |= right;
        }
        return *this;
    }

    varray &operator<<=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) <<= right;
        }
        return *this;
    }

    varray &operator>>=(const dependent_type &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) >>= right;
        }
        return *this;
    }

    varray &operator*=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) *= right[idx];
        }
        return *this;
    }

    varray &operator/=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) /= right[idx];
        }
        return *this;
    }

    varray &operator%=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) %= right[idx];
        }
        return *this;
    }

    varray &operator+=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) += right[idx];
        }
        return *this;
    }

    varray &operator-=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) -= right[idx];
        }
        return *this;
    }

    varray &operator^=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) ^= right[idx];
        }
        return *this;
    }

    varray &operator|=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) |= right[idx];
        }
        return *this;
    }

    varray &operator&=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) &= right[idx];
        }
        return *this;
    }

    varray &operator<<=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) <<= right[idx];
        }
        return *this;
    }

    varray &operator>>=(const varray<T> &right)
    {
        const size_t sz = size();
        for (size_t idx = 0; idx < sz; ++idx)
        {
            getw<T>(ptr_, idx) >>= right[idx];
        }
        return *this;
    }

    inline constexpr std::size_t size() const
    {
        return size_;
    }

    inline constexpr std::size_t vsize() const
    {
        return vsize_;
    }

    inline const dependent_type &operator[](std::size_t idx) const noexcept
    {
        VERIFY(idx < size_, "operator[]: idx out of range");
        return getr<T>(ptr_, idx);
    }

    inline dependent_type &operator[](std::size_t idx) noexcept
    {
        VERIFY(idx < size_, "operator[]: idx out of range");
        return getw<T>(ptr_, idx);
    }

    inline const dependent_type &atomicAt(std::size_t idx) const noexcept
    {
        VERIFY(idx < size_, "atomicAt: idx out of range");
        return getr<T>(ptr_, idx);
    }

    inline dependent_type &atomicAt(std::size_t idx) noexcept
    {
        VERIFY(idx < size_, "atomicAt: idx out of range");
        return getw<T>(ptr_, idx);
    }

    inline const T &at(std::size_t idx) const noexcept
    {
        VERIFY(idx < vsize_, "at: idx out of range");
        return ptr_[idx];
    }

    inline T &at(std::size_t idx) noexcept
    {
        VERIFY(idx < vsize_, "at: idx out of range");
        return ptr_[idx];
    }

    varray operator[](slice slicearr) const
    {
        return varray<T>(slice_varray<T>(slicearr, ptr_));
    }

    slice_varray<T> operator[](slice slicearr)
    {
        return slice_varray<T>(slicearr, ptr_);
    }

  private:
    std::size_t get_vsize(std::size_t new_size)
    {
        std::size_t count = new_size / length_type;
        if (new_size % length_type > 0)
        {
            count++;
        }
        return count;
    }

    void init_() noexcept
    {
        size_ = 0;
        vsize_ = 0;
        ptr_ = nullptr;
    }

    void grow_(std::size_t new_size)
    {
        if (new_size > 0)
        {
            size_ = new_size;
            vsize_ = get_vsize(new_size);
            ptr_.reset(new T[vsize_]);
        }
    }

    void grow_(std::size_t new_size, T val)
    {
        if (new_size > 0)
        {
            size_ = new_size;
            vsize_ = get_vsize(new_size);
            ptr_.reset(new T[vsize_]);
            for (std::size_t t = 0; t < vsize_; ++t)
            {
                ptr_[t] = val;
            }
        }
    }

    void grow_(std::size_t new_size, const std::shared_ptr<T[]> &ptr, std::size_t start, std::size_t inc)
    {
        if (new_size > 0)
        {
            size_ = new_size;
            vsize_ = get_vsize(new_size);
            ptr_.reset(new T[vsize_]);
            std::size_t stride = start;
            for (std::size_t t = 0; t < size_; ++t, stride += inc)
            {
                getw<T>(ptr_, t) = getr<T>(ptr, stride);
            }
        }
    }

    template <typename = enable_if_packed<T>> void grow_(std::size_t new_size, dependent_type val)
    {
        if (new_size > 0)
        {
            size_ = new_size;
            vsize_ = get_vsize(new_size);
            ptr_.reset(new T[vsize_]);
            for (std::size_t t = 0; t < vsize_; ++t)
            {
                ptr_[t] = _mm256_set1(val);
            }
        }
    }
};

/**
    @struct slice
    @brief Defines a slice for varray
**/
struct slice
{
    std::size_t start, count, inc;

    slice(size_t off, size_t cnt, size_t increment) noexcept : start(off), count(cnt), inc(increment)
    {
    }

    friend bool operator==(const slice &left, const slice &right) noexcept
    {
        return left.start == right.start && left.count == right.count && left.inc == right.inc;
    }
};

template <typename T> struct slice_varray : public slice
{
    using value_type = T;
    using dependent_type = underlying_type_t<T>;

    //===

    void operator=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) = right[idx];
        }
    }

    void operator=(const T &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) = right;
        }
    }

    template <typename = enable_if_packed<T>> void operator=(const dependent_type &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) = right;
        }
    }

    void operator*=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) *= right[idx];
        }
    }

    void operator/=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) /= right[idx];
        }
    }

    void operator%=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) %= right[idx];
        }
    }

    void operator+=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) += right[idx];
        }
    }

    void operator-=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) -= right[idx];
        }
    }

    void operator^=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) ^= right[idx];
        }
    }

    void operator&=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) &= right[idx];
        }
    }

    void operator|=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) |= right[idx];
        }
    }

    void operator<<=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) <<= right[idx];
        }
    }

    void operator>>=(const varray<T> &right) const
    {
        size_t off = start;
        for (size_t idx = 0; idx < count; ++idx, off += inc)
        {
            getw<T>(ptr_, off) >>= right[idx];
        }
    }

    //===

    const std::shared_ptr<T[]> &_ptr() const
    {
        return ptr_;
    }

    slice_varray() = delete;

    slice_varray(const slice_varray &) = default;

    const slice_varray &operator=(const slice_varray &right) const
    {
        std::size_t dst_start = start;
        std::size_t src_start = right.start;
        for (std::size_t idx = 0; idx < count; ++idx, dst_start += inc, src_start += right.inc)
        {
            getw<T>(ptr_, idx) = getr<T>(right.ptr_, idx);
        }
        return *this;
    }

  private:
    friend varray<T>;

    slice_varray(const slice &slc, const std::shared_ptr<T[]> &data) : slice(slc), ptr_(data)
    {
    }

    std::shared_ptr<T[]> ptr_;
};

template <typename T> _NODISCARD varray<T> abs(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gabs<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> acos(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gacos<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> asin(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gasin<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> atan(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gatan<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> atan2(const varray<T> &valY, const varray<T> &valX)
{
    VERIFY(valY.vsize() == valX.vsize(), "atan2:vsize differs");
    VERIFY(valY.size() == valX.size(), "atan2:size differs");
    const size_t sz = valY.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(valY.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gatan2<T>(valY.at(idx), valX.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> cos(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gcos<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> cosh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gcosh<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> exp(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gexp<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> log(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = glog<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> log10(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = glog10<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> pow(const varray<T> &valY, const varray<T> &valX)
{
    VERIFY(valY.vsize() == valX.vsize(), "pow:vsize differs");
    VERIFY(valY.size() == valX.size(), "pow:size differs");
    const size_t sz = valY.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(valY.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gpow<T>(valY.at(idx), valX.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> sin(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gsin<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> sinh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gsinh<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> sqrt(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gsqrt<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> tan(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gtan<T>(val.at(idx));
    }
    return ans;
}

template <typename T> _NODISCARD varray<T> tanh(const varray<T> &val)
{
    const size_t sz = val.vsize();
    const size_t stride = length_of_type<T>();
    varray<T> ans(val.size());
    for (std::size_t idx = 0; idx < sz; idx += stride)
    {
        ans.at(idx) = gtanh<T>(val.at(idx));
    }
    return ans;
}

#endif ///_VARRAY_HPP_
