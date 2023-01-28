#include <iostream>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    Node *left, *right, *parent;
    Color color;

    Node(int key) : key(key), left(NULL), right(NULL), parent(NULL), color(RED) {}
};

class RedBlackTree
{
private:
    Node *root;

    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixViolation(Node *&);

public:
    RedBlackTree();
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

RedBlackTree::RedBlackTree() : root(NULL) {}

void RedBlackTree::rotateLeft(Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::fixViolation(Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left)
        {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->right)
                {
                    rotateLeft(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateRight(grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        else
        {
            Node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rotateRight(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::insert(const int &key)
{
    Node *pt = new Node(key);
    root = insertHelper(root, pt);

    fixViolation(pt);
}

Node *RedBlackTree::insertHelper(Node *root, Node *pt)
{
    if (root == NULL)
        return pt;
    if (pt->key < root->key)
    {
        root->left = insertHelper(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->key > root->key)
    {
        root->right = insertHelper(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

void RedBlackTree::inorder()
{
    inorderHelper(root);
}

void RedBlackTree::inorderHelper(Node *root)
{
    if (root == NULL)
        return;
    inorderHelper(root->left);
    std::cout << root->key << " ";
    inorderHelper(root->right);
}

void RedBlackTree::levelOrder()
{
    levelOrderHelper(root);
}

void RedBlackTree::levelOrderHelper(Node *root)
{
    if (root == NULL)
        return;
    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        std::cout << temp->key << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);

        q.pop();
    }
}
