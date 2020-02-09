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
	size_t					content_size;
	struct s_tree			*left;
	struct s_tree			*right;

}							t_tree;

typedef struct				s_forward_list
{	void					*content;
	size_t					content_size;
	struct s_forward_list	*next;
}							t_forward_list;

typedef struct				s_list
{	void					*content;
	size_t					content_size;
	struct s_list			*next;
	struct s_list			*prev;
}							t_list;

#endif
