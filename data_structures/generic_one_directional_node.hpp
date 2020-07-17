#ifndef DATA_STRUCTURES_GENERIC_ONE_DIRECTIONAL_NODE_H_
#define DATA_STRUCTURES_GENERIC_ONE_DIRECTIONAL_NODE_H_

namespace data_structures{

template <typename T>
struct OneDirectionalNode{
  OneDirectionalNode(T value){
      this->value = value;
  }
  T value;
  OneDirectionalNode* next;
};

} // namespace data_structures

#endif // DATA_STRUCTURES_GENERIC_ONE_DIRECTIONAL_NODE_H_