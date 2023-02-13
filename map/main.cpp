#include <iostream>
#include "./red_black_tree.hpp"
#include "./fancy_tree.hpp"
#include "./map.hpp"
#include <map>
int main()
{

    fancy_tree<int> debug;
    ft::map<int, char> obj;

    obj.insert(ft::make_pair(64, 'a'));
    obj.insert(ft::make_pair(36, 'a'));
    obj.insert(ft::make_pair(01, 'a'));
    obj.insert(ft::make_pair(06, 'a'));
    obj.insert(ft::make_pair(80, 'a'));
    obj.insert(ft::make_pair(81, 'a'));
    obj.insert(ft::make_pair(11, 'a'));
    ft::map<int, char>::iterator it = obj.end();
    // std::advance(it, -3);
    // obj.erase(it);
    // it = obj.end();
    // std::advance(it, -1);
    // obj.erase(it);
    it = obj.begin();
    std::advance(it, 1);
    std::cout << it->first << std::endl;
    obj.erase(it);

    // std::cout << obj.size() << std::endl;
    // std::cout << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // std::cout << obj.end()->first_() <<  std::endl;

    

    // ft::red_black_tree<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > > obj;;


    // obj.insert(ft::make_pair(20, 20));
    // obj.insert(ft::make_pair(30, 30));
    // obj.insert(ft::make_pair(40, 40));
    // obj.insert(ft::make_pair(5, 5));
    // obj.insert(ft::make_pair(89, 89));
    // obj.insert(ft::make_pair(1, 1));
    // obj.insert(ft::make_pair(63, 63));
    // obj.insert(ft::make_pair(21, 21));
    // obj.insert(ft::make_pair(45, 45));
    // obj.insert(ft::make_pair(22, 22));
    // obj.insert(ft::make_pair(2, 2));
    // obj.insert(ft::make_pair(12, 12));
    // obj.insert(ft::make_pair(222, 222));
    // obj.insert(ft::make_pair(212, 212));
    // obj.insert(ft::make_pair(242, 242));
    // obj.insert(ft::make_pair(245, 245));
    // obj.insert(ft::make_pair(27, 27));
    // obj.insert(ft::make_pair(-1, -1));
    // obj.insert(ft::make_pair(10, 10));
    // // debug.print_tree(obj.root, V_VIEW);
    
    // obj.delete_Node(obj.root, 89);
    // obj.delete_Node(obj.root, 30);
    // // obj.erase(89);
    // debug.print_tree(obj.root, V_VIEW);
    // obj.delete_Node(obj.root, 45);
    // debug.print_tree(obj.tree.root, V_VIEW);
    // std::cout << "\n" << "size = " << obj.size() << std::endl;
    // obj.deleteNode(40);
    std::cout <<  std::endl;
    debug.print_tree(obj.tree.root, V_VIEW);
    // obj.tempr = obj.search(obj.root, 10);
    // std::cout << obj.tempr->key << std::endl;
    std::cout <<  std::endl;
    // std::cout << "\033[1;31m" << "hhhah" << "\033[0m";
}