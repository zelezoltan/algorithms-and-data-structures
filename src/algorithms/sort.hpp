#ifndef ALGORITHMS_SORT_HPP_
#define ALGORITHMS_SORT_HPP_

#include <vector>
#include <ctime>
#include <cstdlib>

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

void SeedRandomGenerator() {
  std::srand(std::time(nullptr));
}

// Generates a random number in range [low..high]
int GetRandomNumber(int low, int high) {
  return low + (std::rand() % (high-low + 1));
}

template <typename T>
typename std::vector<T>::size_type left(typename std::vector<T>::size_type k) {
  return 2*k + 1;
}

template <typename T>
typename std::vector<T>::size_type parent(typename std::vector<T>::size_type k) {
  return (k - 1) / 2;
}

template <typename T>
void sink(std::vector<T>& vec, typename std::vector<T>::size_type k,
   typename std::vector<T>::size_type n) {
  typename std::vector<T>::size_type i = k;
  typename std::vector<T>::size_type j = left<T>(k);
  bool b = true;
  while (j < n && b) {
    // arr_[j] is the left child of arr_[i]
    // arr_[j + 1] is the right child of arr_[i]
    if (j < n - 1 && vec[j + 1] > vec[j]) {
      ++j;
    }
    // arr_[j] is the greater child of arr_[i]
    if (vec[i] < vec[j]) {
      swap(vec[i], vec[j]);
      i = j;
      j = left<T>(j);
    } else {
      b = false;
    }
  }
}

// Builds a max heap from a vector in place
template <typename T>
void BuildMaxHeap(std::vector<T>& vec) {
  typename std::vector<T>::size_type size = vec.size();
  for (typename std::vector<T>::size_type k = parent<T>(size - 1); k > 0; --k) {
    sink(vec, k, size);
  }
  sink(vec, 0, size);
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

enum class QuickSortImplementation {
  // Do QuickSort every iteration
  kNormal,
  // If the size of the array is smaller than some constant c,
  // do InsertionSort instead 
  kMixed,
  // Mixed implementation using a while loop and one recursive call 
  kTailCallOptimized
};

const MergeSortImplementation kMergeSortImplementation 
  = MergeSortImplementation::kEfficient;
const QuickSortImplementation kQuickSortImplementation
  = QuickSortImplementation::kTailCallOptimized;

// Minimum number of elements needed to perform Quicksort
// It is known that for small arrays Insertionsort is more efficient
// Usually between 20 and 40
const int kQuicksortMinElemCount = 30;

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

// Sorts the subarray vec[low..high]
template <typename T>
void InsertionSubSort(std::vector<T>& vec, int low, int high) {
  for(int i = low + 1; i <= high; ++i) { 
    // vec[low..i-1] is sorted
    // If new element is smaller then the biggest in the sorted part
    if (vec[i - 1] > vec[i]) { 
      // store the new element
      T value = vec[i]; 
      // move the biggest element to the place of the new 
      // (This creates a hole in the place of the previously biggest element)
      vec[i] = vec[i - 1]; 
      int j = i - 2;
      // While the previous element is bigger than the new
      while (j >= low && vec[j] > value) { 
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
  std::vector<T> a = MergeSortInEfficient(halves.first);
  std::vector<T> b = MergeSortInEfficient(halves.second);
  return MergeInEfficient(a, b);
}

// Efficient implementation of merge
template <typename T>
void Merge(std::vector<T>& vec, int low, int middle, int high) {
  // Number of elements in the first half
  int d = middle - low;
  // Copy the elements in the first half to temp
  std::vector<T> temp(vec.begin() + low, vec.begin() + low + d);
  int i = middle;
  int k = low;
  int j = 0;
  // Merging the two half
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
  // After the loop either i = high:
  //   - the remaining elements in temp needed
  //     to be copied to the end of the array 
  // or j = d:
  //   - the elements in temp are copied into vec already
  //     and the remaining elements are already in the 
  //     right place 
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
      break;
  }
}

template <typename T>
int Partition(std::vector<T>& vec, int low, int high) {
  // Select the pivot randomly
  int i = sort_helpers::GetRandomNumber(low, high);
  int pivot = vec[i];
  // Move the last element in the place of the pivot
  vec[i] = vec[high];
  // Find the first element in the array > pivot
  i = low;
  while (i < high && vec[i] <= pivot) {
    ++i;
  }
  // If we found an element that is larger
  if (i < high) {
    // vec[low..i) <= pivot
    // vec[i..j) >= pivot
    // vec[j..high) unknown
    for (int j = i + 1; j < high; ++j) {
      // If we find an element thats < pivot in vec[j..high)
      // swap the element with the first element >= pivot (vec[i])
      // move the index to the new first element >= pivot (i + 1)
      if (vec[j] < pivot) {
        sort_helpers::swap(vec[i], vec[j]);
        ++i;
      }
    }
    // Move the first element >= pivot to the last place
    vec[high] = vec[i];
    // Move the pivot to it's place
    // Now vec[low..i) <= pivot and vec[(i + 1)..high] >= pivot
    vec[i] = pivot;
  } else { // All elements are smaller than or equal to the pivot
    vec[high] = pivot;
  }
  // Return with the index of the pivot
  return i;
}

template <typename T>
void QuickSort(std::vector<T>& vec, int low, int high) {
  if (low < high) {
    int pivot_index = Partition(vec, low, high);
    QuickSort(vec, low, pivot_index - 1);
    QuickSort(vec, pivot_index + 1, high);
  }
}

template <typename T>
void QuickSortMixed(std::vector<T>& vec, int low, int high) {
  if (low + kQuicksortMinElemCount < high) {
    int pivot_index = Partition(vec, low, high);
    QuickSort(vec, low, pivot_index - 1);
    QuickSort(vec, pivot_index + 1, high);
  } else {
    InsertionSubSort(vec, low, high);
  }
}

template <typename T>
void QuickSortTailCallOptimized(std::vector<T>& vec, int low, int high) {
  while (low + kQuicksortMinElemCount < high) {
    int pivot_index = Partition(vec, low, high);
    QuickSortTailCallOptimized(vec, low, pivot_index - 1);
    low = pivot_index + 1;
  }
  InsertionSubSort(vec, low, high);
}

template <typename T>
void QuickSort(std::vector<T>& vec) {
  // Seed the random number generator
  sort_helpers::SeedRandomGenerator();
  switch (kQuickSortImplementation) {
    case QuickSortImplementation::kNormal:
      QuickSort(vec, 0, vec.size() - 1);
      break;
    case QuickSortImplementation::kMixed:
      QuickSortMixed(vec, 0, vec.size() - 1);
      break;
    case QuickSortImplementation::kTailCallOptimized:
      QuickSortTailCallOptimized(vec, 0, vec.size() - 1);
      break;
  }
}

template <typename T>
void HeapSort(std::vector<T>& vec) {
  sort_helpers::BuildMaxHeap(vec);
  for (typename std::vector<T>::size_type i = vec.size() - 1; i > 0; --i) {
    sort_helpers::swap(vec[0], vec[i]);
    sort_helpers::sink(vec, 0, i);
  }
}


} // namespace algortihms

#endif // ALGORITHMS_SORT_HPP_
