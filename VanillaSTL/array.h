#ifndef VANILLASTL_ARRAY_H
#define VANILLASTL_ARRAY_H
#include <cstddef>
#include <iterator>
#include <cstddef>
namespace vanilla {
    template<typename T, std::size_t N>
    class array {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using pointer = value_type *;
        using const_pointer = const value_type *;
        using iterator = value_type *;
        using const_iterator = const value_type *;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        T data[N];

    public:
        constexpr reference at(size_type pos) {
            if (pos >= N)
                throw std::out_of_range("array::at");
            return data[pos];
        }
        constexpr const_reference at(size_type pos) const {
            if (pos >= N)
                throw std::out_of_range("array::at");
            return data[pos];
        }

        constexpr reference operator[](size_type pos) { return data[pos]; }
        constexpr const_reference operator[](size_type pos) const { return data[pos]; }

        // std::array<T,N>::begin, std::array<T,N>::cbegin
        constexpr iterator begin() noexcept { return iterator(&data[0]); };
        constexpr const_iterator begin() const noexcept { return const_iterator(&data[0]); };
        constexpr const_iterator cbegin() const noexcept { return const_iterator(&data[0]); };

        //std::array<T,N>::end, std::array<T,N>::cend
        constexpr iterator end() noexcept { return iterator(&data[N]); };
        constexpr const_iterator end() const noexcept { return const_iterator(&data[N]); };
        constexpr const_iterator cend() const noexcept { return const_iterator(&data[N]); };

        //std::array<T,N>::rbegin, std::array<T,N>::crbegin
        constexpr reverse_iterator rbegin() noexcept { return reverse_iterator(&data[N]); }
        constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(&data[N]); }
        constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(&data[N]); }

        //std::array<T,N>::rend, std::array<T,N>::crend
        constexpr reverse_iterator rend() noexcept { return reverse_iterator(&data[0]); }
        constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator(&data[0]); }
        constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator(&data[0]); }

        //std::array<T,N>::empty
        [[nodiscard]] constexpr bool empty() const noexcept { return N == 0; }

        //std::array<T,N>::size
        constexpr size_type size() const noexcept { return N; }

        //std::array<T,N>::max_size
        constexpr size_type max_size() const noexcept { return N; }

        //std::array<T,N>::fill
        constexpr void fill(const T &value) {
            for (const_reference tmp : value) {
                data++ = tmp;
            }
        }

        //std::array<T,N>::swap
        constexpr void swap(array &other) noexcept {
            std::swap_ranges(&data[0], &data[N], &other.data[0]);
        }
    };

//    template< class T, std::size_t N >
//    constexpr bool operator==( const std::array<T,N>& lhs,
//                              const std::array<T,N>& rhs ){return true;};
//
//    template< class T, std::size_t N >
//    constexpr /* see below */ operator<=>( const std::array<T,N>& lhs,
//                                          const std::array<T,N>& rhs ){return true;};
}// namespace vanilla
#endif//VANILLASTL_ARRAY_H
