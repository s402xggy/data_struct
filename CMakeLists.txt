cmake_minimum_required(VERSION 3.23)
project(data_struct)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)


set(Stack_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/stack/include)
set(Queue_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/queue/include)
set(Slist_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/linklist/slist/include)
set(BinTree_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/tree/include)
set(Bstree_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/search/include)
set(Sort_Inc_Dir ${PROJECT_SOURCE_DIR}/data_struct/sort/include)


add_subdirectory(data_struct)
