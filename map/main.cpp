#include <iostream>
#include "red_black_tree.hpp"

int main()
{
    ft::red_black_tree<int> obj;

    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);

    std::cout << obj.root->right->right->key << std::endl;

}