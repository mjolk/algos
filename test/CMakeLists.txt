include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(merge_sort_test merge_sort.c)
target_link_libraries(merge_sort_test sort)
add_test(NAME merge_sort COMMAND merge_sort_test)

add_executable(quick_sort_test quick_sort.c)
target_link_libraries(quick_sort_test sort)
add_test(NAME quick_sort COMMAND quick_sort_test)

add_executable(count_sort_test count_sort.c)
target_link_libraries(count_sort_test sort)
add_test(NAME count_sort COMMAND count_sort_test)

add_executable(insert_sort_test insert_sort.c)
target_link_libraries(insert_sort_test sort)
add_test(NAME insert_sort COMMAND insert_sort_test)

add_executable(radix_sort_test radix_sort.c)
target_link_libraries(radix_sort_test sort)
add_test(NAME radix_sort COMMAND radix_sort_test)

add_executable(heap_sort_test heap_sort.c)
target_link_libraries(heap_sort_test sort)
add_test(NAME heap_sort COMMAND heap_sort_test)

add_executable(bst_test bst.c)
target_link_libraries(bst_test graph)
add_test(NAME bst COMMAND bst_test)

add_executable(stack_test stack.c)
target_link_libraries(stack_test graph)
add_test(NAME stack COMMAND stack_test)

add_executable(rbt_test rbt.c)
target_link_libraries(rbt_test graph)
add_test(NAME rbt COMMAND rbt_test)
