#include <iostream>
#include "./includes/red_black.hpp"
#include "./includes/pair.hpp"

int main()
{
    ft::redblack_tree<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > obj;

    obj.insert(ft::make_pair(20, 20));
    obj.insert(ft::make_pair(30, 30));
    obj.insert(ft::make_pair(40, 40));
    obj.insert(ft::make_pair(5, 5));
    obj.insert(ft::make_pair(89, 89));
    obj.insert(ft::make_pair(1, 1));
    obj.insert(ft::make_pair(63, 63));
    obj.insert(ft::make_pair(21, 21));
    obj.insert(ft::make_pair(45, 45));
    obj.insert(ft::make_pair(22, 22));
    obj.insert(ft::make_pair(2, 2));
    obj.insert(ft::make_pair(12, 12));
    obj.insert(ft::make_pair(222, 222));
    obj.insert(ft::make_pair(212, 212));
    obj.insert(ft::make_pair(242, 242));
    obj.insert(ft::make_pair(245, 245));
    obj.insert(ft::make_pair(27, 27));
    obj.insert(ft::make_pair(-1, -1));
    obj.insert(ft::make_pair(10, 10));
	obj.printTree(obj._root, nullptr, false);
	obj.erase(89);
	obj.printTree(obj._root, nullptr, false);
    // obj.insert(40);
    // obj.insert(5);
    // obj.insert(89);
    // obj.insert(1);
    // obj.insert(63);
    // obj.insert(21);
    // obj.insert(45);
    // obj.insert(22);
    // obj.insert(2);
    // obj.insert(12);
    // obj.insert(222);
    // obj.insert(212);
    // obj.insert(242);
    // obj.insert(245);
    // obj.insert(27);
    // obj.insert(-1);
    // obj.insert(10);
    // obj.deleteNode(5);
    // obj.deleteNode(40);
    // debug.print_tree(obj.root, V_VIEW);
    // obj.tempr = obj.search(obj.root, 10);
    // std::cout << obj.tempr->key << std::endl;
    // std::cout << "\033[1;31m" << "hhhah" << "\033[0m";

}