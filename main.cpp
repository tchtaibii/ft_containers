#include "ft_vector.hpp"
// #include <vector>
int main()
{
    ft::vector<int> myVector;
    myVector.push_back(1);
    std::cout << "okaaaay1" << std::endl;
    myVector.push_back(2);
    myVector.push_back(3);
    std::cout << "okaaaay" << std::endl;

    ft::vector<int>::iterator it;
    // ft::iterator<int> it;
    for (it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
