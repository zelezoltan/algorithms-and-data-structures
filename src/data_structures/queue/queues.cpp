#include <iostream>
#include <vector>

#include "fixed_queue.hpp"
#include "dynamic_queue.hpp"

int main() {
  std::vector<int> values = {1, 3, 5, 2, 22, 8, 2, 6, 4, 15, 13, 66};
  data_structures::FixedQueue<int> queue1(5);
  std::cout << queue1.length() << " " << queue1.IsEmpty() << " " << queue1.IsFull() << '\n';
  for(int i = 0; i < 5; ++i) {
    queue1.add(values[i]);
  }
  std::cout << queue1.length() << " " << queue1.IsEmpty() << " " << queue1.IsFull() << '\n';
  try {
    queue1.add(4);
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
  while (!queue1.IsEmpty()) {
    std::cout << queue1.rem() << " ";
  }
  std::cout << '\n';
  for(int i = 5; i < 10; ++i) {
    queue1.add(values[i]);
  }
  std::cout << queue1.length() << " " << queue1.IsEmpty() << " " << queue1.IsFull() << '\n';
  queue1.rem();
  queue1.rem();
  for(int i = 0; i < 2; ++i) {
    queue1.add(values[i]);
  }
   try {
    queue1.add(4);
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
  std::cout << queue1.length() << " " << queue1.IsEmpty() << " " << queue1.IsFull() << '\n';
  while (!queue1.IsEmpty()) {
    std::cout << queue1.rem() << " ";
  }
  std::cout << '\n';

  data_structures::DynamicQueue<int> queue;
  queue.add(2);
  for (int value : values) {
    queue.add(value);
  }
  while (!queue.IsEmpty()) {
    std::cout << queue.rem() << " ";
  }
  std::cout << '\n';
  return 0;
}