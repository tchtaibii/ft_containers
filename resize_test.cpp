#include "ft_vector.hpp"
#include <vector>
int main() {
  std::vector<int> v(5);
  ft::vector<int> ft_v(5);
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';

  // Resize to 5 elements, fill with default value
  v.resize(5);
  ft_v.resize(5);
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';


  // Resize to 2 elements, fill with 4
  v.resize(2, 4);
  ft_v.resize(2, 4);
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';

  // Resize to 0 elements
  v.resize(0);
  ft_v.resize(0);
  std::cout << "v size: " << v.size() << '\n';
  std::cout << "ft:v size: " << ft_v.size() << '\n';
  std::cout << "v empty: " << std::boolalpha << v.empty() << '\n';
  std::cout << "ft:v empty: " << std::boolalpha << ft_v.empty() << '\n';

  return 0;
}