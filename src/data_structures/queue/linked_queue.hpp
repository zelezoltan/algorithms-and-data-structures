#ifndef DATA_STRUCTURES_QUEUE_LINKED_QUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_LINKED_QUEUE_HPP_

#include "Iqueue.h"
#include "../linked_list/singly_linked_list.hpp"

namespace data_structures {

template <typename T>
class LinkedQueue : public IQueue<T> {
 public:
  void add(const T& elem);
  T rem();
  T& first();
  int length() const;
  bool IsFull() const;
  bool IsEmpty() const;
  void SetEmpty();
 private:
  SinglyLinkedList<T> list_;
};

template <typename T>
void LinkedQueue<T>::add(const T& elem) {
  if (!IsFull()) {
    list_.push_back(elem);
  }
}

template <typename T>
T LinkedQueue<T>::rem() {
  if (!IsEmpty()) {
    return list_.pop_front();
  }
}

template <typename T>
T& LinkedQueue<T>::first() {
  return list_.front();
}

template <typename T>
int LinkedQueue<T>::length() const {
  return list_.size();
}

template <typename T>
bool LinkedQueue<T>::IsFull() const {
  return list_.IsFull();
}

template <typename T>
bool LinkedQueue<T>::IsEmpty() const {
  return list_.IsEmpty();
}

template <typename T>
void LinkedQueue<T>::SetEmpty() {
  list_.SetEmpty();
}

} // namespace data_structures

#endif // DATA_STRUCTURES_QUEUE_LINKED_QUEUE_HPP_
