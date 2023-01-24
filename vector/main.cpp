#include "vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
int main()
{
    // std::string str, ft_str;
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
        std::istringstream str_f("");
        std::istreambuf_iterator<char> it_f(str_f), end_f;

        std::istringstream str_v("");
        std::istreambuf_iterator<char> it_v(str_v), end_v;

        // std::vector<std::string> v(100, "hello");
        ft::vector<int> ft_v;
        std::vector<int> v;




        std::cout << "part 1  " << std::endl;
        ft_v.assign(it_v, end_v);
        v.assign(it_f, end_f);

        // it = v.erase(v.begin(), v.end());
        // ft_it = ft_v.erase(ft_v.begin(), ft_v.end());
        std::cout << "part 2  " << std::endl;

        // s = v.size();
        ft_s = ft_v.size();
        // c = v.size();
        ft_c = ft_v.size();
        // for (size_t i = 0; i < v.size(); ++i)
        //     str += v[i];
        // for (size_t i = 0; i < ft_v.size(); ++i)
        //     ft_str += ft_v[i];
        // cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        // cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        std::cout << "part 3  " << std::endl;

        std::cout << "their capacity : " << v.capacity() << "\nmy capacity : " << ft_v.capacity() << std::endl;
        std::cout << "their size : " << v.size() << "\nmy size : " << ft_v.size() << std::endl;
         
        // it = v.begin();
        // ft_it = ft_v.begin();
        // while (ft_it != ft_v.end())
        // {
        //     std::cout <<  " = = = " << *ft_it << std::endl;
        //     // it++;
        //     ft_it++;
        // }
    }
}
