#ifndef DATA_STRUCTURES_DYNAMIC_STACK_HPP_
#define DATA_STRUCTURES_DYNAMIC_STACK_HPP_

#include <exception>

#include "fixed_stack.hpp"

namespace data_structures {

template <typename T>
class DynamicStack : public FixedStack<T> {
 public:
  explicit DynamicStack(int size): FixedStack<T>::FixedStack(size) {}
  DynamicStack() {}
  // Push elem on the top of the stack
  void push(T elem) override;
  bool IsFull() const override;
};

template <typename T>
void DynamicStack<T>::push(T elem) {
  if (this->n_ == this->size_) {
    T* new_arr = this->size_ == 0 ? new T[1] : new T[2*this->size_];
    for (int i = 0; i < this->size_; ++i) {
      new_arr[i] = this->arr_[i];
    }
    delete[] this->arr_;
    this->size_ = this->size_ == 0 ? 1 : this->size_ * 2;
    this->arr_ = new_arr;
  } 
  this->arr_[this->n_] = elem;
  ++this->n_; 
}

template <typename T>
bool DynamicStack<T>::IsFull() const {
  return false;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_DYNAMIC_STACK_HPP_
