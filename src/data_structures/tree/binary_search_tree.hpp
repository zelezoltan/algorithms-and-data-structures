#ifndef DATA_STRUCTURES_TREE_BINARY_SEARCH_TREE_HPP_
#define DATA_STRUCTURES_TREE_BINARY_SEARCH_TREE_HPP_

#include "../node/binary_tree_node.hpp"

namespace data_structures {

template <typename T>
class BinarySearchTree {
 public:
  using Node = BinaryTreeNode<T>;

  BinarySearchTree() {}
  ~BinarySearchTree();
  Node* search(T data) { return SearchHelper(root, data); }
  void insert(T data) { Inserthelper(root, data); }
  Node* min();
  Node* RemoveMin() { return RemoveMinHelper(root); }
  void del(T data) { DelHelper(root, data); }
 private:
  Node* SearchHelperRecursive(Node* node, T data);
  Node* SearchHelper(Node* node, T data);
  void InsertHelper(Node*& node, T data);
  Node* RemoveMinHelper(Node*& node);
  void DelHelper(Node*& node, T data);
  void DelRoot(Node*& node);
  void DeleteNodesHelper(Node*& node);
  void DeleteNodes() { DeleteNodesHelper(root); }

  Node* root = nullptr;
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  DeleteNodes();
}

template <typename T>
void BinarySearchTree<T>::DeleteNodesHelper(Node*& node) {
  if (node == nullptr) return;
  DeleteNodesHelper(node->left);
  DeleteNodesHelper(node->right);
  delete node;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::SearchHelperRecursive(
    Node* node, T data) {
  if (node == nullptr) return nullptr;
  if (node->data == data) return node;
  if (node->data > data) return SearchHelperRecursive(node->left, data);
  return SearchHelperRecursive(node->right, data);
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::SearchHelper(
    Node* node, T data) {
  while (node != nullptr && node->data != data) {
    if (node->data > data) node = node->left;
    else node = node->right;
  }
  return node;
}

template <typename T>
void BinarySearchTree<T>::InsertHelper(Node*& node, T data) {
  if (node == nullptr) {
    node = new Node(data);
  } else {
    if (data == node->data) return;
    else if (data > node->data) InsertHelper(node->right, data);
    else InsertHelper(node->left, data);
  }
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::min() {
  Node* node = root;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return node;
}

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::RemoveMinHelper(
    Node*& node) {
  if (node->left == nullptr) {
    Node* min = node;
    node = node->right;
    min->right = nullptr;
    return min;
  } else {
    return RemoveMinHelper(node->left);
  }
}

template <typename T>
void BinarySearchTree<T>::DelHelper(Node*& node, T data) {
  if (node == nullptr) return;
  if (data > node->data) DelHelper(node->right);
  else if (data < node->data) DelHelper(node->left);
  else if (data == node->data) DelRoot(node);
}

template <typename T>
void BinarySearchTree<T>::DelRoot(Node*& node) {
  Node* temp = node;
  if (node->left == nullptr) {
    node = node->right;
  } else if (node->right == nullptr) {
    node = node->left;
  } else {
    Node* min_in_right = RemoveMinHelper(node->right);
    min_in_right->left = node->left;
    min_in_right->right = node->right;
    node = min_in_right;
  }
  delete temp;
}

} // namespace data_structures

#endif // DATA_STRUCTURES_TREE_BINARY_SEARCH_TREE_HPP_