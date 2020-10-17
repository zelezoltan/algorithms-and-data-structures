#include <iostream>
#include <vector>

#include "priority_queue.hpp"

int main () {
  std::vector<int> nums = {3, 8, 2, 5, 1, 7, 8, 9, 22, 213, 44, 122, 1, 2, 2, 2, 77};
  data_structures::PriorityQueue<int> prq(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    prq.add(nums[i]);
  }
  for (int i = nums.size() - 1; i >= 0; --i) {
    nums[i] = prq.RemoveMax();
  }
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << '\n';
  return 0;
}