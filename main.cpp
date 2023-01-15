#include "vector.hpp"
#include <vector>
int main()
{
    ft::vector<std::string> myVector(5000, "test");
    // Insert some initial values into the vector
    // myVector.insert(myVector.begin(), 0, 64);
    // std::cout << "capacity : " << myVector.capacity() << std::endl;
    // myVector.insert(myVector.end(), 0, 64);
    // std::cout << "capacity : " << myVector.capacity() << std::endl;
    // myVector.insert(myVector.end(), 10, 64);
    // myVector.insert(myVector.end(), 10, 64);
    
    // // Print out the current contents of the vector
    // for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    // // Insert the value 4 at the third position (index 2)
    // // myVector.insert(myVector.begin() + 2, 6, 99999);
    
    // std::cout << "size : " << myVector.size() << std::endl;
    // std::cout << "capacity : " << myVector.capacity() << std::endl;
    // // Print out the current contents of the vector
    // for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
}