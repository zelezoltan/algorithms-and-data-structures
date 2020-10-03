#ifndef DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST
#define DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST

#include <limits>

#include "../node/singly_linked_node.hpp"

namespace data_structures {

template <typename T>
class SinglyLinkedList {
 public:
  using node_type = SinglyLinkedNode<T>;
  using size_type = unsigned long long;

  SinglyLinkedList() {};
  ~SinglyLinkedList();
  void push_front(const T& data);
  void insert(const T& data, size_type position);
  void push_back(const T& data);
  T pop_front();
  T& front() { return head_->value; }
  T& back() { return tail_->value; }
  // T pop_back();
  size_type size() const { return size_; }
  bool IsFull() const;
  bool IsEmpty() const;
  void SetEmpty();
 private:
  void DeleteNodes();
  node_type* Allocate(const T& data);

  node_type* head_ = nullptr;
  node_type* tail_ = nullptr;
  size_type size_ = 0;
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  DeleteNodes();
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& data) {
  // If the list is full then we don't do anything
  if (!IsFull()) {
    node_type* new_node = Allocate(data);
    // Could not allocate
    if (new_node == nullptr) return;
    if (IsEmpty()) {
      head_ = tail_ = new_node;
    } else {
      new_node->next = head_;
      head_ = new_node;
    }
    ++size_;
  }
}

template <typename T>
void SinglyLinkedList<T>::insert(const T& data, size_type position) {
  if (position == 0) {
    push_front(data);
  } else if (position == size_) {
    push_back(data);
  // out of bounds
  } else if (position > size_) {
    return;
  } else {
    if (!IsFull()) {
      node_type* new_node = Allocate(data);
      if (new_node == nullptr) return;
      node_type* current = head_;
      while (position > 1) {
        current = current->next;
        --position;
      }
      new_node->next = current->next;
      current->next = new_node;
      ++size_;
    }
  }
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& data) {
  // If the list is full then we don't do anything
  if (!IsFull()) {
    node_type* new_node = Allocate(data);
    // Could not allocate
    if (new_node == nullptr) return;
    if (IsEmpty()) {
      head_ = tail_ = new_node;
    } else {
      tail_->next = new_node;
      tail_ = tail_->next;
    }
    ++size_;
  }
}

template <typename T>
T SinglyLinkedList<T>::pop_front() {
  if (!IsEmpty()) {
    node_type* node_to_delete = head_;
    T data = node_to_delete->value;
    head_ = head_->next;
    delete node_to_delete;
    --size_;
    return data;
  }
}

template <typename T>
bool SinglyLinkedList<T>::IsEmpty() const {
  return size_ == 0;
}

template <typename T>
bool SinglyLinkedList<T>::IsFull() const {
  return size_ == std::numeric_limits<size_type>::max();
}

template <typename T>
void SinglyLinkedList<T>::SetEmpty() {
  DeleteNodes();
  size_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::DeleteNodes() {
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
typename SinglyLinkedList<T>::node_type* SinglyLinkedList<T>::Allocate(
    const T& data) {
  node_type* new_node;
  // If we can't allocate memory then return nullptr
  try {
    new_node = new node_type(data);
  } catch (...) {
    return nullptr;
  }
  return new_node;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST
