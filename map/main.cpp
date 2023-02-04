#include <iostream>
#include "red_black_tree.hpp"
#include "./fancy_tree.hpp"

int main()
{
    ft::red_black_tree<int> obj;

    fancy_tree<int> debug;


    // obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(5);
    obj.insert(89);
    obj.insert(1);
    obj.insert(63);
    obj.insert(21);
    obj.insert(45);
    obj.insert(22);
    obj.insert(2);
    obj.insert(12);
    obj.insert(222);
    obj.insert(212);
    obj.insert(242);
    obj.insert(245);
    obj.insert(27);
    // obj.insert(0);
    // obj.insert(10);
    // debug.print_tree(obj.root, V_VIEW);
    // obj.deleteNode(5);
    debug.print_tree(obj.root, V_VIEW);
    // obj.deleteNode(40);
    obj.deleteNode(89);
    debug.print_tree(obj.root, V_VIEW);
    // obj.tempr = obj.search(obj.root, 10);
    // std::cout << obj.tempr->key << std::endl;
    // std::cout << "\033[1;31m" << "hhhah" << "\033[0m";

}