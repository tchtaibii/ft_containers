#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../includes/iterator_traits.hpp"

namespace ft
{
	template <class type, class NodePTR>
	class map_iterator
	{
	public:
		typedef type iterator_type;
		typedef typename ft::iterator_traits<iterator_type, std::bidirectional_iterator_tag>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<iterator_type, std::bidirectional_iterator_tag>::value_type value_type;
		typedef typename ft::iterator_traits<iterator_type, std::bidirectional_iterator_tag>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type, std::bidirectional_iterator_tag>::pointer pointer;
		typedef typename ft::iterator_traits<iterator_type, std::bidirectional_iterator_tag>::reference reference;
		map_iterator() : i(NULL), root_(NULL), leaf_(NULL) {}
		template <class a1, class a2>
		map_iterator(const map_iterator<a1, a2> &o) : i(o.base()), root_(&(*o.get_root())), leaf_(o.get_leaf()) {}
		map_iterator(NodePTR p, NodePTR const &r, NodePTR const &l) : i(p), root_(r), leaf_(l) {}
		map_iterator(const NodePTR p) : i(p) {}
		template <class a1, class a2>
		map_iterator &operator=(map_iterator<a1, a2> const &o)
		{
			this->i = o.base();
			this->root_ = &(*o.get_root());
			return *this;
		}
		reference operator*() const { return ((i->val)); }
		map_iterator &operator++()
		{
			if (i == NULL)
			{
				i = root_;
				while (i->left != get_leaf())
					i = i->left;
			}
			i = successor(i);
			return (*this);
		}
		map_iterator operator++(int)
		{

			map_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		map_iterator &operator--()
		{
			NodePTR tmp = get_leaf();
			if (i == tmp)
				i = tmp->parent;
			else
				i = predecessor(i);
			return (*this);
		}
		map_iterator operator--(int)
		{
			map_iterator tmp = *this;
			--(*this);
			return (tmp);
		}
		pointer operator->()
		{
			return (&(operator*()));
		}
		pointer operator->() const
		{
			return (&(operator*()));
		}
		NodePTR base() const
		{
			return this->i;
		}
		NodePTR get_root() const
		{
			return this->root_;
		}
		NodePTR get_leaf() const
		{
			return this->leaf_;
		}
		template <class a1, class a2, class a3, class a4>
		friend bool operator==(const map_iterator<a1, a2> &p1, const map_iterator<a3, a4> &p2)
		{
			return (p1.base() == p2.base() ? true : false);
		}
		template <class a1, class a2, class a3, class a4>
		friend bool operator!=(const map_iterator<a1, a2> &p1, const map_iterator<a3, a4> &p2)
		{
			return (p1.base() != p2.base() ? true : false);
		}

	private:
		NodePTR i;
		NodePTR root_;
		NodePTR leaf_;
		NodePTR successor(NodePTR myNode)
		{
			NodePTR tmp = myNode->right;
			if (tmp != get_leaf())
			{
				while (tmp->left != get_leaf())
					tmp = tmp->left;
				return tmp;
			}
			NodePTR parent = myNode->parent;
			while (parent != NULL && myNode == parent->right)
			{
				myNode = parent;
				parent = parent->parent;
			}
			return (parent);
		}

		NodePTR predecessor(NodePTR myNode)
		{
			NodePTR tmp = myNode->left;
			if (tmp != get_leaf())
			{
				while (tmp->right != get_leaf())
					tmp = tmp->right;
				return tmp;
			}
			NodePTR parent = myNode->parent;
			while (parent != NULL && myNode == parent->left)
			{
				myNode = parent;
				parent = parent->parent;
			}
			return (parent);
		}
	};
}

#endif