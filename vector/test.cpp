#include <algorithm>
#include <vector>
#include <iostream>
#include "vector.hpp"
int main()
{
    ft::vector<int> ft_v(10 , 64);
    // ft_v.insert(ft_v.begin(), 0, 64);
    // ft_v.insert(ft_v.end(), 0, 64);
    ft_v.insert(ft_v.begin() + 1, 1, -9);

    // v.insert(v.begin(), 0, 64);
    // v.insert(v.end(), 0, 64);
    std::vector<int> v(10, 64);
    v.insert(v.begin() + 1, 1, -9);
    // for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //     std::cout << *it << std::endl;


    std::cout << "their capacity : " << v.capacity() << "\nmy capacity : " << ft_v.capacity() << std::endl;
    std::cout << "their size : " << v.size() << "\nmy size : " << ft_v.size() << std::endl;
    ft::vector<int>::iterator ft_it = ft_v.begin();
    std::vector<int>::iterator it = v.begin();
    // while (it != v.end() && ft_it != ft_v.end())
    // {
    //     std::cout << *it << " = = = " << *ft_it << std::endl;
    //     it++;
    //     ft_it++;
    // }
}