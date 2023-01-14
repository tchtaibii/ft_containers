#include "vector.hpp"
// #include <vector>
int main()
{
    ft::vector<std::string> v;

    v.resize(14, "HelloWorld");
    v.resize(64, "I-like-vectors");

    return 0;
}
