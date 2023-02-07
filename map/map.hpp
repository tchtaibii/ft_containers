#pragma once
#include <iostream>
#include "utils.hpp"
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>> >
	class map
	{
	private:
		ft::tree *tree;
		
	public:
		typedef key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef size_t size_type;
		typedef compare key_compare;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef std::allocator_traits<alloc>::pointer pointer;
		typedef std::allocator_traits<alloc>::const_pointer const_pointer;
		typedef typename std::ptrdiff_t difference_type;
		// default constructor
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			
		}
		// range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		// copy constructor
		map(const map &x);
		// deconstructor
		~map();
		// copy assignment operator
		map &operator=(const map &x);
		// returns whether the map container is empty (i.e. whether its size is 0).
		bool empty() const;
		// Returns the number of elements in the map container.
		size_type size() const;
		// Returns the maximum number of elements that the map container can hold.
		size_type max_size() const;
		// If k matches the key of an element in the container, the function returns a reference to its mapped value.
		mapped_type &operator[](const key_type &k);
		// insert single element
		pair<iterator, bool> insert(const value_type &val);
		// insert element in position
		iterator insert(iterator position, const value_type &val);
		// insert a range of elements
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);
		// erase element from map use position
		void erase(iterator position);
		// erase element from map use key
		size_type erase(const key_type &k);
		// erase a range of element
		void erase(iterator first, iterator last);
		// swap : Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
		void swap(map &x);
		// clear content. Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		void clear();
		// Return key comparison object
		key_compare key_comp() const;
		// Return value comparison object
		value_compare value_comp() const;
		// Get iterator to element
		iterator find(const key_type &k);
		// Get iterator to element const
		const_iterator find(const key_type &k) const;
		// Count elements with a specific key
		size_type count(const key_type &k) const;
		// Return iterator to lower bound
		iterator lower_bound(const key_type &k);
		// Return iterator to lower bound const
		const_iterator lower_bound(const key_type &k) const;
		// Return iterator to upper bound
		iterator upper_bound(const key_type &k);
		// Return iterator to upper bound const
		const_iterator upper_bound(const key_type &k) const;
		// Get range of equal elements
		pair<iterator, iterator> equal_range(const key_type &k);
		// Get range of equal elements const
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
		// get allocator
		allocator_type get_allocator() const;
	};

}
