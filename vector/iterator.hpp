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
        typedef typename std::remove_cv<_Iter>::type value_type;
		typedef _Iter* pointer;
		typedef const _Iter* const_pointer;
		typedef _Iter& reference;
		typedef const _Iter& const_reference;
		typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
        // CONSTRUCTOR
        iterator(pointer pt) : ptr_(pt) {}
        iterator() : ptr_(NULL) {}
        iterator(const iterator &cp) : ptr_(cp.ptr_) {}
        template<class Y>
        iterator &operator=(const iterator<Y> &cp)
        {
            ptr_ = cp.ptr_;
            return *this;
        }
        // dereferenced as an rvalue
        reference operator*() const { return *ptr_;}
        pointer operator->() const { return ptr_; }
        // incremented/decremented
        iterator operator++()
        {
            ++ptr_;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp(*this);
            ++ptr_;
            return tmp;
        }
        iterator operator--()
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
        difference_type operator-(iterator n)
        {
            difference_type i = std::distance(n.ptr_, this->ptr_);
            return i;
        }
        pointer base() const {return ptr_;}
        // compared for equivalence
        template <class T, class T2>
        friend bool operator==(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ == rhs.ptr_; }
        template <class T, class T2>
        friend bool operator!=(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ != rhs.ptr_; }
        // compared with inequality relational operators
        template <class T, class T2>
        friend bool operator<(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ < rhs.ptr_; }
        template <class T, class T2>
        friend bool operator>(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ > rhs.ptr_; }
        template <class T, class T2>
        friend bool operator<=(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ <= rhs.ptr_; }
        template <class T, class T2>
        friend bool operator>=(const iterator<T> &lhs, const iterator<T2> &rhs)  { return lhs.ptr_ >= rhs.ptr_; }
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
        value_type &operator[](size_type index) { return ptr_[index]; }

    private:
        pointer ptr_;
    };
    template <class Iterator>
    iterator<Iterator> operator+(typename iterator<Iterator>::difference_type n, const iterator<Iterator> &x)
    {
        return iterator<Iterator>(x.base() + n);
    }
}

#endif