#ifndef ALGORITHMS_SORT_HPP_
#define ALGORITHMS_SORT_HPP_

#include <vector>

namespace algorithms {

template <typename T>
using Vectorpair = std::pair<std::vector<T>, std::vector<T>>;

namespace sort_helpers {

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
Vectorpair<T> split(const std::vector<T>& vec) {
  int half = vec.size() / 2;
  return Vectorpair<T>(std::vector<T>(vec.begin(), vec.begin() + half), 
                       std::vector<T>(vec.begin() + half, vec.end()));
}

} // namespace sort_helpers

enum class MergeSortImplementation {
  // Implementation by always copying the elements
  // into new arrays before recursive calls and in merge
  kInEfficient,  
  // Efficient implementation modifying the elements in place 
  // (creates a new array in merge with half the size middle - low)
  kEfficient 
};

const MergeSortImplementation kMergeSortImplementation 
  = MergeSortImplementation::kEfficient;

// Sorts the elements in place. 
// (Assumes T implements operators: =(assignment), >)
template <typename T>
void InsertionSort(std::vector<T>& vec) {
  for(int i = 1; i < vec.size(); ++i) { 
    // vec[0..i-1] is sorted
    // If new element is smaller then the biggest in the sorted part
    if (vec[i - 1] > vec[i]) { 
      // store the new element
      T value = vec[i]; 
      // move the biggest element to the place of the new 
      // (This creates a hole in the place of the previously biggest element)
      vec[i] = vec[i - 1]; 
      int j = i - 2;
      // While the previous element is bigger than the new
      while (j >= 0 && vec[j] > value) { 
        // move the hole backwards by moving the bigger element forward
        sort_helpers::swap(vec[j], vec[j + 1]); 
        --j;
      }
      // Put the new element in the hole
      vec[j + 1] = value; 
    }
  }
}

// Sorts the elements in place. 
// (Assumes T implements operators: =(assignment), >)
template <typename T>
void MinSelectionSort(std::vector<T>& vec) {
  for (int i = 0; i < vec.size() - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < vec.size(); ++j) {
      if (vec[min] > vec[j]) {
        min = j;
      }
    }
    sort_helpers::swap(vec[i], vec[min]);
  }
}

// Ineffiecient merge creating a new array to merge into and returning the copy
template <typename T>
std::vector<T> MergeInEfficient(const std::vector<T>& a,
                                const std::vector<T>& b) {
  int i = 0;
  int j = 0;
  int k = 0;
  std::vector<T> merged(a.size() + b.size());
  while (i < a.size() || j < b.size()) {
    if (i < a.size() && j < b.size()) {
      if (a[i] <= b[j]) {
        merged[k] = a[i];
        ++i;
      } else {
        merged[k] = b[j];
        ++j;
      }
      
    } else if (i < a.size()) {
      merged[k] = a[i];
      ++i;
    } else {
      merged[k] = b[j];
      ++j;
    }
    ++k; 
  }
  return merged;
}

// Inefficient implementation of Merge sort
// Creates copies of parts of the array
template <typename T>
std::vector<T> MergeSortInEfficient(const std::vector<T>& vec) {
  if (vec.size() <= 1) return vec;
  Vectorpair<T> halves = sort_helpers::split(vec);
  std::vector<int> a = MergeSortInEfficient(halves.first);
  std::vector<int> b = MergeSortInEfficient(halves.second);
  return MergeInEfficient(a, b);
}

// Efficient implementation of merge
template <typename T>
void Merge(std::vector<T>& vec, int low, int middle, int high) {
  // Number of elements in the first half
  int d = middle - low;
  std::vector<T> temp(vec.begin() + low, vec.begin() + low + d);
  int i = middle;
  int k = low;
  int j = 0;
  while (i < high && j < d) {
    if (vec[i] > temp[j]) {
      vec[k] = temp[j];
      ++j;
    } else {
      vec[k] = vec[i];
      ++i;
    }
    ++k;
  }
  while (j < d) {
    vec[k] = temp[j];
    ++j;
    ++k;
  }
}

// Efficient implementation of Merge sort
// Sorts the subvector vec[low..high)
template <typename T>
void MergeSort(std::vector<T>& vec, int low, int high) {
  if (high - low > 1) {
    int middle = (high + low) / 2;
    MergeSort(vec, low, middle);
    MergeSort(vec, middle, high);
    Merge(vec, low, middle, high);
  }
}

template <typename T>
void MergeSort(std::vector<T>& vec) {
  switch (kMergeSortImplementation) {
    case MergeSortImplementation::kInEfficient:
      vec = MergeSortInEfficient(vec);
      break;
    case MergeSortImplementation::kEfficient:
      MergeSort(vec, 0, vec.size());
  }
}


} // namespace algortihms

#endif // ALGORITHMS_SORT_HPP_
