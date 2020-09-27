#ifndef DATA_STRUCTURES_DYNAMIC_STACK_HPP_
#define DATA_STRUCTURES_DYNAMIC_STACK_HPP_

#include <exception>

#include "Istack.h"

namespace data_structures {

template <typename T>
class DynamicStack : public IStack<T> {
 public:
  explicit DynamicStack(int size);
  DynamicStack() {}
  ~DynamicStack() override;
  // Push elem on the top of the stack
  void push(T elem) override;
  // Remove and return the top element of the stack
  T& pop() override;
  // Return the top element of the stack
  T& top() override;
  bool IsFull() const override;
  bool IsEmpty() const override;
  void SetEmpty() override;
 private:
  int n_ = 0;
  int size_ = 0;
  T* arr_ = nullptr;
};

template <typename T>
DynamicStack<T>::DynamicStack(int size): size_(size) {
  if (size_ <= 0) {
    throw std::domain_error("The size of the Stack must be positive!");
  }
  arr_ = new T[size_];
}

template <typename T>
DynamicStack<T>::~DynamicStack() {
  delete[] arr_;
}

template <typename T>
void DynamicStack<T>::push(T elem) {
  if (n_ == size_) {
    T* new_arr = size_ == 0 ? new T[1] : new T[2*size_];
    for (int i = 0; i < size_; ++i) {
      new_arr[i] = arr_[i];
    }
    delete[] arr_;
    size_ = size_ == 0 ? 1 : size_ * 2;
    arr_ = new_arr;
  } 
  arr_[n_] = elem;
  ++n_; 
}

template <typename T>
T& DynamicStack<T>::pop() {
  if (IsEmpty()) {
    throw std::length_error("The Stack is empty!");
  }
  --n_;
  return arr_[n_];
}

template <typename T>
T& DynamicStack<T>::top() {
  if (IsEmpty()) {
    throw std::length_error("The Stack is empty!");
  }
  return arr_[n_ - 1];
}

template <typename T>
bool DynamicStack<T>::IsEmpty() const {
  return n_ == 0;
}

template <typename T>
bool DynamicStack<T>::IsFull() const {
  return false;
}

template <typename T>
void DynamicStack<T>::SetEmpty() {
  n_ = 0;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_DYNAMIC_STACK_HPP_
