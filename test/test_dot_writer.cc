#include <fstream>
#include <iostream>

#include "bst/dot_writer.h"
#include "bst/tree_definitions.h"

int main() {
  bst::Node<int>* root = nullptr;
  root = bst::insert(root, 100);
  int value = 2;
  for (int i = 1; i < 10; ++i) {
    value = -i * value;
    bst::insert(root, value);
  }

  std::cout << "root: " << root->value << "\n";
  std::ofstream myfile("example.dot");
  bst::exportDot(myfile, root);

  return 0;
}
