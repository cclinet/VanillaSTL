#ifndef VANILLASTL_VECTOR_TEST_H
#define VANILLASTL_VECTOR_TEST_H
#include "vector.h"
#include <vector>
namespace vanilla::test {
    void vector_test() {
        auto stds = std::vector<int, vanilla::allocator<int>>(3, 0);
        auto stdv = vanilla::vector<int>(3, 5);
        for (auto i: stdv){
            std::cout<<i<<' ';
        }
    }
}// namespace vanilla::test
#endif//VANILLASTL_VECTOR_TEST_H
