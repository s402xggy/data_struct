project(slist)

add_executable(slist_test main.cpp)
target_include_directories(slist_test PRIVATE ${Slist_Inc_Dir})

add_executable(merge_slist merge_slist.cpp)
target_include_directories(merge_slist PRIVATE ${Slist_Inc_Dir})

add_executable(delete_repeat delete_repeat.cpp)
target_include_directories(delete_repeat PRIVATE ${Slist_Inc_Dir})

add_executable(find_last find_last.cpp)
target_include_directories(find_last PRIVATE ${Slist_Inc_Dir})

add_executable(reverse_list reverse_list.cpp)
target_include_directories(reverse_list PRIVATE ${Slist_Inc_Dir})

add_executable(josephus josephus.cpp)
target_include_directories(josephus PRIVATE ${Slist_Inc_Dir})