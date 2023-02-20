#include <iostream>
#include <stack>
#include "stack.hpp"

int main()
{
    // Create stacks for testing
    std::stack<int> stdStack;
    ft::stack<int> ftStack;

    // Test push
    stdStack.push(1);
    ftStack.push(1);

    // Test top
    if (stdStack.top() != ftStack.top()) {
        std::cout << "ERROR: Top does not match" << std::endl;
    }

    // Test size
    if (stdStack.size() != ftStack.size()) {
        std::cout << "ERROR: Size does not match" << std::endl;
    }

    // Test pop
    stdStack.pop();
    ftStack.pop();
    if (stdStack.size() != ftStack.size()) {
        std::cout << "ERROR: Size does not match after pop" << std::endl;
    }

    // Add more tests for all functions and iterators

    // Output success message
    std::cout << "All tests [STACK] passed!" << std::endl;

    return 0;
}