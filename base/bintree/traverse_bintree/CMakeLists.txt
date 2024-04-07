include_directories(Inc)
add_subdirectory(level_traverse)
aux_source_directory(Src SRC_LIST)
message(STATUS ${SRC_LIST})

add_executable(bin_tree_2 ${SRC_LIST})
