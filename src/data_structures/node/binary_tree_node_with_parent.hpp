#ifndef DATA_STRUCTURES_NODE_BINARY_TREE_NODE_WITH_PARENT_HPP_
#define DATA_STRUCTURES_NODE_BINARY_TREE_NODE_WITH_PARENT_HPP_

namespace data_structures {

template <typename T>
struct BinaryTreeNodeWithParent {
  T data;
  BinaryTreeNodeWithParent* left = nullptr;
  BinaryTreeNodeWithParent* right = nullptr;
  BinaryTreeNodeWithParent* parent = nullptr;

  BinaryTreeNodeWithParent() {}
  BinaryTreeNodeWithParent(T value) : data(value) {}
  BinaryTreeNodeWithParent(T value, BinaryTreeNodeWithParent* parent_) : data(value), parent(parent_) {}
};

} // namespace data_structures

#endif // DATA_STRUCTURES_NODE_BINARY_TREE_NODE_WITH_PARENT_HPP_