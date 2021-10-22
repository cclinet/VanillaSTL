#include <execution>
#include <iostream>
#include <vector>

int main() {
    //    vanilla::allocator<int> alloc;
    //    // 演示少见的直接使用成员
    //    static_assert(std::is_same_v<int, decltype(alloc)::value_type>);
    //    int *p = alloc.allocate(1);// 一个 int 的空间
    //    alloc.deallocate(p, 1);    // 而它没了
    //
    //    std::vector<int, vanilla::allocator<int>> v(8);
    //    v.push_back(42);
    //    vanilla::test::array_test();
    //    vanilla::test::vector_test();
    auto a = std::vector<int>{4, 3, 2, 1};
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}