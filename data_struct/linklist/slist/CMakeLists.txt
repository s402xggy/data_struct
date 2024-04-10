project(slist)

add_executable(slist_test main.cpp)
target_include_directories(slist_test PRIVATE ${Slist_Inc_Dir})

add_executable(merge_slist merge_slist.cpp)
target_include_directories(merge_slist PRIVATE ${Slist_Inc_Dir})

add_executable(delete_repeat delete_repeat.cpp)
target_include_directories(delete_repeat PRIVATE ${Slist_Inc_Dir})