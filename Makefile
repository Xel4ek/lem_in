# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayooden <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 14:59:34 by ayooden           #+#    #+#              #
#    Updated: 2020/02/05 14:59:36 by ayooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=   src/ft_add_edge.c \
                    src/ft_add_vertex.c \
                    src/ft_split_egde.c \
                    src/ft_remove_egde.c \
                    src/ft_split_vertex.c \
                    src/ft_remove_vertex.c \
                    src/ft_convert_graph.c \
                    src/ft_min_cost_flow.c \
                    src/ft_new_edge.c \
                    src/ft_new_vertex.c \
                    src/ft_reverse_edge.c \
                    src/ft_set_path.c \
                    src/ft_push_ant.c \
                    src/ft_set_ant_to_pash.c \
                    src/ft_char_in_str.c \
                    src/ft_count_char.c \
                    src/ft_get_ants_count.c \
                    src/ft_get_edges.c \
                    src/ft_get_graph.c \
                    src/ft_get_vertex.c \
                    src/ft_get_valid_nbr.c \
                    src/ft_get_next_pointer.c \
                    src/ft_init_graph.c \
                    src/ft_init_memory.c \
                    src/ft_print_error.c \
                    src/ft_new_path_list.c \
                    src/ft_accept_path.c \
                    src/ft_get_pash_len.c \
                    src/ft_del_graph.c \
                    src/ft_remove_zero_flow.c \
                    src/ft_set_insert_vertex.c \
                    src/main.c

SRCDIR          =   src

OBJDIR          =   obj

OBJ				=	$(SRC:.c=.o)

LIBFTDIR		=	lib/libft/ lib/ft_printf/

INCL			=	-Iincludes/ -Ilib/libft/includes -Ilib/ft_printf/includes

CFLAGS			=	-Wall -Werror -Wextra

NAME			=	lem-in

LFTFLAG			=	-Llib/libft/ -Llib/ft_printf/ -lft -lftprintf

LFT				=	lib/libft/libft.a lib/ft_printf/libftprintf.a

DEPS			=	includes/lem_in.h

CC              =   clang

LIB_FT_ALL      =   $(addsuffix .all,$(LIBFTDIR))
LIB_FT_CLEAN    =   $(addsuffix .clean,$(LIBFTDIR))
LIB_FT_FCLEAN   =   $(addsuffix .fclean,$(LIBFTDIR))

.PHONY: all clean fclean re

all: $(LIB_FT_ALL) $(NAME)

%.o:%.c $(DEPS)
	            $(CC) $(CFLAGS) $(INCL) -c $< -o $@

$(LFT):
				@$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LFT) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(INCL) $(LFTFLAG) -o $(NAME)

clean: $(LIB_FT_CLEAN)
				rm -f $(OBJ)

fclean:	$(LIB_FT_FCLEAN)
				rm -f $(OBJ)
				rm -f $(NAME)

re: 			fclean all

%.all:
	@make -C $*

%.clean:
	make -C $* clean

%.fclean: clean
	rm -f $(LFT)