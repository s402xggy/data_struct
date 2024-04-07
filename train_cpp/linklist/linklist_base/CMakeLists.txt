include_directories(Inc)
add_library(linklist  Src/link_list_base.cpp )
add_executable(link_list Src/main.cpp Src/link_list_base.cpp)

add_executable(link_list1 Src/main1.cpp Src/link_list_base_cplus.cpp)
