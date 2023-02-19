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
	template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
	class red_black_tree
	{
		typedef Key value_type;
		typedef size_t size_type;
		typedef Compare compare_type;
		typedef Node<value_type> Node_;
		typedef Alloc allocator_type;
		typedef typename allocator_type::template rebind<Node_>::other alloc;
	private:
		Node_ *leaf;
		alloc alloc_;
		size_type size_;
		compare_type comp;
		
		void printHelper(Node_ *root, std::string indent, bool last) {
		if (root != leaf) {
		std::cout << indent;
		if (last) {
			std::cout << "R----";
			indent += "   ";
		} else {
			std::cout << "L----";
			indent += "|  ";
		}
		std::string sColor = root->color == RED ? "RED" : "BLACK";
		std::cout << root->val << "(" << sColor << ")" << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
		}
	}
		size_type insert_helper(Node_ *parent, Node_ *node)
		{
			if (comp (node->val, parent->val))
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
			else if (comp(parent->val, node->val))
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
			if (node->parent->parent != leaf)
				if (node->parent->parent->left == node->parent)
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
			if (node->parent->parent != leaf)
				if (node->parent->parent->right == node->parent)
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
			if (node->parent->left == node)
			{
				if (node->parent->parent->left == node->parent)
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
			if (node->parent->right == node)
			{
				if (node->parent->parent != leaf)
					if (node->parent->parent->right == node->parent)
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
		Node_ *minimum(Node_ *node)
		{
			while (node->left != leaf)
				node = node->left;
			return node;
		}
		void leftRotate(Node_ *node)
		{
			Node_ *tmp = node->right;
			if (node->right != leaf)
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
				if (node->parent->left == node)
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
				if (node->parent->right == node)
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
					if (w != leaf && w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w != leaf && w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						if (w->right)
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
			if (node == leaf || !node )
				return ;
			delete_tree (node->left);
			delete_tree (node->right);
			if (node != leaf || !node )
			{
				alloc_.destroy (node);
				alloc_.deallocate (node, 1);
			}
		}

	public:
		Node_ *g_leaf() const {return this->leaf;}
		red_black_tree() {
			leaf = alloc_.allocate(1);
			leaf->color = BLACK;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->side = NOSIDE;
			root = leaf;
			size_ = 0;
		}
		~red_black_tree(){
			clear();
			alloc_.deallocate (leaf, 1);
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
				leaf->parent = root;
				return 1;
			}
			else
			{
				if (!insert_helper(root, node))
				{
					alloc_.destroy(node);
					alloc_.deallocate(node, 1);
					leaf->parent = max();
					return 0;
				}
				if (node->parent->right == node || node->parent->left == node)
					check_color(node);
				leaf->parent = max();
				return 1;
			}
		}

		size_type delete_Node(value_type key)
		{
			Node_ *nodeDelete = search(root, key);
			if (nodeDelete == leaf)
			{
				leaf->parent = max();
				return 0;
			}
			size_--;
			Node_ *tmp = nodeDelete;
			Color originalColor = tmp->color;
			Node_ *x;
			if (nodeDelete->left == leaf)
			{
				if (nodeDelete->parent == root && nodeDelete->parent->left == leaf && nodeDelete->right == leaf )
				{
					x = nodeDelete->parent;
					x->right = leaf;
					alloc_.destroy(nodeDelete);
					alloc_.deallocate(nodeDelete, 1);
					leaf->parent = root;
					// nodeDelete = leaf;
					return 1;
				}
				x = nodeDelete->right;
				transplant(root, nodeDelete, x);
			}
			else if (nodeDelete->right == leaf) {
				x = nodeDelete->left;
				transplant(root, nodeDelete, x);
			}
			else {
				tmp = minimum(nodeDelete->right);
				originalColor = tmp->color;
				x = tmp->right;
				if (tmp->parent == nodeDelete)
					x->parent = tmp;
				else
				{
					transplant(root, tmp, tmp->right);
					tmp->right = nodeDelete->right;
					tmp->right->parent = tmp;
				}
					
				transplant(root, nodeDelete, tmp);
				tmp->left = nodeDelete->left;
				tmp->left->parent = tmp;
				tmp->color = nodeDelete->color;
			}
			if (originalColor == BLACK) {
				fixDelete(root, x);
			}
			if (nodeDelete != leaf)
			{
				alloc_.destroy(nodeDelete);
				alloc_.deallocate(nodeDelete, 1);
				nodeDelete = leaf;
			}
			leaf->parent = max();
			return 1;
		}
		Node_ *g_root() const {return this->root;}
		
		Node_ *search(Node_ *node ,const value_type key) const
		{
			if (node == leaf && node->left == NULL && node->left == NULL)
				return node;
			if (node != leaf && comp(node->val, key) == false && comp(key, node->val) == false)
				return node;
			if (node != leaf && comp(node->val, key))
				return search(node->right ,key);
			return search(node->left ,key);
		}
		Node_ *min() const
		{
			if (root == leaf)
				return leaf;
			if (root->left == leaf)
				return root;
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

		Node_ *max() const
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
		Node_	*lower_bound(const Key &k)
		{
			Node_	*tmp = root;
			Node_	*ret = leaf;

			while (tmp != leaf)
			{
				if (!comp(tmp->val,k) && !comp(k, tmp->val))
				{
					ret = tmp;
					break ;
				}
				if (comp(k, tmp->val))
				{
					ret = tmp;
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			return (ret);
		}
		
		Node_	*lower_bound(const Key &k) const
		{
			Node_	*tmp = root;
			Node_	*ret = leaf;

			while (tmp != leaf)
			{
				if (!comp(tmp->val,k) && !comp(k, tmp->val))
				{
					ret = tmp;
					break ;
				}
				if (comp(k, tmp->val))
				{
					ret = tmp;
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			return (ret);
		}
		Node_	*upper_bound(const Key &k)
		{
			Node_	*tmp = root;
			Node_	*ret = leaf;

			while (tmp != leaf)
			{
				Node_	*tmp = root;
				Node_	*ret = leaf;

				while (tmp != leaf)
				{
					if (comp(k, tmp->val))
					{
						ret = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
			}
			return (ret);
			}
			return (ret);
		}
		Node_	*upper_bound(const Key &k) const
		{
			Node_	*tmp = root;
			Node_	*ret = leaf;

			while (tmp != leaf)
			{
				if (comp(k, tmp->val))
				{
					ret = tmp;
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			return (ret);
		}
		void RBswap(red_black_tree &x)
		{
			// myObj to tmp
			alloc alloc_tmp = alloc_;
			size_type size_tmp = size_;
			compare_type comp_tmp = comp;
			Node_ *root_tmp = root;
			Node_ *leaf_tmp = leaf;
			// x to myObj
			alloc_ = x.alloc_;
			size_ = x.size_;
			comp = x.comp;
			root = x.root;
			leaf = x.leaf;
			// tmp to x
			x.alloc_ = alloc_tmp;
			x.size_ = size_tmp;
			x.comp = comp_tmp;
			x.root = root_tmp;
			x.leaf = leaf_tmp;
			// tmp to NULL
			root_tmp = NULL;
			leaf_tmp = NULL;
		}
		void printTree()
		{
			if (root != leaf)
				printHelper(this->root, "", true);
		}
		Node_ *root;
	};
}
