#ifndef DATA_STRUCTURES_NODE_SINGLY_LINKED_NODE_HPP_
#define DATA_STRUCTURES_NODE_SINGLY_LINKED_NODE_HPP_

namespace data_structures {

template <typename T>
struct SinglyLinkedNode {
  SinglyLinkedNode(const T& data) : value(data) {}
  T value;
  SinglyLinkedNode* next = nullptr;
};

} // namespace data_structures

#endif // DATA_STRUCTURES_NODE_SINGLY_LINKED_NODE_HPP_
