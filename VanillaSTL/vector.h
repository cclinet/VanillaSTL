#ifndef VANILLASTL_VECTOR_H
#define VANILLASTL_VECTOR_H
#include <memory>
#include "allocator.h"
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
        allocator_type al;

    public:
        // 构造函数
        constexpr vector() noexcept(noexcept(Allocator())) : al(Allocator()), begin_(nullptr), end_(nullptr), cap_(nullptr){};
        constexpr explicit vector(const Allocator &alloc) noexcept : al(alloc), begin_(nullptr), end_(nullptr), cap_(nullptr){};
        constexpr ~vector() {
            al.deallocate(begin_, cap_ - begin_);
        };
        constexpr vector(size_type count,
                         const T &value,
                         const Allocator &alloc = Allocator()) : al(alloc) {
            begin_ = al.allocate(count);
            std::uninitialized_fill_n(begin_, count, value);
            cap_ = end_ = begin_ + count;
        }

        constexpr explicit vector(size_type count,
                                  const Allocator &alloc = Allocator()) : vector(count, new T(), alloc){};

        template<class InputIt, std::_RequireInputIter<InputIt>>
        constexpr vector(InputIt first, InputIt last,
                         const Allocator &alloc = Allocator()) : al(alloc) {}

        constexpr vector(const vector &other) {}
        constexpr vector(const vector &other, const Allocator &alloc) {}
        constexpr vector(vector &&other) noexcept {};
        constexpr vector(vector &&other, const Allocator &alloc){};
        constexpr vector(std::initializer_list<T> init,
                         const Allocator &alloc = Allocator()){};


        constexpr iterator begin() noexcept {
            return begin_;
        }
        constexpr iterator end() noexcept {
            return end_;
        }

        constexpr void push_back(const T &value) {
            if (end_ != cap_) {
                size_type count = capacity() + 1;
                iterator new_begin_ = al.allocate(count);
                std::uninitialized_move_n(begin_, count, new_begin_);
                *(new_begin_ + count - 1) = value;
                al.deallocate(begin_, count - 1);
                begin_ = new_begin_;
                cap_ = end_ = begin_ + count;
            } else {
            }
        }

        constexpr size_type capacity() const noexcept {
            if (begin_) {
                return cap_ - begin_;
            }
            return 0;
        }
        constexpr size_type size() const noexcept {
            if (begin_) {
                return end_ - begin_;
            }
            return 0;
        }
        [[nodiscard]] constexpr bool empty() const noexcept {
            return (!begin_) || (end_ - begin_ == 0);
        }
    };
}// namespace vanilla
#endif//VANILLASTL_VECTOR_H
