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
        src/ft_remove_egde.c
        src/ft_split_vertex.c
        src/ft_remove_vertex.c
        src/ft_convert_graph.c
        src/ft_min_cost_flow.c
        src/ft_queue_pop.c
        src/ft_save_as_dot.c
        src/ft_queue_new.c
        src/ft_spllit_all_graph_edge.c src/ft_reset_edge_oriented.c src/ft_reverse_edge.c
        src/ft_squeeze_graph.c src/ft_set_path.c src/ft_push_ant.c src/ft_find_shortest_path.c src/ft_add_ant.c src/ft_set_ant_to_pash.c
        src/ft_char_in_str.c
        src/ft_count_char.c
        src/ft_find_vertex.c
        src/ft_get_ants_count.c
        src/ft_add_line.c
        src/ft_get_edges.c
        src/ft_get_graph.c
        src/ft_get_vertex.c
        src/ft_get_valid_nbr.c
        src/ft_print_map.c
        src/ft_add_to_hash.c
        src/ft_find_in_hash.c
        src/ft_add_and_return_vertex.c
        src/ft_delete_hash.c
        src/ft_check_n_add_edge.c
        src/ft_init_hash.c
        src/ft_accept_new_path.c src/ft_new_path_list.c src/ft_accept_path.c src/ft_get_pash_len.c src/ft_del_graph.c
        src/ft_remove_zero_flow.c)


include_directories(lib/libft/includes)
include_directories(includes)

add_executable(lem_in ${SRC} src/main.c)
add_executable(test_str_len  test_str_len.c)
add_executable(short_test  ${SRC} src/short_test.c)


add_subdirectory(lib/libft)
target_link_libraries(lem_in libft)
target_link_libraries(test_str_len libft)
target_link_libraries(short_test libft)
