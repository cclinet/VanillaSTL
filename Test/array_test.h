#ifndef VANILLASTL_ARRAY_TEST_H
#define VANILLASTL_ARRAY_TEST_H
#include "array.h"
#include <iostream>
namespace vanilla::test {
    void array_test() {
        std::cout << "[===============================================================]\n";
        std::cout << "[------------------ Run container test: array ------------------]\n";
        std::cout << "[-------------------------- API test ---------------------------]\n";
        vanilla::array<int, 3> a = {1, 2, 3};
        []() { vanilla::array<int, 4> numbers{2, 4, 6, 8};
            std::cout << "Second element: " << numbers[1] << '\n';
            numbers[0] = 5;
            std::cout << "All numbers:";
            //            for (auto i : numbers) {
            //                std::cout << ' ' << i;
            //            }
            std::cout << '\n'; }();
    }

}// namespace vanilla::test
#endif//VANILLASTL_ARRAY_TEST_H
