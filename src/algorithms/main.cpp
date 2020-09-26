#include <iostream>
#include <algorithm>
#include "search.hpp"

int main() {
  std::vector<int> values = {4, 6, 2, 8, 3, 5, 2, 10, 11};
  int x = 6;

  int index = algorithms::LinearSearch(values, x);
  if (index < values.size()) {
    std::cout << "Found! " << index << ", " << values[index] << '\n';
  } else {
    std::cout << "Not found!" << '\n';
  }

  std::sort(values.begin(), values.end());
  for (int value : values) {
    std::cout << value << " ";
  }
  std::cout << '\n';
  index = algorithms::BinarySearch(values, x);
  if (index < values.size()) {
    std::cout << "Found! " << index << ", " << values[index] << '\n';
  } else {
    std::cout << "Not found!" << '\n';
  }

  return 0;
}