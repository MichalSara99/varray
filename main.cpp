#include <iostream>
#include <string>

#include <immintrin.h>

int main(int argc, char const *argv[])
{

    // std::cout << "size: " << sizeof(__m256) / sizeof(float) << "\n";
    // std::cout << "size: " << sizeof(__m256d) / sizeof(double) << "\n";

    // varray<__m256> v0(7, _mm256_set1_ps(3.1415f));
    // varray<__m256d> v1(10, 3.1415);
    // varray<double> v2(11, std::exp(1.0));

    // double v00 = v0[0];
    // v0[1] = 2.714f;
    // double v01 = v0[1];
    // double v02 = v0[2];
    // double v03 = v0[3];

    // double v20 = v2[0];

    // std::cout << "v0[0]: " << v0[0] << "\n";

    // std::cout << "under: " << typeid(varray<__m256d>::dependent_type).name() << "\n";

    // auto const slc = v1[slice(2, 2, 1)];

    // varray<__m256d> cpy(slc);

    // varray<__m256d> slc1 = v1[slice(2, 2, 3)];

    ////// ==============================================

    // varray<__m256d> arr(11);

    // arr[0] = 1.0;
    // arr[1] = 2.0;
    // arr[2] = 3.0;
    // arr[3] = 4.0;
    // arr[4] = 5.0;
    // arr[5] = 6.0;
    // arr[6] = 7.0;
    // arr[7] = 8.0;
    // arr[8] = 9.0;
    // arr[9] = 10.0;
    // arr[10] = 11.0;

    // decltype(arr) slice2n = arr[slice(0, 6, 2)];

    ////// ========================================

    // varray<double> arrs(11);

    // arrs[0] = 1.0;
    // arrs[1] = 2.0;
    // arrs[2] = 3.0;
    // arrs[3] = 4.0;
    // arrs[4] = 5.0;
    // arrs[5] = 6.0;
    // arrs[6] = 7.0;
    // arrs[7] = 8.0;
    // arrs[8] = 9.0;
    // arrs[9] = 10.0;
    // arrs[10] = 11.0;

    // decltype(arrs) slices2n = arrs[slice(0, 6, 2)];

    std::cin.get();
    std::cin.get();
    return 0;
}
