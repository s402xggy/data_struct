include_directories(Inc)
aux_source_directory(Src SRC_LIST)
message(STATUS ${SRC_LIST})

add_executable(bin_tree_3 ${SRC_LIST})
