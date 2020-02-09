cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)
set(SRC
        src/main.c src/ft_print_matrix.c src/ft_set_edge.c src/ft_new_edge.c src/ft_new_vertex.c src/ft_set_vertex.c src/ft_print_tools.c)


include_directories(lib/libft/includes)
include_directories(includes)

add_executable(lem_in ${SRC})

add_subdirectory(lib/libft)
target_link_libraries(lem_in libft)