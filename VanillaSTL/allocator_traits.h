//
// Created by cclin on 10/18/21.
//

#ifndef VANILLASTL_ALLOCATOR_TRAITS_H
#define VANILLASTL_ALLOCATOR_TRAITS_H

namespace Vanilla {
    template<class Alloc>
    class allocator_traits {
    public:
        typedef Alloc allocator_type;
        typedef typename Alloc::value_type value_type;
        typedef value_type *pointer;
        typedef std::pointer_traits<pointer>::rebind<const value_type> const_pointer;
        typedef std::pointer_traits<pointer>::rebind<void> void_pointer;
        typedef std::pointer_traits<pointer>::rebind<const void> const_void_pointer;
        typedef typename Alloc::difference_type difference_type;
        typedef typename Alloc::size_type size_type;
        typedef std::false_type propagate_on_container_copy_assignment;
        typedef Alloc::propagate_on_container_move_assignment propagate_on_container_move_assignment;
        typedef std::false_type propagate_on_container_swap;
        typedef typename std::is_empty<Alloc>::type is_always_equal;

    private:
    };
}// namespace Vanilla

#endif//VANILLASTL_ALLOCATOR_TRAITS_H
