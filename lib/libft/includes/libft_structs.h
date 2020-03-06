/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:15:25 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:17:54 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H
# include <string.h>

typedef struct				s_tree
{
	void					*content;
	struct s_tree			*left;
	struct s_tree			*right;
	size_t					content_size;

}							t_tree;

typedef struct				s_forward_list
{
	void					*content;
	struct s_forward_list	*next;
	size_t					content_size;
}							t_forward_list;

typedef struct				s_list
{
	void					*content;
	struct s_list			*next;
	struct s_list			*prev;
	size_t					content_size;
}							t_list;

typedef struct				s_heap
{
	int						key;
	int						dist;
	struct s_heap			*left;
	struct s_heap			*right;
	void					*value;
	size_t					content_size;
}							t_heap;

typedef struct				s_mem
{
	char					*current;
	char					*end;
	char					*endl;
	char					*head;
	size_t					size;
}							t_mem;

typedef struct				s_hash
{
	size_t					key;
	size_t					index;
	void					*value;
	struct s_hash			*next;
}							t_hash;

typedef struct				s_set
{
	t_hash					*hashtab;
	size_t					size;
	size_t					capacity;
}							t_set;
#endif
