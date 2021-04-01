#pragma once

#include "tree_definitions.h"

namespace avl {

template <typename T>
class Tree {
 public:
  Tree() : root(nullptr) {}
  void insert(const T value) {
    root = bst::insert(root, value);
    balanceTree();
  }

  bst::Node<T>* get() { return root; }

 private:
  void balanceTree() {
    int balance_factor = getBalance(root);
    if (balance_factor == 0 || balance_factor == 1 || balance_factor == -1) {
      // these are all good cases we don't need to do anything else.
      // std::cout << "good case, balance didn't break.\n";
      return;
    }

    if (balance_factor > 1) {
      // left case is when balance factor is positive. left is longer than right.
      auto left = root->left;
      if (bst::getHeight(left->left) > bst::getHeight(left->right)) {
        // if the height of the right child is greater than the height of the left child, then we have a right right
        // case.
        root = bst::balanceLeftLeft(root);
      } else {
        // left, right case.
        root = bst::balanceLeftRight(root);
      }
    } else if (balance_factor < 1) {
      // right case is when balance factor is negative. right is longer than left.
      auto right = root->right;
      if (bst::getHeight(right->right) > bst::getHeight(right->left)) {
        // if the height of the right child is greater than the height of the left child, then we have a right right
        // case.
        root = bst::balanceRightRight(root);
      } else {
        // right, left case.
        root = bst::balanceRightLeft(root);
      }
    }
  }

  int getBalance(bst::Node<T>* node) {
    if (!node) {
      return 0;
    }
    return bst::getHeight(node->left) - bst::getHeight(node->right);
  }

  bst::Node<T>* root;
};

}  // namespace avl
