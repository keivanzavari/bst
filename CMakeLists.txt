cmake_minimum_required(VERSION 3.12)
project(bst)

add_definitions(-std=c++17)

include_directories(src)
add_subdirectory(lib/Catch2)

add_executable(test_tree_definitions test/test_tree_definitions.cc)
target_link_libraries(test_tree_definitions PRIVATE Catch2::Catch2)

add_executable(test_dot_writer test/test_dot_writer.cc)
target_link_libraries(test_dot_writer PRIVATE Catch2::Catch2)

add_executable(test_avl_tree_insert test/test_avl_tree_insert.cc)
target_link_libraries(test_avl_tree_insert PRIVATE Catch2::Catch2)
