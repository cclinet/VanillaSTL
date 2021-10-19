#ifndef VANILLASTL_ALLOCATOR_H
#define VANILLASTL_ALLOCATOR_H
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <type_traits>

namespace Vanilla {
    template<class T>
    class allocator {
    public:
        typedef T value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::true_type propagate_on_container_move_assignment;

        constexpr allocator() noexcept {}

        constexpr allocator(const allocator &other) noexcept {}

        template<class U>
        constexpr explicit allocator(const allocator<U> &other) noexcept {}

        constexpr ~allocator() {}

        [[nodiscard]] constexpr T *allocate(std::size_t n) {
            if (std::numeric_limits<std::size_t>::max() / sizeof(T) < n)
                throw std::bad_array_new_length{};

            if (auto p = static_cast<T *>(std::malloc(n * sizeof(T)))) {
                report(p, n);
                return p;
            }

            throw std::bad_alloc{};
        }

        constexpr void deallocate(T *p, std::size_t n) noexcept {
            report(p, n, false);
            std::free(p);
        }

    private:
        void report(T *p, std::size_t n, bool alloc = true) const {
            std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
                      << " bytes at " << std::hex << std::showbase
                      << reinterpret_cast<void *>(p) << std::dec << '\n';
        }
    };


}// namespace Vanilla
#endif//VANILLASTL_ALLOCATOR_H
