#include <iostream>
#include <vector>

#include "singly_linked_list.hpp"
#include "doubly_linked_list.hpp"

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

  data_structures::DoublyLinkedList<int> list2;
  for (int num : values) {
    list2.push_back(num);
  }
  while (!list2.IsEmpty()) {
    std::cout << list2.pop_front() << " ";
  }
  std::cout << '\n';
  for (int num : values) {
    list2.push_front(num);
  }
  while (!list2.IsEmpty()) {
    std::cout << list2.pop_back() << " ";
  }
  std::cout << '\n';

  return 0;
}