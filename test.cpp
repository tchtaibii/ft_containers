#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    int* src = new int[5];
    for (size_t i = 0; i < 5; i++)
        src[i] = i;
    
    int* dest = new int[7];
    for (size_t i = 0; i < 7; i++)
    {
        dest[i] = i + 66;
    }
    
    std::copy(src, src + 5, dest);

    std::cout << "Elements of destination array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dest[i] << " ";
}
}