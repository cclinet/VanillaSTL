#include "allocator.h"
#include "allocator_traits.h"
#include <type_traits>
#include <vector>


int main() {
    Vanilla::allocator<int> alloc;
    // 演示少见的直接使用成员
    static_assert(std::is_same_v<int, decltype(alloc)::value_type>);
    int* p = alloc.allocate(1);  // 一个 int 的空间
    alloc.deallocate(p, 1);      // 而它没了

    std::vector<int, Vanilla::allocator<int>> v(8);
    v.push_back(42);
    std::allocator_traits<int>
}