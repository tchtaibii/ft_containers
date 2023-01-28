#pragma once
#include <iostream>
#include "utils.hpp"

namespace ft
{
	enum Color
	{
		RED,
		BLACK
	}; // red = 0 , black = 1;

	template <typename T>
	struct Node
	{
		T key;
		Node *left, *right, *parent;
		Color color;
		Node(T key) : key(key), left(NULL), right(NULL), parent(NULL), color(RED) {}
	};
	template <class T>
	class red_black_tree
	{
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

	private:
		Node<value_type> *insert_helper(Node<value_type> *root, Node<value_type> *node)
		{
			if (root == NULL)
			{
				node->color = BLACK;
				return node;
			}

			if (node->key < root->key)
			{
				root->left = insert_helper(root->left, node);
				root->left->parent = root;
			}
			else if (node->key > root->key)
			{
				root->right = insert_helper(root->right, node);
				root->right->parent = root;
			}
			return root;
		}

	public:
		Node<value_type> *root;
		red_black_tree() : root(NULL) {}
		void insert(value_type value)
		{
			std::allocator<Node<value_type> > alloc;
			Node<value_type> *node = alloc.allocate(1);
			alloc.construct(node, Node<value_type>(value));
			root = insert_helper(root, node);
		}
	};
}
