#include "vector.hpp"
#include <vector>
#include <iostream>
int main()
{
    ft::vector<std::string> v;
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
}
