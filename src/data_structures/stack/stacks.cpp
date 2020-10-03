#include <iostream>
#include <vector>

#include "fixed_stack.hpp"
#include "dynamic_stack.hpp"
#include "stack.h"
#include "linked_stack.hpp"

int main() {

  data_structures::FixedStack<int> stack1(5);
  std::cout << stack1.IsEmpty() << " " << stack1.IsFull() << '\n'; 
  std::vector<int> values = {1, 3, 5, 2, 22, 8, 2, 6, 4, 15, 13, 66};
  for(int i = 0; i < 5; ++i) {
    stack1.push(values[i]);
  }
  std::cout << stack1.IsFull() << '\n';
  while (!stack1.IsEmpty()) {
    std::cout << stack1.pop() << " ";
  }
  std::cout << '\n';

  data_structures::Stack<int> stack;
  std::cout << stack1.IsEmpty() << " " << stack1.IsFull() << '\n'; 
  for (int i = 0; i < values.size(); ++i) {
    stack.push(values[i]);
  }
  while (!stack.IsEmpty()) {
    std::cout << stack.pop() << " ";
  }
  std::cout << '\n';

  data_structures::LinkedStack<int> linked_stack;
  std::cout << linked_stack.IsEmpty() << " " << linked_stack.IsFull() << '\n'; 
  for (int i = 0; i < values.size(); ++i) {
    linked_stack.push(values[i]);
  }
  while (!linked_stack.IsEmpty()) {
    std::cout << linked_stack.pop() << " ";
  }
  std::cout << '\n';

  return 0;
}
