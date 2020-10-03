#include <iostream>
#include <vector>

#include "singly_linked_list.hpp"

int main() {

  std::vector<int> values {5, 2, 6, 2, 8, 5, 3, 3, 9, 2};
  data_structures::SinglyLinkedList<int> list;
  for (int num : values) {
    list.push_back(num);
  }
  while (!list.IsEmpty()) {
    std::cout << list.pop_front() << " ";
  }
  std::cout << '\n';
  for (int num : values) {
    list.push_front(num);
  }
  while (!list.IsEmpty()) {
    std::cout << list.pop_front() << " ";
  }
  std::cout << '\n';

  return 0;
}