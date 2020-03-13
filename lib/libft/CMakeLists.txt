project(libft)

set (CMAKE_C_FLAGS_RELEASE "-Wall -O2 ${CMAKE_C_FLAGS_RELEASE}")

set(SRC
        src/ft_atoi_base.c
        src/ft_atoi.c
        src/ft_bzero.c
        src/ft_isalnum.c
        src/ft_isalpha.c
        src/ft_isascii.c
        src/ft_isdigit.c
        src/ft_isprint.c
        src/ft_itoa_base.c
        src/ft_itoa.c
        src/ft_lstadd.c
        src/ft_lstappend.c
        src/ft_lstdel.c
        src/ft_lstdelone.c
        src/ft_lstiter.c
        src/ft_lstlen.c
        src/ft_lstmap.c
        src/ft_lstnew.c
        src/ft_memalloc.c
        src/ft_memccpy.c
        src/ft_memchr.c
        src/ft_memcmp.c
        src/ft_memcpy.c
        src/ft_memdel.c
        src/ft_memmove.c
        src/ft_memset.c
        src/ft_putchar.c
        src/ft_putchar_fd.c
        src/ft_putendl.c
        src/ft_putendl_fd.c
        src/ft_putnbr.c
        src/ft_putnbr_fd.c
        src/ft_putstr.c
        src/ft_putstr_fd.c
        src/ft_sort_str_table.c
        src/ft_strcapitalize.c
        src/ft_strcat.c
        src/ft_strchr.c
        src/ft_strclr.c
        src/ft_strcmp.c
        src/ft_strcpy.c
        src/ft_strdel.c
        src/ft_strdup.c
        src/ft_strequ.c
        src/ft_striter.c
        src/ft_striteri.c
        src/ft_strjoin.c
        src/ft_strlcat.c
        src/ft_strlen.c
        src/ft_strmap.c
        src/ft_strmapi.c
        src/ft_strncat.c
        src/ft_strncmp.c
        src/ft_strncpy.c
        src/ft_strnequ.c
        src/ft_strnew.c
        src/ft_strnstr.c
        src/ft_strrchr.c
        src/ft_strsplit.c
        src/ft_strstr.c
        src/ft_strsub.c
        src/ft_strtrim.c
        src/ft_tolower.c
        src/ft_toupper.c
        src/ft_memjoin.c
        src/get_next_line.c
        src/ft_ceil.c
        src/ft_nbrlen.c
        src/ft_lstd_push_front.c
        src/ft_lstd_pop_front.c
        src/ft_lstd_collapse.c
        src/ft_lstd_del.c
        src/ft_lstd_push_back.c
        src/ft_quick_sort.c
        src/ft_swap.c
        src/ft_tree_new.c
        src/ft_hash.c
        src/ft_hash_del.c
        src/ft_merge_sort.c
        src/ft_max.c src/ft_abs.c src/ft_min.c
        src/ft_new_heap.c
        src/ft_heap_add.c
        src/ft_pop_min_heap.c
        src/ft_heap_merge.c
        src/fast_get_next_line.c
        src/ft_hash_tab.c src/ft_set.c src/ft_set_2.c)
set(HEADERS
        includes/libft.h)

add_library(libft STATIC ${SRC} ${HEADERS})

target_include_directories(libft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})