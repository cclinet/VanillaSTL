#ifndef VANILLASTL_ALLOCATOR_H
#define VANILLASTL_ALLOCATOR_H
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <type_traits>

namespace vanilla {
    template<typename T>
    class allocator {
    public:
        using difference_type = std::ptrdiff_t;
        using propagate_on_container_move_assignment = std::true_type;
        using value_type = T;
        using size_type = std::size_t;


        constexpr allocator() noexcept = default;

        constexpr allocator(const allocator &other) noexcept = default;

        template<typename U>
        constexpr explicit allocator(const allocator<U> &other) noexcept {}

        constexpr ~allocator() = default;

        [[nodiscard]] constexpr T *allocate(std::size_t n) {
            if (std::numeric_limits<std::size_t>::max() / sizeof(T) < n)
                throw std::bad_array_new_length{};

            if (auto p = static_cast<T *>(::operator new(n * sizeof(T)))) {
                report(p, n);
                return p;
            }

            throw std::bad_alloc{};
        }

        constexpr void deallocate(T *p, std::size_t n) noexcept {
            report(p, n, false);
            ::operator delete(p);
        }

    private:
        void report(T *p, std::size_t n, bool alloc = true) const {
            std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
                      << " bytes at " << std::hex << std::showbase
                      << reinterpret_cast<void *>(p) << std::dec << '\n';
        }
    };

}// namespace vanilla
#endif//VANILLASTL_ALLOCATOR_H
