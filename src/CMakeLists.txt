add_library(sort sort.c)
add_library(graph bst.c stack.c rbt.c)
add_executable(algos main.c)
target_link_libraries(algos sort graph)
