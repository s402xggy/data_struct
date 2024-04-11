project(tree)

add_executable(bin_tree_test main.cpp)
target_include_directories(bin_tree_test PRIVATE ${BinTree_Inc_Dir})