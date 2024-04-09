project(queue)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
# add_library(queuelib STATIC ${Queue_Inc_Dir}/queue.hpp)

add_executable(queue_test main.cpp)
target_include_directories(queue_test PRIVATE ${Queue_Inc_Dir})

add_executable(decode decode.cpp)
target_include_directories(decode PRIVATE ${Queue_Inc_Dir})

add_executable(d_palindorm d_palindorm.cpp)
target_include_directories(d_palindorm PRIVATE ${Queue_Inc_Dir})