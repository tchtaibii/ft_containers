#include "ft_vector.hpp"
#include <vector>
void ft_test()
{
    // Default constructor
    ft::vector<int> v1;
    std::cout << "v1 size: " << v1.size() << '\n';
    std::cout << "v1 capacity: " << v1.capacity() << '\n';
    std::cout << "v1 empty: " << std::boolalpha << v1.empty() << '\n';

    // Fill constructor
    ft::vector<int> v2(10, 1);
    std::cout << "v2 size: " << v2.size() << '\n';
    std::cout << "v2 capacity: " << v2.capacity() << '\n';
    std::cout << "v2 empty: " << std::boolalpha << v2.empty() << '\n';
    std::vector<int>::iterator a;
    // Copy constructor
    ft::vector<int> v3(v2);
    std::cout << "v3 size: " << v3.size() << '\n';
    std::cout << "v3 capacity: " << v3.capacity() << '\n';
    std::cout << "v3 empty: " << std::boolalpha << v3.empty() << '\n';

    // Assignment copy
    v1 = v2;
    std::cout << "v1 size: " << v1.size() << '\n';
    std::cout << "v1 capacity: " << v1.capacity() << '\n';
    std::cout << "v1 empty: " << std::boolalpha << v1.empty() << '\n';

    // max_size
    std::cout << "v1 max size: " << v1.max_size() << '\n';

    // push_back
    v1.push_back(2);
    std::cout << "v1 size: " << v1.size() << '\n';
    std::cout << "v1 capacity: " << v1.capacity() << '\n';

    // resize
    v1.resize(5);
    std::cout << "v1 size: " << v1.size() << '\n';
    std::cout << "v1 capacity: " << v1.capacity() << '\n';

    // at
    std::cout << "v1 at 3: " << v1.at(3) << '\n';

    // random access
    std::cout << "v1 [4]: " << v1[4] << '\n';
    v1[4] = 3;
    std::cout << "v1 [4]: " << v1[4] << '\n';
    system("leaks a.out");
}
int main()
{
    ft_test();
    return 0;
}
