#include "ft_vector.hpp"
// #include <vector>
int main()
{
    ft::vector<int> myVector;

    std::cout << myVector.size() << std::endl;
    ft::vector<int>::iterator it;
    // ft::iterator<int> it;
    for (it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
