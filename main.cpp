#include "vector.hpp"
#include <vector>
#include <iostream>
int main()
{
    ft::vector<int> v(4,50);
    ft::vector<int>::reverse_iterator it = v.rbegin();
    // std::cout << v.capacity() << std::endl;
    // v.assign(2, 900);
    // std::cout << v.capacity() << std::endl;
    // for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     std::cout << *it << std::endl;
    // std::vector<int>::reverse_iterator it;
}
