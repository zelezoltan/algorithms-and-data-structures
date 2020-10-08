#ifndef DATA_STRUCTURES_NODE_BINARY_TREE_NODE_HPP_
#define DATA_STRUCTURES_NODE_BINARY_TREE_NODE_HPP_

namespace data_structures {

template <typename T>
struct BinaryTreeNode {
  T data;
  BinaryTreeNode* left = nullptr;
  BinaryTreeNode* right = nullptr;

  BinaryTreeNode() {}
  BinaryTreeNode(T value) : data(value) {}
};

} // namespace data_structures

#endif // DATA_STRUCTURES_NODE_BINARY_TREE_NODE_HPP_