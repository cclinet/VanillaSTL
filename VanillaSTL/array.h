#ifndef VANILLASTL_ARRAY_H
#define VANILLASTL_ARRAY_H
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
        constexpr iterator begin() noexcept { return iterator(data); };
        constexpr const_iterator begin() const noexcept { return const_iterator(data); };
        constexpr const_iterator cbegin() const noexcept { return const_iterator(data); };
        //std::array<T,N>::end, std::array<T,N>::cend
        constexpr iterator end() noexcept { return data + N; };
        constexpr const_iterator end() const noexcept { return data + N; };
        constexpr const_iterator cend() const noexcept { return data + N; };
    };
}// namespace vanilla
#endif//VANILLASTL_ARRAY_H
