cmake_minimum_required(VERSION 3.1)
project(bst)

include_directories(src)
add_subdirectory(lib/Catch2)

add_executable(test_dot_writer test/test_dot_writer.cc)
target_link_libraries(test_dot_writer PRIVATE Catch2::Catch2)
