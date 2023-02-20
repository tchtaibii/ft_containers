#pragma once
#include <iostream>

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		typedef	T1	first_type;
		typedef	T2	second_type;

		public:
		first_type first_() const {return this->first;}
		second_type second_() const {return this->second;}
		pair () : first(), second() {}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first_()), second(pr.second_()) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		pair& operator= (const pair& pr)
		{
			this->first = pr.first_();
			this->second = pr.second_();
			return (*this);
		}
		first_type			first;
		second_type			second;
	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		if ((lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second))
			return (true);
		return (false);	
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2> (x, y));
	}
	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <typename T>
    struct remove_cv{
        typedef T type;
    };

    template <typename T>
    struct remove_cv<const T> {
        typedef T type;
    };

    template <typename T>
    struct remove_cv<volatile T> {
        typedef T type;
    };

    template <typename T>
    struct remove_cv<const volatile T> {
        typedef T type;
    };

    template<typename T>
    struct is_integral
    {
        static const bool value = false;
    };
    template<>
    struct is_integral <remove_cv<bool>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<signed char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<short int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<long int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned char>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned short int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned int>::type>
    {
        static const bool value = true; 
    };

    template<>
    struct is_integral <remove_cv<unsigned long int>::type>
    {
        static const bool value = true; 
    };

    template<typename T>
    struct is_input_it
    {
        static const bool value = false;
    };

    template<>
    struct is_input_it<std::input_iterator_tag>
    {
        static const bool value = true;
    };
}