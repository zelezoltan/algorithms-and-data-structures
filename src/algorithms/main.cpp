#include <iostream>
#include <algorithm>
#include "search.hpp"
#include "sort.hpp"

template <typename T>
void PrintVector(const std::vector<T>& vec) {
  for (const auto& elem : vec) {
    std::cout << elem << ' '; // T has operator<< defined
  }
  std::cout << '\n';
}

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
  PrintVector(values);
  
  index = algorithms::BinarySearch(values, x);
  if (index < values.size()) {
    std::cout << "Found! " << index << ", " << values[index] << '\n';
  } else {
    std::cout << "Not found!" << '\n';
  }

  values = {4, 6, 2, 8, 3, 5, 2, 10, 11};
  algorithms::InsertionSort(values);
  PrintVector(values);

  values = {4, 6, 2, 8, 3, 5, 2, 10, 11};
  algorithms::MinSelectionSort(values);
  PrintVector(values);

  values = {4, 6, 2, 8, 3, 5, 2, 10, 11};
  algorithms::MergeSort(values);
  PrintVector(values);

  values = {4, 6, 2, 8, 3, 5, 2, 10, 11, 4, 6, 2, 8, 3, 5, 2, 10, 11};
  algorithms::QuickSort(values);
  PrintVector(values);

  values = {4, 6, 2, 8, 3, 5, 2, 10, 11, 4, 6, 2, 8, 3, 5, 2, 10, 11};
  algorithms::HeapSort(values);
  PrintVector(values);

  return 0;
}
