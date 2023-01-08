#include "ft_vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test(5, 2);
    ft::vector<int> test2;
    std::vector<int> test3(5, 2);
    std::cout << test3.max_size() << std::endl;
    std::cout << test.max_size() << std::endl;
    test2 = test;
}