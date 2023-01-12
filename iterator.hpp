#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
    template <typename _Iter>
    class iterator
    {
    public:
        typedef _Iter iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type value_type;
        typedef typename iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename iterator_traits<iterator_type>::pointer pointer;
        typedef typename iterator_traits<iterator_type>::reference reference;

        // CONSTRUCTOR
        iterator(pointer ptr_) : ptr_(ptr_) {}
        iterator() : ptr_(nullptr) {}
        iterator(const iterator &cp) : ptr_(cp.ptr_) {}
        iterator &operator=(const iterator &cp)
        {
            ptr_ = cp.ptr_;
            return *this;
        }
        // compared for equivalence
        bool operator==(const iterator &other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator &other) const { return ptr_ != other.ptr_; }
        // dereferenced as an rvalue
        reference operator*() const { return *ptr_; }
        reference operator->() const { return ptr_; }
        // incremented/decremented
        iterator &operator++()
        {
            ++ptr_;
            return *this;
        }
        iterator &operator++(int)
        {
            iterator tmp(*this);
            ++ptr_;
            return tmp;
        }
        iterator &operator--()
        {
            --ptr_;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp(*this);
            --ptr_;
            return tmp;
        }
        // arithmetic operators + and -
        iterator operator+(difference_type n) const { return iterator(ptr_ + n); }
        iterator operator-(difference_type n) const { return iterator(ptr_ - n); }
        // compared with inequality relational operators
        bool operator<(difference_type n) const { return ptr_ < n; }
        bool operator>(difference_type n) const { return ptr_ > n; }
        bool operator<=(difference_type n) const { return ptr_ <= n; }
        bool operator>=(difference_type n) const { return ptr_ >= n; }
        // compound assignment operations += and -=
        iterator &operator-=(difference_type n)
        {
            ptr_ -= n;
            return *this;
        }
        iterator &operator+=(difference_type n)
        {
            ptr_ += n;
            return *this;
        }
        // the offset dereference operator ([])
        value_type &operator[](size_t index) { return ptr_[index]; }

    private:
        pointer ptr_;
    };
}

#endif