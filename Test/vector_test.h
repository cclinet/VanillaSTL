#ifndef VANILLASTL_VECTOR_TEST_H
#define VANILLASTL_VECTOR_TEST_H
#include "vector.h"
#include <vector>
namespace vanilla::test {
    void vector_test() {
        auto stds = std::vector<int>(3, 0);
        auto stdv = vanilla::vector<int>(3, 0);
    }
}// namespace vanilla::test
#endif//VANILLASTL_VECTOR_TEST_H
