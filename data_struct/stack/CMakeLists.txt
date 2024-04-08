project(stack)

add_executable(stack_main main.cpp src/stack.cpp)
target_include_directories(stack_main PRIVATE ${Stack_Inc_Dir})

add_executable(reverse_polish reverse_polish.cpp src/stack.cpp)
target_include_directories(reverse_polish PRIVATE ${Stack_Inc_Dir})

add_executable(mid_to_last mid_to_last.cpp src/stack.cpp)
target_include_directories(mid_to_last PRIVATE ${Stack_Inc_Dir})

add_executable(paren_match paren_match.cpp src/stack.cpp)
target_include_directories(paren_match PRIVATE ${Stack_Inc_Dir})

add_executable(dec_to_bin dec_to_bin.cpp src/stack.cpp)
target_include_directories(dec_to_bin PRIVATE ${Stack_Inc_Dir})

add_executable(palindrom palindrom.cpp src/stack.cpp)
target_include_directories(palindrom PRIVATE ${Stack_Inc_Dir})

