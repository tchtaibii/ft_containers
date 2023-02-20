#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
    // Create vectors for testing
    std::vector<int> stdVec;
    ft::vector<int> ftVec;

    // Test push_back
    stdVec.push_back(1);
    ftVec.push_back(1);

    // Test iterator and dereferencing
    std::vector<int>::iterator it1 = stdVec.begin();
    ft::vector<int>::iterator it2 = ftVec.begin();
    if (*it1 != *it2) {
        std::cout << "ERROR: Iterators do not match" << std::endl;
    }

    // Test size
    if (stdVec.size() != ftVec.size()) {
        std::cout << "ERROR: Size does not match" << std::endl;
    }

    // Test clear
    stdVec.clear();
    ftVec.clear();
    if (stdVec.size() != ftVec.size()) {
        std::cout << "ERROR: Size does not match after clear" << std::endl;
    }

    // Test insert
    for (int i = 0; i < 10; i++) {
        stdVec.insert(stdVec.begin() + i, i);
        ftVec.insert(ftVec.begin() + i, i);
    }

    // Test erase
    stdVec.erase(stdVec.begin() + 5);
    ftVec.erase(ftVec.begin() + 5);
    if (stdVec.size() != ftVec.size()) {
        std::cout << "ERROR: Size does not match after erase" << std::endl;
    }

    // Test swap
    std::vector<int> stdVec2;
    ft::vector<int> ftVec2;
    stdVec.swap(stdVec2);
    ftVec.swap(ftVec2);
    if (stdVec.size() != ftVec.size() || stdVec2.size() != ftVec2.size())
        std::cout << "ERROR: Swap failed" << std::endl;
    // Output success message
    std::cout << "All tests [VECTOR] passed!" << std::endl;

    return 0;
}
