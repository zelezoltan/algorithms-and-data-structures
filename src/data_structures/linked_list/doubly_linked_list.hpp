#ifndef DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_HPP_
#define DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_HPP_

#include <limits>

#include "../node/doubly_linked_node.hpp"

namespace data_structures {

template <typename T>
class DoublyLinkedList {
 public:
  using node_type = DoublyLinkedNode<T>;
  using size_type = unsigned long long;

  DoublyLinkedList() {}
  ~DoublyLinkedList();
  void push_front(const T& value);
  void push_back(const T& value);
  void insert(const T& value, size_type position);
  T& front() { return head_->value; }
  T& back() { return tail_->value; }
  T pop_front();
  T pop_back();
  bool IsEmpty() const { return size_ == 0; }
  bool IsFull() const;
  void SetEmpty();
 private:
  node_type* Allocate(const T& value);
  void DeleteNodes();

  node_type* head_ = nullptr;
  node_type* tail_ = nullptr;
  size_type size_ = 0;
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  DeleteNodes();
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
  if (!IsFull()) {
    node_type* new_node = Allocate(value);
    if (new_node == nullptr) return;
    if (IsEmpty()) {
      head_ = tail_ = new_node;
    } else {
      new_node->next = head_;
      head_->prev = new_node;
      head_ = new_node;
    }
    ++size_;
  }
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  if (!IsFull()) {
    node_type* new_node = Allocate(value);
    if (new_node == nullptr) return;
    if (IsEmpty()) {
      head_ = tail_ = new_node;
    } else {
      new_node->prev = tail_;
      tail_->next = new_node;
      tail_ = new_node;
    }
    ++size_;
  }
}

template <typename T>
void DoublyLinkedList<T>::insert(const T& value, size_type position) {
  if (position == 0) {
    push_front(value);
  } else if (position == size_) {
    push_back(value);
  } else if (position > size_) {
    return;
  } else {
    if (!IsFull()) {
      // TODO: if position is in the second half, go from the back
      node_type* new_node = Allocate(value);
      if (new_node == nullptr) return;
      node_type* current = head_;
      while (position > 1) {
        current = current->next;
      }
      new_node->next = current->next;
      new_node->prev = current;
      current->next = new_node;
      ++size_;
    }
  }
}

template <typename T>
T DoublyLinkedList<T>::pop_front() {
  if (!IsEmpty()) {
    node_type* node_to_delete = head_;
    T value = node_to_delete->value;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    }
    delete node_to_delete;
    --size_;
    return value;
  }
}

template <typename T>
T DoublyLinkedList<T>::pop_back() {
  if (!IsEmpty()) {
    node_type* node_to_delete = tail_;
    T value = node_to_delete->value;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    }
    delete node_to_delete;
    --size_;
    return value;
  }
}

template <typename T>
bool DoublyLinkedList<T>::IsFull() const {
  return size_ == std::numeric_limits<size_type>::max();
}

template <typename T>
void DoublyLinkedList<T>::SetEmpty() {
  DeleteNodes();
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

template <typename T>
void DoublyLinkedList<T>::DeleteNodes() {
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
typename DoublyLinkedList<T>::node_type* DoublyLinkedList<T>::Allocate(
    const T& value) {
  node_type* new_node;
  try {
    new_node = new node_type(value);
  } catch (...) {
    return nullptr;
  }
  return new_node;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_LINKED_LIST_DOUBLY_LINKED_LIST_HPP_