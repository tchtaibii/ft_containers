#pragma once
#include <iostream>
#include <algorithm>
#include "../includes/utils.hpp"
#include "./iterator.hpp"
#include "../includes/red_black_tree.hpp"
#include "./includes/reverse_iterator.hpp"
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class set
	{
	private:
		Compare										COM;
		Alloc										al;
		ft::red_black_tree<Key, T, Compare, Alloc>	tree;
		
	public:
		typedef Key 																				key_type;
		typedef T 																					setped_type;
		typedef ft::pair<const key_type, setped_type> 												value_type;
		typedef size_t 																				size_type;
		typedef Compare 																			key_compare;
		typedef Alloc 																				allocator_type;
		typedef value_type 																			&reference;
		typedef const	value_type 																	&const_reference;
		typedef typename std::allocator_traits<allocator_type>::pointer								pointer;
		typedef typename std::allocator_traits<allocator_type>::const_pointer						const_pointer;
		typedef typename std::ptrdiff_t																difference_type;
		typedef ft::set_iterator<value_type *, ft::Node<value_type> *>								iterator;
		typedef ft::set_iterator<const value_type *, ft::Node<value_type> *>						const_iterator;
		typedef typename ft::reverse_iterator<iterator>												reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;
		typedef class value_compare : std::binary_function<value_type, value_type, bool>{   
			friend class set;
			protected:
				key_compare compa;
			public:
				value_compare (key_compare c) : compa(c) {}
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {return compa(x.first, y.first);}
		}																							value_compare;
		// default constructor
		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : COM(comp), al(alloc){}
		// range constructor
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : COM(comp), al(alloc)
		{
			// should i make iterator 
			while (first != last)
			{
				this->insert(*first);
				first++;
			}
		}
		// copy constructor
		set(const set &x) : COM(x.COM), al(x.al) {
			// should i make iterator
			for (iterator it = x.begin(); it != x.end(); it++)
					tree.insert (*it);
		}
		// deconstructor
		~set(){
		}
		// copy assignment operator
		set &operator=(const set &x)
		{
			COM = x.COM;
			al = x.al;
			clear();
			// should i make iterator
			for (iterator it = x.begin(); it != x.end(); it++)
					tree.insert (*it);
			return (*this);
		}
		// returns whether the set container is empty (i.e. whether its size is 0).
		bool empty() const {
			return !size();
		}
		// Returns the number of elements in the set container.
		size_type size() const { return tree.size();}
		// Returns the maximum number of elements that the set container can hold.
		size_type max_size() const {return (al.max_size());};

		// insert single element
		pair<iterator, bool> insert(const value_type &val)
		{
			ft::pair<iterator, bool>	P_R;
			bool						b;

			b = tree.insert(val);
			P_R.first = iterator(tree.search(tree.g_root(), val.first), tree.g_root(), tree.g_leaf());
			P_R.second = b;
			return (P_R);
		}
		// insert element in position
		iterator insert(iterator position, const value_type &val)
		{
			(void) position;
			ft::pair<iterator, bool> pr = this->insert(val);
			return (pr.first_());
		}
		// insert a range of elements
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			// should i make iterator 
			while (first != last)
			{
				this->insert(*first);
				first++;
			}
		}
		// erase element from set use position
		void erase(iterator position)
		{
			if (position != end())
			{
				// std::cout << position->first << std::endl;
				tree.delete_Node(position->first);
			}
		}
		// erase element from set use key
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
				this->erase(first->first);
				first = temp;
			}
		}
		// swap : Exchanges the content of the container by the content of x, which is another set of the same type. Sizes may differ.
		void swap(set &x)
		{
			std::swap(COM, x.COM);
			std::swap(al, x.al);
			this->tree.RBswap(x.tree);
		}
		// Returns a reference to the setped value of the element identified with key k.
		setped_type& at (const key_type& k)
		{
			iterator	it = find(k);
			if (it == end())
				throw std::out_of_range("Not found");
			return (it->second);
		}
		const setped_type& at (const key_type& k) const
		{
			iterator	it = iterator (find(k));
			if (it == end())
				throw std::out_of_range("Not found");
			return (it->second);
		}
		// clear content. Removes all elements from the set container (which are destroyed), leaving the container with a size of 0.
		void clear() {tree.clear();}
		// Return key comparison object
		key_compare key_comp() const {return COM;}
		// Return value comparison object
		value_compare value_comp() const {return (value_compare(key_comp()));}
		// Get iterator to element
		iterator find(const key_type &k)
		{
			return iterator(tree.search(tree.g_root(), k), tree.g_root(), tree.g_leaf());
		}
		// Get iterator to element const
		const_iterator find(const key_type &k) const
		{
			return iterator(tree.search(tree.g_root(), k), tree.g_root(), tree.g_leaf());
		}
		// Count elements with a specific key
		size_type count(const key_type &k) const{
			if (tree.search(tree.g_root(), k) != tree.g_leaf())
				return 1;
			return  0;
		}
		// Return iterator to lower bound
		iterator lower_bound (const key_type& k)
		{
			return (iterator(tree.lower_bound(k), tree.g_root(), tree.g_leaf()));
		}
		// Return iterator to lower bound const
		const_iterator lower_bound(const key_type &k) const
		{
			return (iterator(tree.lower_bound(k), tree.g_root(), tree.g_leaf()));
		}
		// Return iterator to upper bound
		iterator upper_bound(const key_type &k)
		{
			return (iterator(tree.upper_bound(k), tree.g_root(), tree.g_leaf()));
		}
		// Return iterator to upper bound const
		const_iterator upper_bound(const key_type &k) const
		{
			return (iterator(tree.upper_bound(k), tree.g_root(), tree.g_leaf()));
		}
		// Get range of equal elements
		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		// Get range of equal elements const
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		// get allocator
		allocator_type get_allocator() const{return al;}
		iterator	begin ()
		{
			Node<value_type>	*mini = tree.min();
			return (iterator (mini, tree.g_root(), tree.g_leaf()));
		}
		iterator	begin () const
		{
			Node<value_type>	*mini = tree.min();
			return (iterator (mini, tree.g_root(), tree.g_leaf()));
		}
		iterator	end ()
		{
			// Node<value_type>	*maxi = tree.max();
			return (iterator (tree.g_leaf(), tree.g_root(), tree.g_leaf()));
		}
		iterator	end () const
		{
			// Node<value_type>	*maxi = tree.max();
			return (iterator (tree.g_leaf(), tree.g_root(), tree.g_leaf()));
		}
		reverse_iterator	rbegin ()
		{
			return  reverse_iterator (this->end());
		}
		reverse_iterator	rend ()
		{
			return reverse_iterator(this->begin());
		}
		reverse_iterator	rbegin () const
		{
			return reverse_iterator (this->end());
		}
		reverse_iterator	rend () const
		{
			return reverse_iterator(this->begin());
		}
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator < (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs > lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator > (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		for (typename set<Key, T, Compare, Alloc>::iterator it = lhs.begin(), it2 = rhs.begin(); it != lhs.end() && it2 != rhs.end(); it++, it2++)
		{
			if (*it > *it2)
				return (1);
			if (*it != *it2)
				return (0);
		}
		return (lhs.size() > rhs.size());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator <= (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator >= (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator == (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (typename set<Key, T, Compare, Alloc>::iterator it = lhs.begin(), it2 = rhs.begin(); it != lhs.end(); it++, it2++)
		{
			if (*it != *it2)
				return (0);
		}
		return (1);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator != (const set<Key, T, Compare, Alloc>& lhs, const set<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void swap (set<Key, T, Compare, Alloc>& a, set<Key, T, Compare, Alloc>& b)
	{
		a.swap(b);
	}
}
