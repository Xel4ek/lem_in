# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:24:49 by hwolf             #+#    #+#              #
#    Updated: 2019/10/26 17:42:42 by hwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -pipe -O2
SRC =	ft_atoi_base.c \
        ft_atoi.c \
        ft_bzero.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_itoa_base.c \
        ft_itoa.c \
        ft_lstadd.c \
        ft_lstappend.c \
        ft_lstdel.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstlen.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_memalloc.c \
        ft_memccpy.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memdel.c \
        ft_memmove.c \
        ft_memset.c \
        ft_putchar.c \
        ft_putchar_fd.c \
        ft_putendl.c \
        ft_putendl_fd.c \
        ft_putnbr.c \
        ft_putnbr_fd.c \
        ft_putstr.c \
        ft_putstr_fd.c \
        ft_sort_str_table.c \
        ft_strcapitalize.c \
        ft_strcat.c \
        ft_strchr.c \
        ft_strclr.c \
        ft_strcmp.c \
        ft_strcpy.c \
        ft_strdel.c \
        ft_strdup.c \
        ft_strequ.c \
        ft_striter.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_strlcat.c \
        ft_strlen.c \
        ft_strmap.c \
        ft_strmapi.c \
        ft_strncat.c \
        ft_strncmp.c \
        ft_strncpy.c \
        ft_strnequ.c \
        ft_strnew.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_strsplit.c \
        ft_strstr.c \
        ft_strsub.c \
        ft_strtrim.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_memjoin.c \
        get_next_line.c \
        ft_ceil.c \
        ft_nbrlen.c \
        ft_lstd_push_front.c \
        ft_lstd_pop_front.c \
        ft_lstd_collapse.c \
        ft_lstd_del.c \
        ft_lstd_push_back.c \
        ft_quick_sort.c \
        ft_swap.c \
        ft_tree_new.c \
        ft_hash.c \
        ft_hash_del.c \
        ft_merge_sort.c \
        ft_max.c \
        ft_abs.c \
        ft_min.c \
		ft_new_heap.c \
		ft_heap_add.c \
		ft_pop_min_heap.c \
		ft_heap_merge.c \
		fast_get_next_line.c \
		ft_hash_tab.c \
		ft_set.c \
		ft_set_2.c
#        ft_printf_src/apply_flags.c \
#        ft_printf_src/data.c \
#        ft_printf_src/e_double.c \
#        ft_printf_src/e_double_tool.c \
#        ft_printf_src/f_double.c \
#        ft_printf_src/ft_printf.c \
#        ft_printf_src/int_funcions.c \
#        ft_printf_src/parse.c \
#        ft_printf_src/parse_tool.c \
#        ft_printf_src/print_tool.c \
#        ft_printf_src/string_tool.c \
#        ft_printf_src/tools.c \



SRCDIR = src
OBJDIR = obj
HEADERS = includes
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
HEADER  = libft.h libft_structs.h


.PHONY: all clean fclean re help

all: $(NAME)

help:
	@echo "Usage :"
	@echo "\tmake //create library"
	@echo "\tmake clean // remove *.o files"
	@echo "\tmake flean //remove *.o files and library"
	@echo "\tmake re // recreation library"

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean  all


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(HEADERS)/, $(HEADER))
	$(CC) $(CFLAGS) -I$(HEADERS) -o $@ -c $<


$(NAME): $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
