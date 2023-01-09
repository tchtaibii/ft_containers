#include <vector>
#include "ft_vector.hpp"

int main() {
  std::vector<int> v;
  std::vector<int> ft_v;

  // Print the size and capacity of the vector
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';
  std::cout << "v capacity: " << v.capacity() << '\n';
  std::cout << "ft:v capacity: " << ft_v.capacity() << '\n';

  // Reserve capacity for 10 elements
  v.reserve(10);
  ft_v.reserve(10);

  // Print the size and capacity of the vector
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';
  std::cout << "v capacity: " << v.capacity() << '\n';
  std::cout << "ft:v capacity: " << ft_v.capacity() << '\n';

  // Push 5 elements onto the vector
  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
    ft_v.push_back(i);
  }

  // Print the size and capacity of the vector
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';
  std::cout << "v capacity: " << v.capacity() << '\n';
  std::cout << "ft:v capacity: " << ft_v.capacity() << '\n';

  return 0;
}