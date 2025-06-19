include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(merge_sort_test merge_sort.c)
target_link_libraries(merge_sort_test sort)
add_test(NAME merge_sort COMMAND merge_sort_test)

add_executable(quick_sort_test quick_sort.c)
target_link_libraries(quick_sort_test sort)
add_test(NAME quick_sort COMMAND quick_sort_test)
