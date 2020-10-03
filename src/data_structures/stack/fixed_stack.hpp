#ifndef DATA_STRUCTURES_FIXED_STACK_HPP_
#define DATA_STRUCTURES_FIXED_STACK_HPP_

#include <exception>

#include "Istack.h"

namespace data_structures {

template <typename T>
class FixedStack : public IStack<T> {
 public:
  explicit FixedStack(int size);
  ~FixedStack() override;
  // Push elem on the top of the stack
  virtual void push(T elem) override;
  // Remove and return the top element of the stack
  T pop() override;
  // Return the top element of the stack
  T& top() override;
  virtual bool IsFull() const override;
  bool IsEmpty() const override;
  void SetEmpty() override;
 protected:
  FixedStack() {};
  int n_ = 0;
  int size_ = 0;
  T* arr_ = nullptr;
};

template <typename T>
FixedStack<T>::FixedStack(int size): size_(size) {
  if (size_ <= 0) {
    throw std::domain_error("The size of the Stack must be positive!");
  }
  arr_ = new T[size_];
}

template <typename T>
FixedStack<T>::~FixedStack() {
  delete[] arr_;
}

template <typename T>
void FixedStack<T>::push(T elem) {
  if (IsFull()) {
    throw std::length_error("The Stack is full!");
  }
  arr_[n_] = elem;
  ++n_;
}

template <typename T>
T FixedStack<T>::pop() {
  if (IsEmpty()) {
    throw std::length_error("The Stack is empty!");
  }
  --n_;
  return arr_[n_];
}

template <typename T>
T& FixedStack<T>::top() {
  if (IsEmpty()) {
    throw std::length_error("The Stack is empty!");
  }
  return arr_[n_ - 1];
}

template <typename T>
bool FixedStack<T>::IsEmpty() const {
  return n_ == 0;
}

template <typename T>
bool FixedStack<T>::IsFull() const {
  return n_ == size_;
}

template <typename T>
void FixedStack<T>::SetEmpty() {
  n_ = 0;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_FIXED_STACK_HPP_
