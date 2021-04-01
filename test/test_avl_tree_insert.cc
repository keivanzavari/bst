#include <fstream>

#include "avl_tree.h"
#include "dot_writer.h"

namespace avl {
void testRightRight() {
  Tree<int> avl_tree{};
  avl_tree.insert(100);

  const int values[] = {80, 105, 115, 102};
  for (const auto value : values) {
    //   // std::cout << "root height: " << y->height << "\n";
    avl_tree.insert(value);
  }
  auto root = avl_tree.get();
  std::ofstream before("right_right_before.dot");
  bst::exportDot(before, root);

  avl_tree.insert(110);
  root = avl_tree.get();
  std::ofstream after("right_right_after.dot");
  bst::exportDot(after, root);
}

void testLeftLeft() {
  Tree<int> avl_tree{};
  avl_tree.insert(100);

  const int values[] = {120, 95, 98, 80};
  for (const auto value : values) {
    //   // std::cout << "root height: " << y->height << "\n";
    avl_tree.insert(value);
  }
  auto root = avl_tree.get();
  std::ofstream before("left_left_before.dot");
  bst::exportDot(before, root);

  avl_tree.insert(90);
  root = avl_tree.get();
  std::ofstream after("left_left_after.dot");
  bst::exportDot(after, root);
}

void testLeftRight() {
  Tree<int> avl_tree{};
  avl_tree.insert(100);

  const int values[] = {120, 80, 95, 98};
  for (const auto value : values) {
    avl_tree.insert(value);
  }
}

void testRightLeft() {
  Tree<int> avl_tree{};
  avl_tree.insert(100);

  const int values[] = {80, 120, 105, 102};
  for (const auto value : values) {
    avl_tree.insert(value);
  }
}

}  // namespace avl
int main() {
  avl::testRightRight();
  avl::testLeftLeft();
  avl::testLeftRight();
  avl::testRightLeft();
  return 0;
}
