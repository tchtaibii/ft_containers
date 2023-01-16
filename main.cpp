#include "vector.hpp"
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> v(2,50);
    v.push_back(899);
    v.push_back(5);
    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator it2 = std::find(v.begin(), v.end(), 899);
    while(it != it2)
        it++;
    v.erase(it);
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
}
}