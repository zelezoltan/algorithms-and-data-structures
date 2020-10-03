#ifndef DATA_STRUCTURES_NODE_DOUBLY_LINKED_NODE_HPP_
#define DATA_STRUCTURES_NODE_DOUBLY_LINKED_NODE_HPP_

namespace data_structures {

template <typename T>
struct DoublyLinkedNode {
  DoublyLinkedNode(T data) : value(data) {}

  T value;
  DoublyLinkedNode* next = nullptr;
  DoublyLinkedNode* prev = nullptr;
};

} // namespace data_structures

#endif // DATA_STRUCTURES_NODE_DOUBLY_LINKED_NODE_HPP_
