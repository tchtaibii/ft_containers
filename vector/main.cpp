#include "vector.hpp"
#include <vector>
#include <iostream>
int main()
{
    std::string str, ft_str;
    /*
     * var to store the size and the capacity
     */
    ft::vector<std::string>::size_type s, ft_s;
    ft::vector<std::string>::size_type c, ft_c;
    std::vector<std::string>::iterator it;
    ft::vector<std::string>::iterator ft_it;
    /*
     * bool to store the comparison
     */
    bool cond;

    /*------------------------------- test 1: empty vector ----------------------------------------*/
    // insert at the begin
    {
        std::vector<std::string> v(100, "hello");
        ft::vector<std::string> ft_v(100, "hello");

        it = v.erase(v.begin(), v.end());
        ft_it = ft_v.erase(ft_v.begin(), ft_v.end());

        s = v.size();
        ft_s = ft_v.size();
        c = v.size();
        ft_c = ft_v.size();
        for (size_t i = 0; i < v.size(); ++i)
            str += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_str += ft_v[i];
        cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));

        std::cout << "their capacity : " << c << "\nmy capacity : " << ft_c << std::endl;
        std::cout << "their size : " << s << "\nmy size : " << ft_s << std::endl;
        std::cout << cond << std::endl;
        it = v.begin();
        ft_it = ft_v.begin();
        while (it != v.end() || ft_it != ft_v.end())
        {
            std::cout << *it << " = = = " << *ft_it << std::endl;
            it++;
            ft_it++;
        }
    }
}
