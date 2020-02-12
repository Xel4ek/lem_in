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
        src/ft_add_vertex.c src/ft_split_egde.c src/fr_remove_egde.c src/ft_split_vertex.c src/ft_remove_vertex.c src/ft_move_edge.c src/ft_convert_graph.c src/ft_grahp_dfs.c src/ft_queue_pop.c)


include_directories(lib/libft/includes)
include_directories(includes)

add_executable(lem_in ${SRC} src/main.c)
add_executable(test_str_len test_str_len.c)

add_subdirectory(lib/libft)
target_link_libraries(lem_in libft)
target_link_libraries(test_str_len libft)