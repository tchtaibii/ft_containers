#include <iostream>
#include "../includes/red_black_tree.hpp"
#include "./print_tree.hpp"
#include "./map.hpp"
#include <map>
int main()
{
    fancy_tree<int> debug;
    bool cond;

    std::map<int, std::string> m2;
    ft::map<int, std::string> ft_m2;

    for (size_t i = 0; i < 10; i++)
    {
        m2.insert(std::make_pair(i, "string1"));
        ft_m2.insert(ft::make_pair(i, "string1"));
    }
    std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
    ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();
    std::cout << "dyalhum  " << &it2 << " value = " << &(it2->first) << std::endl;
    std::cout << "dyali :" << &ft_it2 << " value = " << &(ft_it2->first) << std::endl;
    // std::cout << "dyalhum  " << &it2 << " value = " << m2.begin()->first << std::endl;
    // std::cout << "dyali :" << &ft_it2 << " value = " << ft_m2.begin()->first << std::endl;
    // std::cout << "****" << std::endl;
    // // debug.print_tree(ft_m2.tree.root, V_VIEW);
    // m2.erase(m2.begin());
    // ft_m2.erase(ft_m2.begin());
    // std::cout << "dyalhum  " << &it2 << " value = " << &(it2->first) << std::endl;
    // std::cout << "dyali :" << &ft_it2 << " value = " << &(ft_it2->first) << std::endl;
    // // ft_m2.tree.printTree();
    //  std::cout << "dyalhum  " << &it2 << " value = " << m2.begin()->first << std::endl;
    // std::cout << "dyali :" << &ft_it2 << " value = " << ft_m2.begin()->first << std::endl;
    // // debug.print_tree(ft_m2.tree.root, V_VIEW);
    // std::cout << ft_m2.tree.g_leaf()->parent->val.first << std::endl;
    // // std::cout << ft_m2.tree.g_root()->left->val.first << std::endl;
    // // std::cout << "here " << std::endl;
    // // std::cout << ft_m2.tree.root->val.first << std::endl;
    // // cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());
    // std::cout << "after ***\ndyalhum  " << &it2 << " value = " << &(it2->first) << std::endl;
    // std::cout << "dyali :" << &ft_it2 << " value = " <<&(ft_it2->first )<< std::endl;
    // ft_it2 = ft_m2.rbegin();
    // std::cout << &ft_it2->first << std::endl;
    // m2.erase(it2->first);
    // ft_m2.erase(ft_it2->first);
    // it2 = m2.rbegin();
    // ft_it2 = ft_m2.rbegin();
    //  ft::map<int, std::string>::iterator ft_it = ft_m2.begin();
    // for (std::map<int, std::string>::iterator it = m2.begin(); it != m2.end(); it++)
    // {
    //     std::cout << "dyalhum  " << it->first << std::endl;
    //     std::cout << "dyali :" << ft_it->first << std::endl;
    //     ft_it++;
    // }
        

    // cond = cond && m2.size() == ft_m2.size() && compareMaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());
    // std::cout << "\n" << m2.size() << "<------- dyyalo \n" <<  ft_m2.size() << " <----- dyali" << std::endl;

    // m.erase("-0");
    // m.tree.printTree();
    // std::cout << m.size();

}