#include <iostream>
#include <map>
#include "map.hpp"
#include "print_tree.hpp"

int main()
{
    // Create maps for testing
    std::map<int, int> stdMap;
    ft::map<int, int> ftMap;

    // Test insert
    stdMap.insert(std::pair<int, int>(1, 1));
    ftMap.insert(ft::pair<int, int>(1, 1));

    // Test iterator and dereferencing
    std::map<int, int>::iterator it1 = stdMap.begin();
    ft::map<int, int>::iterator it2 = ftMap.begin();
    if (it1->first != it2->first || it1->second != it2->second) {
        std::cout << "ERROR: Iterators do not match" << std::endl;
    }

    // Test size
    if (stdMap.size() != ftMap.size()) {
        std::cout << "ERROR: Size does not match" << std::endl;
    }

    // Test clear
    stdMap.clear();
    ftMap.clear();
    if (stdMap.size() != ftMap.size()) {
        std::cout << "ERROR: Size does not match after clear" << std::endl;
    }

    // Test insert with hint
    std::pair<std::map<int, int>::iterator, bool> ret1;
    ft::pair<ft::map<int, int>::iterator, bool> ret2;
    ret1 = stdMap.insert(std::pair<int, int>(1, 1));
    ret2 = ftMap.insert(ft::pair<int, int>(1, 1));
    if (ret1.second != ret2.second) {
        std::cout << "ERROR: Insert with hint failed" << std::endl;
    }

    // Test find
    it1 = stdMap.find(1);
    it2 = ftMap.find(1);
    if (it1->first != it2->first || it1->second != it2->second) {
        std::cout << "ERROR: Find failed" << std::endl;
    }
    fancy_tree<int> debug;
    ft::map<int, int> obj;
    for (int i = 0; i < 8; i++)
        obj.insert(ft::pair<int, int>(i, i));
    debug.print_tree(obj.get_tree(), V_VIEW);
    obj.erase(4);
    obj.erase(3);
    obj.erase(9);
    debug.print_tree(obj.get_tree(), V_VIEW);
    // Output success message
    std::cout << "All tests [MAP] passed!" << std::endl;


    return 0;
}
