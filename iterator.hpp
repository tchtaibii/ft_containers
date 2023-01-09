#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
    template <typename T>
    class booliterator
    {
    public:
        typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
        typedef std::random_access_iterator_tag iterator_category;

        // CONSTRUCTOR
        iterator() : ptr_(nullptr) {}
        iterator(const iterator &cp) : ptr_(cp.ptr_) {}
        iterator& operator=(const iterator &cp) {ptr_ = cp.ptr_;}
        // compared for equivalence
        bool operator==(const iterator& other) const {return ptr_ == other.ptr_;}
        bool operator!=(const iterator& other) const {return ptr_ != other.ptr_;}
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
        iterator operator+(difference_type n) const { return iterator(ptr_ + n);}
        iterator operator-(difference_type n) const { return iterator(ptr_ - n);}
        // compared with inequality relational operators 
        bool operator<(difference_type n) const { return if (ptr_ < n);}
        bool operator>(difference_type n) const { return if (ptr_ > n);}
        bool operator<=(difference_type n) const { return if (ptr_ <= n);}
        bool operator>=(difference_type n) const { return if (ptr_ >= n);}
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












        // iterator operator-(difference_type n) const { return iterator(ptr_ - n); }

        // bool operator<(const iterator &other) const { return ptr_ < other.ptr_; }
        // bool operator>(const iterator &other) const { return ptr_ > other.ptr_; }
        // bool operator<=(const iterator &other) const { return ptr_ <= other.ptr_; }
        // bool operator>=(const iterator &other) const { return ptr_ >= other.ptr_; }

    private:
        pointer ptr_;
    };
}

#endif