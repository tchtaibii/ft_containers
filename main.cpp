#include "vector.hpp"
#include <vector>
int main()
{
    ft::vector<int> myVector;
    // Insert some initial values into the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    // Print out the current contents of the vector
    for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    // Insert the value 4 at the third position (index 2)
    myVector.insert(myVector.begin() + 2, 4);
    myVector.insert(myVector.begin() + 2, 6, 99999);
    std::cout << "capacity : " << myVector.capacity() << std::endl; 
    std::cout << "size : " << myVector.size() << std::endl; 
    // Print out the current contents of the vector
    for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}