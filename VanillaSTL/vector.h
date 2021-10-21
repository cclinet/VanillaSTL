#ifndef VANILLASTL_VECTOR_H
#define VANILLASTL_VECTOR_H
#include <memory>
namespace vanilla {
    template<typename T,
             typename Allocator = vanilla::allocator<T>>
    class vector {
        using value_type = T;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = T &;
        using const_reference = const T &;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using iterator = value_type *;
        using const_iterator = const value_type *;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    private:
        iterator begin_;// 表示目前使用空间的头部
        iterator end_;  // 表示目前使用空间的尾部
        iterator cap_;  // 表示目前储存空间的尾部

    public:
        // 构造函数
//        constexpr vector() noexcept(noexcept(Allocator())) = default;
//        constexpr explicit vector(const Allocator &alloc) noexcept = default;
        constexpr vector(size_type count,
                         const T &value,
                         const Allocator &alloc = Allocator()) {
            begin_ = alloc.allocate(count);
            std::uninitialized_fill_n(begin_, count, value);
        }
    };
}// namespace vanilla
#endif//VANILLASTL_VECTOR_H
