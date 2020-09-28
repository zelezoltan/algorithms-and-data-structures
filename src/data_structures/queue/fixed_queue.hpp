#ifndef DATA_STRUCTURES_QUEUE_FIXED_QUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_FIXED_QUEUE_HPP_

#include <exception>

#include "Iqueue.h"

namespace data_structures {

// Fixed length queue
template <typename T>
class FixedQueue : public IQueue<T> {
 public:
  explicit FixedQueue(int size);
  ~FixedQueue() override;
  virtual void add(T elem) override;
  // Removes and returns the first element in the queue
  T& rem() override;
  // Returns the first element of the queue
  T& first() override;
  // Returns the length of the queue
  int length() const override;
  virtual bool IsFull() const override;
  bool IsEmpty() const override;
  void SetEmpty() override;
 protected:
  FixedQueue() {};
  T* arr_ = nullptr;
  // The actual length of the array
  int length_ = 0;
  // The size of the allocated array
  int size_ = 0;
  // The index of the first element in the queue
  int start_ind_ = 0;
};

template <typename T>
FixedQueue<T>::FixedQueue(int size) : size_(size) {
  if (size_ <= 0) {
    throw std::domain_error("The size of the queue must be positive!");
  }
  arr_ = new T[size_];
}

template <typename T>
FixedQueue<T>::~FixedQueue() {
  delete[] arr_;
}

template <typename T>
int FixedQueue<T>::length() const {
  return length_;
}

template <typename T>
bool FixedQueue<T>::IsFull() const {
  return length_ == size_;
}

template <typename T>
bool FixedQueue<T>::IsEmpty() const {
  return length_ == 0;
}

template <typename T>
void FixedQueue<T>::SetEmpty() {
  length_ = 0;
  start_ind_ = 0;
}

template <typename T>
void FixedQueue<T>::add(T elem) {
  if (IsFull()) {
    throw std::length_error("The queue is full!");
  }
  arr_[(start_ind_ + length_) % size_] = elem;
  ++length_;
}

template <typename T>
T& FixedQueue<T>::first() {
  if (IsEmpty()) {
    throw std::length_error("The queue is empty!");
  }
  return arr_[start_ind_];
}

template <typename T>
T& FixedQueue<T>::rem() {
  if (IsEmpty()) {
    throw std::length_error("The queue is empty!");
  }
  int first_index = start_ind_;
  start_ind_ = (start_ind_ + 1) % size_;
  --length_; 
  return arr_[first_index];
}

} // namespace data_structures

#endif // DATA_STRUCTURES_QUEUE_FIXED_QUEUE_HPP_