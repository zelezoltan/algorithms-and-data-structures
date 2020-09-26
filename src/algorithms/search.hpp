#ifndef ALGORITHMS_SEARCH_HPP_
#define ALGORITHMS_SEARCH_HPP_

#include <vector>

namespace algorithms {

enum class BinarySearchImplementation {
  kRecursive,
  kIterative
};

const BinarySearchImplementation kBinSearchImplementation = BinarySearchImplementation::kIterative;

// Searches an array for a given value x. (Assumes T has implemented the comparison operator !=)
// Returns the index of the value if found, otherwise vec.size().
template <typename T>
int LinearSearch(const std::vector<T>& vec, const T& x) {
  int i = 0;
  while (i < vec.size() && vec[i] != x) ++i;
  return i; 
}

// Recursive implementation of the binary search.
// Returns the index of the found element or -1.
template <typename T>
int BinarySearchRecursive(const std::vector<T>& vec, int low, int high, const T& x) {
  if (low > high) { // interval [low..high] is empty
    return -1; // Not found
  } else {
    int middle = (low + high) / 2;
    if (vec[middle] == x) {
      return middle;
    } else if (vec[middle] > x) {
      return BinarySearchRecursive(vec, low, middle - 1, x);
    } else { // if vec[middle] < x
      return BinarySearchRecursive(vec, middle + 1, high, x);
    }
  }
}

// Iterative implementation of the binary search.
// Returns the index of the found element or -1.
template <typename T>
int BinarySearchIterative(const std::vector<T>& vec, const T& x) {
  int low = 0;
  int high = vec.size() - 1;
  while (low <= high) {
    int middle = (low + high) / 2;
    if (vec[middle] == x) {
      return middle;
    } else if (vec[middle] > x) {
      high = middle - 1;
    } else { // if vec[middle] < x
      low = middle + 1;
    }
  }
  return -1; // Not found
}

// Searches a sorted array for a given value x. (Assumes that the array is sorted and comparison operators == and > are implemented by type T)
// Returns the index of the found element or -1.
template <typename T>
int BinarySearch(const std::vector<T>& vec, const T& x) {
  int index;
  switch (kBinSearchImplementation) {
    case BinarySearchImplementation::kRecursive:
      index = BinarySearchRecursive(vec, 0, vec.size() - 1, x);
      break;
    case BinarySearchImplementation::kIterative:
      index = BinarySearchIterative(vec, x);
      break;
  }
  return index;
}

} // namespace algorithms

#endif // ALGORITHMS_SEARCH_HPP_