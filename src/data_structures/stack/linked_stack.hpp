#ifndef DATA_STRUCTURES_STACK_LINKED_STACK_HPP_
#define DATA_STRUCTURES_STACK_LINKED_STACK_HPP_

#include <limits>
#include <exception>

#include "Istack.h"
#include "../node/singly_linked_node.hpp"

namespace data_structures {

template <typename T>
class LinkedStack : public IStack<T> {
 public:
  using size_type = unsigned long long;
  using node_type = SinglyLinkedNode<T>;

  LinkedStack() {}
  ~LinkedStack();
  void push(T elem) override;
  T pop() override;
  T& top() override;
  bool IsEmpty() const override;
  bool IsFull() const override;
  void SetEmpty() override;
 private:
  void DeleteNodes();
  // TODO: Use a linked list implementation
  node_type* head_ = nullptr;
  size_type size_ = 0;
};

template <typename T>
void LinkedStack<T>::DeleteNodes() {
  if (!IsEmpty()) {
    node_type* node_to_delete = head_;
    while (head_ != nullptr) {
      head_ = head_->next;
      delete node_to_delete;
      node_to_delete = head_;
    }
  }
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
  DeleteNodes();
}

template <typename T>
void LinkedStack<T>::push(T elem) {
  if (!IsFull()) {
    // Throws bad alloc if it couldn't allocate memory
    node_type* new_node = new node_type(elem);
    if (IsEmpty()) {
      head_ = new_node;
    } else {
      new_node->next = head_;
      head_ = new_node;
    }
    ++size_;
  } else {
    throw std::length_error("The stack is full!");
  }
}

template <typename T>
T LinkedStack<T>::pop() {
  if (IsEmpty()) {
    throw std::length_error("The stack is empty!");
  }
  node_type* node_to_delete = head_;
  head_ = head_->next;
  --size_;
  T data = node_to_delete->value;
  delete node_to_delete;
  return data;
}

template <typename T>
T& LinkedStack<T>::top() {
  if (IsEmpty()) {
    throw std::length_error("The stack is empty!");
  }
  return head_->value;
}

template <typename T>
bool LinkedStack<T>::IsFull() const {
  return size_ == std::numeric_limits<size_type>::max();
}

template <typename T>
bool LinkedStack<T>::IsEmpty() const {
  return size_ == 0;
}

template <typename T>
void LinkedStack<T>::SetEmpty() {
  DeleteNodes();
  size_ = 0;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_STACK_LINKED_STACK_HPP_