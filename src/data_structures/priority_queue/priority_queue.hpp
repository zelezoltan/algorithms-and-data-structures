#ifndef DATA_STRUCTURES_PRIOROTY_QUEUE_PRIORITY_QUEUE_HPP
#define DATA_STRUCTURES_PRIOROTY_QUEUE_PRIORITY_QUEUE_HPP

namespace data_structures {

template <typename T>
class PriorityQueue {
 public:
  using size_type = unsigned long long;
  
  PriorityQueue(size_type size): size_(size) { arr_ = new T[size_]; }
  ~PriorityQueue() { delete[] arr_; }
  bool add(const T& value);
  T RemoveMax();
  T& max() const;
  bool IsFull() const { return length_ == size_; }
  bool IsEmpty() const { return length_ == 0; }
  void SetEmpty() { length_ = 0; }
 private:
  size_type left(size_type node_index) const { return 2*node_index + 1; }
  size_type right(size_type node_index) const { return 2*node_index + 2; }
  size_type parent(size_type node_index) const { return (node_index - 1) / 2; }
  void swap(T& a, T& b);
  void sink(size_type k, size_type n);

  T* arr_ = nullptr;
  // The maximum size of the queue
  size_type size_ = 0;
  // The actual size of the queue
  size_type length_ = 0;
};

template <typename T>
void PriorityQueue<T>::swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
bool PriorityQueue<T>::add(const T& value) {
  if (!IsFull()) {
    arr_[length_] = value;
    size_type inserted_index = length_;
    size_type parent_index = parent(inserted_index);
    ++length_;
    while (inserted_index > 0 && arr_[inserted_index] > arr_[parent_index]) {
      swap(arr_[inserted_index], arr_[parent_index]);
      inserted_index = parent_index;
      parent_index = parent(inserted_index);
    }
  } else { // The queue is full
    return false;
  }
}

template <typename T>
T& PriorityQueue<T>::max() const {
  if (!IsFull()) {
    return arr_[0];
  }
}

template <typename T>
T PriorityQueue<T>::RemoveMax() {
  if (!IsEmpty()) {
    T max = arr_[0];
    arr_[0] = arr_[length_ - 1];
    --length_;
    sink(0, length_);
    return max;
  }
}

template <typename T>
void PriorityQueue<T>::sink(size_type k, size_type n) {
  size_type i = k;
  size_type j = left(k);
  bool b = true;
  while (j < length_ && b) {
    // arr_[j] is the left child of arr_[i]
    // arr_[j + 1] is the right child of arr_[i]
    if (j < length_ - 1 && arr_[j + 1] > arr_[j]) {
      ++j;
    }
    // arr_[j] is the greater child of arr_[i]
    if (arr_[i] < arr_[j]) {
      swap(arr_[i], arr_[j]);
      i = j;
      j = left(j);
    } else {
      b = false;
    }
  }
}

} // namespace data_structures


#endif // DATA_STRUCTURES_PRIOROTY_QUEUE_PRIORITY_QUEUE_HPP