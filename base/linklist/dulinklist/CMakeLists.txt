include_directories(Inc)
aux_source_directory(Src SRC_LIST)
message(STATUS ${SRC_LIST})

add_executable(8 ${SRC_LIST})
