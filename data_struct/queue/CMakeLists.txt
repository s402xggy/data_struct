project(queue)


add_executable(queue_test main.cpp)
target_include_directories(queue_test PRIVATE ${Queue_Inc_Dir})