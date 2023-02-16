#include <iostream>
#include "../includes/red_black_tree.hpp"
#include "./print_tree.hpp"
#include "./map.hpp"
#include <map>
int main()
{

    // fancy_tree<int> debug;
    ft::map<int, char> m;

    // obj.insert(ft::make_pair(64, 'a'));
    // obj.insert(ft::make_pair(90, 'a'));
    // obj.insert(ft::make_pair(1, 'a'));
    // obj.insert(ft::make_pair(2, 'a'));
    // obj.insert(ft::make_pair(92, 'a'));
    // obj.insert(ft::make_pair(3, 'a'));
    // obj.insert(ft::make_pair(98, 'a'));
    // obj.insert(ft::make_pair(78, 'a'));
    // obj.insert(ft::make_pair(8, 'a'));
    // obj.insert(ft::make_pair(6, 'a'));
    // obj.insert(ft::make_pair(23, 'a'));
    // obj.insert(ft::make_pair(5, 'a'));
    // obj.insert(ft::make_pair(4, 'a'));
    // obj.insert(ft::make_pair(96, 'a'));
    // obj.insert(ft::make_pair(88, 'a'));
    // obj.insert(ft::make_pair(101, 'a'));
    // obj.insert(ft::make_pair(103, 'a'));
    // obj.insert(ft::make_pair(100, 'a'));
    // obj.insert(ft::make_pair(-1, 'a'));
    // // obj.insert(ft::make_pair(-6, 'a'));
    // obj.insert(ft::make_pair(97, 'a'));
    // obj.insert(ft::make_pair(920, 'a'));
    // obj.insert(ft::make_pair(30, 'a'));
    // obj.insert(ft::make_pair(980, 'a'));
    // obj.insert(ft::make_pair(780, 'a'));
    // // std::cout << obj.size() << std::endl;
    // ft::map<int, char>::iterator it = obj.begin();
    // obj.erase(it);
    // it = obj.begin();
    // std::advance(it, 21);
    // obj.erase(it);
    // it = obj.end();
    // it = obj.end();
    // std::advance(it, -3);
    // obj.erase(it);        
    // it = obj.end();
    // std::advance(it, -1);        
    // obj.erase(it);
    // it = obj.begin();
    // std::advance(it, 1);
    // obj.erase(it);
    // std::cout << "it = " << it->first << std::endl;
    // debug.print_tree(obj.tree.root, V_VIEW);
    // std::cout << "****************************************************" << std::endl;
    // for (it = obj.begin(); it != obj.end(); it = obj.begin()) {
    //     std::cout << it->first << std::endl;
    //     debug.print_tree(obj.tree.root, V_VIEW);
    //     if (it->first == 100)
    //     {
    //         obj.erase(it);
    //         std::cout << "my seg point ********" << std::endl;
    //         std::cout << obj.tree.root->val.first << std::endl;
    //     }
    //     else
    //     {
    //         obj.erase(it);
    //         std::cout << "deleted complet " << std::endl;
    //     }

    // }

    strmap::size_type size = m.erase("");
    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    m.insert(NAMESPACE::make_pair("", ""));
    m.insert(NAMESPACE::make_pair("123", "kjhgfdsdffghsfghdfgh"));
    m.insert(NAMESPACE::make_pair("1234", "gfdsadgg"));
    m.insert(NAMESPACE::make_pair("123456789123456789123456789", "49857459898674568464"));
    m.insert(NAMESPACE::make_pair("0", "2345456456456456"));
    m.insert(NAMESPACE::make_pair("", ""));
    m.insert(NAMESPACE::make_pair("", "9459845984598498"));
    m.insert(NAMESPACE::make_pair("000000000000000000000000", "1111111111111111111111111111"));

    size = m.erase("1");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("123");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("123");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("1234");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("123456789123456789123456789");

    PRINT_LINE("Erased?:", size);
    PRINT_ALL(m);

    size = m.erase("000000000000000000000000");

    PRINT_LINE("Erased?:", size);
}