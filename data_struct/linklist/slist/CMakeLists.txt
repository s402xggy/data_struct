project(slist)

add_executable(slist_test main.cpp)
target_include_directories(slist_test PRIVATE ${Slist_Inc_Dir})
