#ifndef DATA_STRUCTURES_STACK_LINKED_STACK_HPP_
#define DATA_STRUCTURES_STACK_LINKED_STACK_HPP_

#include <limits>

#include "Istack.h"
#include "../linked_list/singly_linked_list.hpp"

namespace data_structures {

template <typename T>
class LinkedStack : public IStack<T> {
 public:
  using size_type = typename SinglyLinkedList<T>::size_type;

  void push(T elem) override;
  T pop() override;
  T& top() override;
  bool IsEmpty() const override;
  bool IsFull() const override;
  void SetEmpty() override;
 private:
  SinglyLinkedList<T> list_;
};

template <typename T>
void LinkedStack<T>::push(T elem) {
  if (!IsFull()) {
    list_.push_front(elem);
  }
}

template <typename T>
T LinkedStack<T>::pop() {
  if (!IsEmpty()) {
    return list_.pop_front();
  }
}

template <typename T>
T& LinkedStack<T>::top() {
  if (IsEmpty()) {
    throw std::length_error("The stack is empty!");
  }
  return list_.front();
}

template <typename T>
bool LinkedStack<T>::IsFull() const {
  return list_.IsFull();
}

template <typename T>
bool LinkedStack<T>::IsEmpty() const {
  return list_.IsEmpty();
}

template <typename T>
void LinkedStack<T>::SetEmpty() {
  list_.SetEmpty();
}

} // namespace data_structures

#endif // DATA_STRUCTURES_STACK_LINKED_STACK_HPP_