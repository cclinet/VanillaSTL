#ifndef VANILLASTL_ALLOCATOR_H
#define VANILLASTL_ALLOCATOR_H
#include <cstddef>
#include <cstdlib>
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

        constexpr allocator() noexcept = default;

        constexpr allocator(const allocator &other) noexcept = default;

        template<class U>
        constexpr explicit allocator(const allocator<U> &other) noexcept {}

        [[nodiscard]] constexpr T *allocate(std::size_t n) {
            if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
                throw std::bad_array_new_length{};

            if (auto p = static_cast<T *>(std::malloc(n * sizeof(T)))) {
                //                report(p, n);
                return p;
            }

            throw std::bad_alloc{};
        }

        void deallocate(T *p, std::size_t n) noexcept {
            report(p, n, 0);
            std::free(p);
        }
    };


}// namespace Vanilla
#endif//VANILLASTL_ALLOCATOR_H
