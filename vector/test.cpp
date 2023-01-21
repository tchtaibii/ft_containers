#include <algorithm>
#include <vector>
#include <iostream>
#include "vector.hpp"
int main()
{
    ft::vector<int> v;

    v.insert(v.end(), 10, 64);
    for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << std::endl;
}