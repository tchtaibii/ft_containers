#include "vector.hpp"
#include <vector>
#include <iostream>
int main()
{
    ft::vector<std::string> v;
    // ft::vector<int>::iterator it = v.begin();
    // it = v.insert(it + 1, 15);
    // v.insert(it, 16);

    // for (ft::vector<int>::iterator i = v.begin(); i != v.end(); i++)
    // {
    //     std::cout << "element : " << *i << std::endl;
    // }
    
    std::string s_string[32] = {                                                                   \
        "1", "2", "3",                    \
        "4", "5", "6",                    \
        "7", "8", "9",                    \
        "10", "11", "12",                    \
        "13", "14", "15",                    \
        "16", "17", "18",                    \
        "19", "21", "21",                    \
        "22", "23", "24",                    \
        "25", "26", "27",                    \
        "28", "29", "30",                    \
        "31", "32"                                             \
    };
    v.insert(v.begin(), s_string, s_string + 32);
    
    // for (ft::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
    // {
    //     std::cout << "element : " << *i << std::endl;
    // }
}
