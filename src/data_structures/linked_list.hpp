#ifndef DATA_STRUCTURES_LINKED_LIST_H_
#define DATA_STRUCTURES_LINKED_LIST_H_

#include "generic_one_directional_node.hpp"

namespace data_structures {

template <typename T>
class OneDirectionalLinkedList {
 public:
  OneDirectionalLinkedList(){}
  ~OneDirectionalLinkedList(){}

  void insert_back(T value);
  
 private:
  OneDirectionalNode<T>* head_;
};

template <typename T>
void OneDirectionalLinkedList<T>::insert_back(T value) {
  OneDirectionalNode<T>* new_node = new OneDirectionalNode<T>(value);
  if(this->head_ == NULL) {
    this->head_ = new_node;
    return;
  }
  OneDirectionalNode<T>* current = this->head_;
  while(current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_LINKED_LIST_H_