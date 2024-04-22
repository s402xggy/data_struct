project(search)

add_executable(sqsearch sqsearch.cpp)

add_executable(bstree bstree.cpp)
target_include_directories(bstree PRIVATE ${Bstree_Inc_Dir} ${Queue_Inc_Dir})

add_executable(avltree avltree.cpp)
target_include_directories(avltree PRIVATE ${Bstree_Inc_Dir} ${Queue_Inc_Dir})

add_executable(hash hash.cpp)
target_include_directories(hash PRIVATE ${Bstree_Inc_Dir} ${Queue_Inc_Dir})