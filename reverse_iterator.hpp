#ifndef ITERATOR_REVERSE_HPP
#define ITERATOR_REVERSE_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft
{
    template <typename _Iter>
    class reverse_iterator
    {
    public:
        typedef _Iter iterator;
        typedef typename iterator_traits<iterator>::difference_type difference_type;
        typedef typename iterator_traits<iterator>::reference reference;
        typedef typename iterator_traits<iterator>::pointer pointer;
        typedef typename iterator_traits<iterator>::iterator_category iterator_category;

        reverse_iterator() : current(NULL){};
        explicit reverse_iterator(iterator x) : current(x) {}
        template <class T>
        reverse_iterator(const reverse_iterator<T> &u) : current(u.current) {}
        iterator base() const { return this->current; } // explicit
        reference operator*() const
        {
            return *(current-1);
        }
        // template <class T>
        // reverse_iterator &operator=(const reverse_iterator<T> &other)
        // {
        //     this->current = other.current;
        //     return *this;
        // }
        pointer operator->() const { return &(operator*()); }
        reverse_iterator &operator++()
        {
            --current;
            return *this;
        };
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --current;
            return tmp;
        }
        reverse_iterator &operator--()
        {
            ++current;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++current;
            return tmp;
        }
        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(current - n);
        }
        reverse_iterator &operator+=(difference_type n)
        {
            current -= n;
            return *this;
        }
        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator(current + n);
        }
        reverse_iterator &operator-=(difference_type n)
        {
            current += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return current[-n - 1];
        }
        iterator get_current() const {return current;}

    private:
        iterator current;
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() == y.get_current();
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() > y.get_current();
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() != y.get_current();
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() < y.get_current();
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() <= y.get_current();
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.get_current() >= y.get_current();
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return y.get_current() - x.get_current();
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x)
    {
        return reverse_iterator<Iterator>(x.get_current() - n);
    }

}

#endif