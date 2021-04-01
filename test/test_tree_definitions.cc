#include <fstream>

#include "dot_writer.h"
#include "tree_definitions.h"
namespace bst {
void testRightRotation() {
  /**
   *       y                                 x
   *     /  \     Right Rotation           /   \
   *    x    T3   - - - - - - - ->        T1    y
   *  /  \       <- - - - - - - -             /  \
   * T1  T2     Left Rotation              T2    T3
   */
  Node<int>* root = nullptr;
  Node<int>* y = insert(root, 100);
  for (const auto value : {70, 90, 65, 110}) {
    y = insert(y, value);
  }
  std::cout << "root height: " << y->height << "\n";

  std::ofstream before("right_rotation_before.dot");
  int before_counter = exportDot(before, y);

  root = rightRotate(y);
  std::ofstream after("right_rotation_after.dot");
  int after_counter = exportDot(after, root);

  std::cout << "number of nodes before: " << before_counter << ", after: " << after_counter << "\n";

  delete y;
}

void testLeftRotation() {
  /**
   *       y                                 x
   *     /  \     Right Rotation           /   \
   *    x    T3   - - - - - - - ->        T1    y
   *  /  \       <- - - - - - - -             /  \
   * T1  T2     Left Rotation              T2    T3
   */
  Node<int>* root = nullptr;
  Node<int>* x = insert(root, 80);
  for (const auto value : {70, 90, 85, 110}) {
    x = insert(x, value);
  }

  std::cout << "root height: " << x->height << "\n";
  std::ofstream before("left_rotation_before.dot");
  int before_counter = exportDot(before, x);

  root = leftRotate(x);
  std::ofstream after("left_rotation_after.dot");
  int after_counter = exportDot(after, root);

  std::cout << "number of nodes before: " << before_counter << ", after: " << after_counter << "\n";

  delete x;
}

void testInsert() {
  Node<int>* root = nullptr;
  Node<int>* x = insert(root, 80);
  for (const auto value : {81, 70, 90, 85, 120, 105, 130, 110}) {
    x = insert(x, value);
  }
  std::cout << "root height: " << x->height << "\n";
}

void testFindMin() {
  Node<int>* root = nullptr;
  Node<int>* x = insert(root, 80);
  for (const auto value : {81, 70, 90, 85, 50, 105, 130, 110}) {
    x = insert(x, value);
  }
  std::cout << "root height: " << x->height << "\n";
  auto min_node = findMin(x);
  std::cout << "min value: " << min_node->value << "\n";
}

}  // namespace bst

int main() {
  bst::testFindMin();
  // bst::testInsert();
  // bst::testRightRotation();
  // bst::testLeftRotation();
  return 0;
}
