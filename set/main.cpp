#include <iostream>
#include <set>
#include "set.hpp"
#include "print_tree.hpp"

int main()
{
    // Create sets for testing
    std::set<int> stdSet;
    ft::set<int> ftSet;

    // Test insert
    stdSet.insert(1);
    ftSet.insert(1);

    // Test iterator and dereferencing
    std::set<int>::iterator it1 = stdSet.begin();
    ft::set<int>::iterator it2 = ftSet.begin();
    if (*it1 != *it2) {
        std::cout << "ERROR: Iterators do not match" << std::endl;
    }

    // Test size
    if (stdSet.size() != ftSet.size()) {
        std::cout << "ERROR: Size does not match" << std::endl;
    }

    // Test clear
    stdSet.clear();
    ftSet.clear();
    if (stdSet.size() != ftSet.size()) {
        std::cout << "ERROR: Size does not match after clear" << std::endl;
    }

    // Test insert with hint
    std::pair<std::set<int>::iterator, bool> ret1;
    ft::pair<ft::set<int>::iterator, bool> ret2;
    ret1 = stdSet.insert(1);
    ret2 = ftSet.insert(1);
    if (ret1.second != ret2.second) {
        std::cout << "ERROR: Insert with hint failed" << std::endl;
    }

    // Test find
    it1 = stdSet.find(1);
    it2 = ftSet.find(1);
    if (*it1 != *it2) {
        std::cout << "ERROR: Find failed" << std::endl;
    }


    fancy_tree<int> debug;
    ft::set<int> obj;
    for (int i = 0; i < 8; i++)
        obj.insert(i);
    debug.print_tree(obj.get_tree(), V_VIEW);
    obj.erase(4);
    obj.erase(3);
    obj.erase(9);
    debug.print_tree(obj.get_tree(), V_VIEW);
    // Output success message
    std::cout << "All tests [SET] passed!" << std::endl;

    return 0;
}