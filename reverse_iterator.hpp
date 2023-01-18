#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft
{
    template <typename _Iter>
    class reverse_iterator
    {
    private:
        iterator current;

    public:
        iterator < typename iterator_traits<Iterator>::iterator_category;
        typename iterator_traits<Iterator>::value_type;
        typename iterator_traits<Iterator>::difference_type;
        typename iterator_traits<Iterator>::pointer;
        typename iterator_traits<Iterator>::reference> ;
        typedef iterator iterator_type;   
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::pointer pointer;

        reverse_iterator(): current(NULL) {};
        explicit reverse_iterator(iterator x) : current(x);
        template <class U>
        reverse_iterator(const reverse_iterator<U> &u) : current(u.current);
        Iterator base() const {return this->current}; // explicit
        reference operator*() const {
            Iterator tmp = this->current;
            return *--tmp;
        };
        pointer operator->() const {return &(operator*());}
        reverse_iterator &operator++(){
            --current;
            return *this;
        };
        reverse_iterator operator++(int){
            reverse_iterator tmp = *this;
            --current;
            return tmp;
        }
        reverse_iterator &operator--(){
            ++ptr;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++current;
            return tmp;
        }
        reverse_iterator operator+(difference_type n) const {
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
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current == y.current;
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current > y.current;
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current != y.current;
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current < y.current;
    }
    template <class Iterator>
    bool operator>=( const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current <= y.current
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return x.current >= y.current;
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
    {
        return y.current - x.current;
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator> &x)
    {
        return reverse_iterator<Iterator> (x.current - n)
    }
}

#endif