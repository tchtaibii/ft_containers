#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class Iterator>
	struct iterator_traits<Iterator *>
	{
		typedef Iterator value_type;
		typedef std::ptrdiff_t difference_type;
		typedef Iterator *pointer;
		typedef Iterator &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	struct iterator_traits<const Iterator *>
	{
		typedef Iterator value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const Iterator *pointer;
		typedef const Iterator &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
} // namespace ft
#endif