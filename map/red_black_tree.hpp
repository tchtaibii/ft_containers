#pragma once
#include <iostream>
#include "utils.hpp"

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
		T key;
		size_t size_;
		Node<T> *left, *right, *parent;
		Color color;
		Node_side side;
		Node(T key) : key(key), left(NULL), right(NULL), parent(NULL), color(RED), size_(0), side(NOSIDE)
		{
		}
	};
	template <class T>
	class red_black_tree
	{
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef size_t size_type;
		// typedef typename std::allocator<Node>::template rebind<value_type>::other alloc;
	private:
		void insert_helper(Node<value_type> *parent, Node<value_type> *node)
		{
			if (node->key < parent->key)
			{
				if (parent->left == NULL)
				{
					parent->left = node;
					node->parent = parent;
					node->side = L;
					return;
				}
				else
					return insert_helper(parent->left, node);
			}
			else if (node->key > parent->key)
			{
				if (parent->right == NULL)
				{
					parent->right = node;
					node->parent = parent;
					node->side = R;
					return;

				}
				else
					return insert_helper(parent->right, node);
			}
		}
		void check_color(Node<value_type> *node)
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
			if (node->parent != NULL)
				check_color(node->parent);
		}
		void correctTree(Node<value_type> *node)
		{
			// parent in the left side
			if (node->parent->side == L)
			{
				// AUNT IS BLACK so we gonna do rotation
				if (node->parent->parent->right == NULL || node->parent->parent->right->color == BLACK)
					return rotate(node);
				if (node->parent->parent->right != NULL)
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
				if (node->parent->parent->left == NULL || node->parent->parent->left->color == BLACK)
				{
					return rotate(node);
				}
				if (node->parent->parent->left != NULL)
				{
					node->parent->parent->left->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					return;
				}
			}
		}
		void rotate(Node<value_type> *node)
		{
			if (node->side == L)
			{
				if (node->parent->side == L)
				{
					rightRotate(node->parent->parent);
					node->color = RED;
					node->parent->color = BLACK;
					if (node->parent->right != NULL)
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
					if (node->parent->left != NULL)
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

		void leftRotate(Node<value_type> *node)
		{
			Node<value_type> *tmp = node->right;
			node->right = tmp->left;
			if (node->right != NULL)
			{
				node->right->parent = node;
				node->right->side = R;
			}
			if (node->parent == NULL)
			{
				root = tmp;
				if (root->side == L)
					root->side = NOSIDE;
				tmp->parent = NULL;
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
		void rightRotate(Node<value_type> *node)
		{
			Node<value_type> *tmp = node->left;
			node->left = tmp->right;
			if (node->left != NULL)
			{
				node->left->parent = node;
				node->left->side = L;
			}
			if (node->parent == NULL)
			{
				root = tmp;
				if (root->side == L)
					root->side = NOSIDE;
				tmp->parent = NULL;
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
		void leftrightRotate(Node<value_type> *node)
		{
			leftRotate(node->left);
			rightRotate(node);
		}
		void rightleftRotate(Node<value_type> *node)
		{
			rightRotate(node->right);
			leftRotate(node);
		}
		size_type height()
		{
			if (root == NULL)
				return 0;
			return height(root) - 1;
		}
		size_type height(Node<value_type> *node)
		{
			if (root == NULL)
				return 0;
			size_type leftHeight = height(node->left) + 1;
			size_type rightHeight = height(node->right) + 1;
			if (leftHeight > rightHeight)
				return leftHeight;
			return rightHeight;
		}
		size_type blacknodes(Node<value_type> *node)
		{
			if (root == NULL)
				return 0;
			size_type leftBlackNode = blacknodes(node->left) + 1;
			size_type rightBlackNode = blacknodes(node->right) + 1;
			if (leftBlackNode != rightBlackNode)
			{
				check_color(node);
				correctTree(node);
			}
			if (node->color == BLACK)
				leftBlackNode++;
			return leftBlackNode;
		}

	public:
		Node<value_type> *root;
		Node<value_type> *tempr;
		red_black_tree() : root(NULL) {}
		void insert(value_type value)
		{
			// if (search(root, value) == NULL)
			{
				std::allocator<Node<value_type> > alloc;
				Node<value_type> *node = alloc.allocate(1);
				alloc.construct(node, Node<value_type>(value));
				if (root == NULL) // root case
				{
					root = node;
					root->size_ = 1;
					node->color = BLACK;
					node->parent = NULL;
					node->side = NOSIDE;
					return ;
				}
				else
				{
					insert_helper(root, node);
					if (node->side == R || node->side == L)
						check_color(node);
				}
			}
			
		}
		Node<value_type> *search(Node<value_type> *node,value_type key)
		{
			if (root == NULL)
				return NULL;
			if (node != NULL && node->key == key)
			{
				printf("equal \n");
				return node;
			}
			if (node != NULL && key > node->key)
			{

				if (node->right != NULL)
					search(node->right ,key);
				else
					return NULL;
			}
			else
			{
				if (node->left != NULL)
					search(node->left ,key);
				return NULL;
			}
			return NULL;
		}
		Node<value_type> *successor(Node<value_type> *node)
		{
			if (root == NULL || node->right == NULL)
				return NULL;
			Node<value_type> *tmp = node->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp->parent->left;
		}

		Node<value_type> *predecessor(Node<value_type> *node)
		{
			if (root == NULL || node->left == NULL)
				return NULL;
			Node<value_type> *tmp = node->left;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return tmp->parent->right;
		}
	};
}
