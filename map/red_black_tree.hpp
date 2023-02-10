#pragma once
#include <iostream>
#include "../includes/utils.hpp"

namespace ft
{
	enum Color
	{
		RED,
		BLACK,
		NOCOLOR
	}; // red = 0 , black = 1;
	enum Node_side
	{
		R,
		L,
		NOSIDE
	}; // right = 0 , left = 1;

	template <class T>
	struct Node
	{
		T val;
		Node<T> *left, *right, *parent;
		Color color;
		Node_side side;
		Node(T value) : val(value), left(NULL), right(NULL), parent(NULL), color(RED), side(NOSIDE)
		{
		}
	};
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class red_black_tree
	{
		typedef Key key_type;
		typedef T mapped_type;
		typedef size_t size_type;
		typedef Compare compare_type;
		typedef ft::pair<const key_type, mapped_type>  value_type;
		typedef Node<value_type> Node_;
		typedef Alloc allocator_type;
		typedef typename allocator_type::template rebind<Node_>::other alloc;
	private:
		Node_ *leaf;
		alloc alloc_;
		size_type size_;
		compare_type comp;
		
		size_type insert_helper(Node_ *parent, Node_ *node)
		{
			if (node->val.first_() < parent->val.first_())
			{
				if (parent->left == leaf)
				{
					parent->left = node;
					node->parent = parent;
					node->side = L;
					size_++;
					return 1;
				}
				else
					return insert_helper(parent->left, node);
			}
			else if (node->val.first_() > parent->val.first_())
			{
				if (parent->right == leaf)
				{
					parent->right = node;
					node->parent = parent;
					node->side = R;
					size_++;
					return 1;

				}
				else
					return insert_helper(parent->right, node);
			}
			return 0;
		}
		void check_color(Node_ *node)
		{
			if (node == root)
			{
				node->color = BLACK;
				node->side = NOSIDE;
				return;
			}
			if (node->color == RED && node->parent->color == RED)
			{
				correctTree(node);
			}
			if (node->parent != leaf)
				check_color(node->parent);
		}
		void correctTree(Node_ *node)
		{
			// parent in the left side
			if (node->parent->side == L)
			{
				// AUNT IS BLACK so we gonna do rotation
				if (node->parent->parent->right == leaf || node->parent->parent->right->color == BLACK)
					return rotate(node);
				if (node->parent->parent->right != leaf)
				{
					node->parent->parent->right->color = BLACK;
					node->parent->parent->color = RED;
					node->parent->color = BLACK;
					return;
				}
			}
			// parent in the right side
			if (node->parent->side == R)
			{
				// AUNT IS BLACK so we gonna do rotation
				if (node->parent->parent->left == leaf || node->parent->parent->left->color == BLACK)
				{
					return rotate(node);
				}
				if (node->parent->parent->left != leaf)
				{
					node->parent->parent->left->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					return;
				}
			}
		}
		void rotate(Node_ *node)
		{
			if (node->side == L)
			{
				if (node->parent->side == L)
				{
					rightRotate(node->parent->parent);
					node->color = RED;
					node->parent->color = BLACK;
					if (node->parent->right != leaf)
						node->parent->right->color = RED;
					return;
				}
				rightleftRotate(node->parent->parent);
				node->color = BLACK;
				node->right->color = RED;
				node->left->color = RED;
				return;
			}
			if (node->side == R)
			{
				if (node->parent->side == R)
				{
					leftRotate(node->parent->parent);
					node->color = RED;
					node->parent->color = BLACK;
					if (node->parent->left != leaf)
						node->parent->left->color = RED;
					return;
				}
				leftrightRotate(node->parent->parent);
				node->color = BLACK;
				node->right->color = RED;
				node->left->color = RED;
				return;
			}
		}

		void leftRotate(Node_ *node)
		{
			Node_ *tmp = node->right;
			node->right = tmp->left;
			if (node->right != leaf)
			{
				node->right->parent = node;
				node->right->side = R;
			}
			if (node->parent == leaf)
			{
				root = tmp;
				if (root->side == L)
					root->side = NOSIDE;
				tmp->parent = leaf;
			}
			else
			{
				tmp->parent = node->parent;
				if (node->side == L)
				{
					tmp->side = L;
					tmp->parent->left = tmp;
				}
				else
				{
					tmp->side = R;
					tmp->parent->right = tmp;
				}
			}
			tmp->left = node;
			node->side = L;
			node->parent = tmp;
		}
		void rightRotate(Node_ *node)
		{
			Node_ *tmp = node->left;
			node->left = tmp->right;
			if (node->left != leaf)
			{
				node->left->parent = node;
				node->left->side = L;
			}
			if (node->parent == leaf)
			{
				root = tmp;
				if (root->side == L)
					root->side = NOSIDE;
				tmp->parent = leaf;
			}
			else
			{
				tmp->parent = node->parent;
				if (node->side == R)
				{
					tmp->side = R;
					tmp->parent->right = tmp;
				}
				else
				{
					tmp->side = L;
					tmp->parent->left = tmp;
				}
			}
			tmp->right = node;
			node->side = R;
			node->parent = tmp;
		}
		void leftrightRotate(Node_ *node)
		{
			leftRotate(node->left);
			rightRotate(node);
		}
		void rightleftRotate(Node_ *node)
		{
			rightRotate(node->right);
			leftRotate(node);
		}
		size_type height()
		{
			if (root == leaf)
				return 0;
			return height(root) - 1;
		}
		size_type height(Node_ *node)
		{
			if (root == leaf)
				return 0;
			size_type leftHeight = height(node->left) + 1;
			size_type rightHeight = height(node->right) + 1;
			if (leftHeight > rightHeight)
				return leftHeight;
			return rightHeight;
		}
		void fixDelete(Node_ *root, Node_ *x)
		{
			while (x != root && x->color == BLACK)
			{
				if (x->parent->left == x) {
					Node_ *w = x->parent->right;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						leftRotate(x->parent);
						x = root;
					}
				} else {
					Node_ *w = x->parent->left;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->left != leaf && w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							leftRotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						if (w->left != leaf)
							w->left->color = BLACK;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}
		void transplant(Node_ *&root, Node_ *u, Node_ *v)
		{
			if (u->parent == leaf) {
				root = v;
			} else if (u == u->parent->left) {
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}
			v->parent = u->parent;
		}
		void	delete_tree(Node_ *node)
		{
			if (node == leaf)
				return ;
			delete_tree (node->left);
			delete_tree (node->right);
			alloc_.destroy (node);
			alloc_.deallocate (node, 1);
		}

	public:
		Node_ *root;
		red_black_tree() {
			leaf = alloc_.allocate(1);
			leaf->color = BLACK;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->side = NOSIDE;
			root = leaf;

		}
		void clear()
		{
			delete_tree(root);
			size_ = 0;
			root = leaf;
		}
		size_type insert(value_type val_)
		{
			Node_ *node = alloc_.allocate(1);
			alloc_.construct(node, Node_(val_));
			node->left = leaf;
			node->right = leaf;
			if (root == leaf) // root case
			{
				node->color = BLACK;
				node->parent = leaf;
				node->side = NOSIDE;
				root = node;
				size_ = 1;
				return 1;
			}
			else
			{
				if (!insert_helper(root, node))
					return 0;
				if (node->side == R || node->side == L)
					check_color(node);
				size_++;
				return 1;
			}
		}

		size_type delete_Node(key_type key)
		{
			Node_ *z = search(root, key);
			if (z == leaf) return 0;
			size_--;
			Node_ *y = z;
			Color originalColor = y->color;
			Node_ *x;
			if (z->left == leaf)
			{
				x = z->right;
				transplant(root, z, z->right);	
			}
			else if (z->right == leaf) {
				x = z->left;
				transplant(root, z, z->left);
			}
			else {
				y = successor(z);
				originalColor = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					transplant(root, y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(root, z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (originalColor == BLACK) {
				fixDelete(root, x);
			}
			return 1;
		}
		
		Node_ *search(Node_ *node,key_type key)
		{
			if (node == leaf)
				return leaf;
			if (node != leaf && node->val.first_() == key)
				return node;
			if (node != leaf && key > node->val.first_())
				return search(node->right ,key);
			return search(node->left ,key);
		}
		Node_ *min()
		{
			if (root == leaf)
				return leaf;
			Node_ *tmp = root;
			while (tmp->left != leaf)
				tmp = tmp->left;
			return tmp->parent->left;
		}
		Node_ *successor(Node_ *node)
		{
			if (root == leaf || node->right == leaf)
				return leaf;
			Node_ *tmp = node->right;
			while (tmp->left != leaf)
				tmp = tmp->left;
			return tmp->parent->left;
		}

		Node_ *max()
		{
			if (root == leaf)
				return leaf;
			Node_ *tmp = root;
			while (tmp->right != leaf)
				tmp = tmp->right;
			return tmp->parent->right;
		}
		Node_ *predecessor(Node_ *node)
		{
			if (root == leaf || node->left == leaf)
				return leaf;
			Node_ *tmp = node->left;
			while (tmp->right != leaf)
				tmp = tmp->right;
			return tmp->parent->right;
		}
		size_type size() const {return size_;}
		
	};
}
