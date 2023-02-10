#pragma once
#include <iostream>
#include "../includes/utils.hpp"
#include "./iterator.hpp"
#include "./red_black_tree.hpp"
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	private:
		ft::red_black_tree<Key, T, Compare, Alloc>	tree;
		Compare										COM;
		Alloc										al;
		
	public:
		typedef Key 																				key_type;
		typedef T 																					mapped_type;
		typedef ft::pair<const key_type, mapped_type> 												value_type;
		typedef size_t 																				size_type;
		typedef Compare 																			key_compare;
		typedef Alloc 																				allocator_type;
		typedef value_type 																			&reference;
		typedef const 	value_type 																	&const_reference;
		typedef typename std::allocator_traits<allocator_type>::pointer								pointer;
		typedef typename std::allocator_traits<allocator_type>::const_pointer						const_pointer;
		typedef typename std::ptrdiff_t																difference_type;
		typedef ft::map_iterator<value_type *, ft::Node<value_type> *>								iterator;
		typedef ft::map_iterator<const value_type *, ft::Node<value_type> *>						const_iterator;
		// default constructor
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : COM(comp), al(alloc){}
		// range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : COM(comp), al(alloc)
		{
			// should i make iterator 
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}
		// copy constructor
		map(const map &x) : tree(x.tree), COM(x.COM), al(x.al) {
			
			// should i make iterator
			for (iterator it = x.begin(); it != x.end(); it++)
					tree.insert (*it);
			return (*this);
		}
		// deconstructor
		~map(){}
		// copy assignment operator
		map &operator=(const map &x)
		{
			COM = x.COM;
			al = x.al;
			clear();
			// should i make iterator
			for (iterator it = x.begin(); it != x.end(); it++)
					tree.insert (*it);
			return (*this);
		}
		// returns whether the map container is empty (i.e. whether its size is 0).
		bool empty() const {return !size();}
		// Returns the number of elements in the map container.
		size_type size() const { return tree.size();}
		// Returns the maximum number of elements that the map container can hold.
		size_type max_size() const {return (al.max_size());};
		// If k matches the key of an element in the container, the function returns a reference to its mapped value.
		mapped_type &operator[](const key_type &k);
		// insert single element
		pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<iterator, bool>	P_R;
			bool						b;
		
			b = tree.insert(val);
			P_R.first = iterator(tree.search(tree.root, val.first), tree.root);
			P_R.second = b;
			return (P_R);
		}
		// insert element in position
		iterator insert(iterator position, const value_type &val)
		{
			(void) position;
			return (tree.insert(val));
		}
		// insert a range of elements
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			// should i make iterator 
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}
		// erase element from map use position
		void erase(iterator position)
		{
			if (position != end())
				tree.erase(position->first);
		}
		// erase element from map use key
		size_type erase(const key_type &k)
		{
			return tree.delete_Node(k);
		}
		// erase a range of element
		void erase(iterator first, iterator last)
		{
			// should i make iterator 
			while (first != last)
			{
				iterator	temp = first;
				temp++;
				tree.erase(first->first);
				first = temp;
			}
		}

		// swap : Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
		void swap(map &x)
		{

		}
		// clear content. Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		void clear() {tree.clear();}
		// Return key comparison object
		key_compare key_comp() const {return COM;}
		// Return value comparison object
		// value_compare value_comp() const;
		// Get iterator to element
		iterator find(const key_type &k);
		// Get iterator to element const
		const_iterator find(const key_type &k) const;
		// Count elements with a specific key
		size_type count(const key_type &k) const{
			return (!!(tree.search(tree.root, k)));
		}
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
		allocator_type get_allocator() const{return al;}
		iterator	begin ()
		{
			Node<value_type>	*mini = tree.minimum();
			return (iterator (mini, tree.root));
		}
		iterator	begin () const
		{
			Node<value_type>	*mini = tree.minimum();
			return (iterator (mini, tree.root));
		}
		iterator	end ()
		{
			Node<value_type>	*maxi = tree.maximum();
			return (iterator (maxi, tree.root));
		}
		iterator	end () const
		{
			Node<value_type>	*maxi = tree.maximum();
			return (iterator (maxi, tree.root));
		}
	};

}
