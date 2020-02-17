cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)
set(SRC
        src/ft_print_matrix.c
        src/ft_set_edge.c
        src/ft_new_edge.c
        src/ft_new_vertex.c
        src/ft_set_vertex.c
        src/ft_print_tools.c
        src/test_graph.c
        src/ft_print_graph.c
        src/ft_add_edge.c
        src/ft_print_egde_list.c
        src/ft_print_edge.c
        src/ft_add_vertex.c
        src/ft_split_egde.c
        src/fr_remove_egde.c
        src/ft_split_vertex.c
        src/ft_remove_vertex.c
        src/ft_move_edge.c
        src/ft_convert_graph.c
        src/ft_grahp_dfs.c
        src/ft_queue_pop.c
        src/ft_save_as_dot.c
        src/ft_queue_new.c
        src/ft_spllit_all_graph_edge.c src/ft_reset_edge_oriented.c src/ft_reverse_edge.c
        src/read_map.c)


include_directories(lib/libft/includes)
include_directories(includes)

add_executable(lem_in ${SRC} src/main.c)
add_executable(test_str_len test_str_len.c)
add_executable(short_test ${SRC} src/short_test.c)
add_executable(read_map ${SRC} src/read_only.c)

add_subdirectory(lib/libft)
target_link_libraries(lem_in libft)
target_link_libraries(test_str_len libft)
target_link_libraries(short_test libft)
target_link_libraries(read_map libft)