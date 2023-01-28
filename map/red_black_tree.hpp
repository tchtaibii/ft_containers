#pragma once
#include <iostream>
#include "utils.hpp"

namespace ft
{
	enum Color{RED,BLACK}; // red = 0 , black = 1;
	enum Node_side{R,L}; // right = 0 , left = 1;

	template <class T>
	struct Node
	{
		T key;
		size_t size_;
		Node *left, *right, *parent;
		Color color;
		Node_side side;
		Node(T key) : key(key), left(NULL), right(NULL), parent(NULL), color(RED), size_(0) {
		}
	};
	template <class T>
	class red_black_tree
	{
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
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
					return ;
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
					return ;
				}
				else
					return insert_helper(parent->right, node);
			}
		}
		void check_color(Node<value_type> *node)
		{
			if (node == root)
				return ;
			if (node->color == RED && node->parent == RED)
				correctTree(node);
			check_color(node->parent);
		}
		void correctTree(Node<value_type> *node)
		{
			// parent in the left side
			if (node->parent->side == L)
			{
				// AUNT IS BLACK so we gonna do rotation
				if (node->parent->parent->right->side == BLACK || node->parent->parent->right == NULL)
					return rotate(node);
				if (node->parent->parent->right != NULL)
					node->parent->parent->right->color = BLACK;
				node->parent->parent->color = RED;
				node->parent->color = RED;
				return;
			}
			// parent in the right side
			if (node->parent->side == R)
			{
				// AUNT IS BLACK so we gonna do rotation
				if (node->parent->parent->left->side == BLACK || node->parent->parent->left == NULL)
					return rotate(node);
				if (node->parent->parent->left != NULL)
					node->parent->parent->left->color = BLACK;
				node->parent->parent->color = RED;
				node->parent->color = RED;
				return;
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
					return ;
				}
				rightLeftRotate(node->parent->parent);
				node->color = BLACK;
				node->right->color = RED;
				node->left->color = RED;
				return ;
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
					return ;
				}
				leftrightRotate(node->parent->parent);
				node->color = BLACK;
				node->right->color = RED;
				node->left->color = RED;
				return ;
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
			if (node->parent != NULL)
			{
				root = tmp;
				tmp->parent = NULL;
			}
			else {
				tmp->parent = node->parent;
				if (node->side == L)
				{
					tmp->side = L;
					tmp->parent->left = tmp;
				}
				else {
					tmp->side = R;
					tmp->parent->right = tmp;
				}
				tmp->left = node;
				node->side = L;
				node->parent = tmp;
			}
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
			if (node->parent != NULL)
			{
				root = tmp;
				tmp->parent = NULL;
			}
			else {
				tmp->parent = node->parent;
				if (node->side == R)
				{
					tmp->side = R;
					tmp->parent->right = tmp;
				}
				else {
					tmp->side = L;
					tmp->parent->left = tmp;
				}
				tmp->right = node;
				node->side = R;
				node->parent = tmp;
			}
		}
	public:
		Node<value_type> *root;
		red_black_tree() : root(NULL) {}
		void insert(value_type value)
		{
			std::allocator<Node<value_type> > alloc;
			Node<value_type> *node = alloc.allocate(1);
			alloc.construct(node, Node<value_type>(value));
			if (root == NULL) // root case
			{
				root = node;
				root->size_ = 1;
				node->color = BLACK;
			}
			else
				insert_helper(root, node);
		}
	};
}