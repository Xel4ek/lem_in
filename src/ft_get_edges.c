/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:41 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:44:22 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int 		ft_get_new_edge(t_mem *mem, t_set *vset)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;
	char		*second_name;
	char		*first_name;

	if (ft_count_char(mem->current, '-') != 1 || \
				ft_count_char(mem->current, ' ') > 0)
		return (-11);
	second_name = ft_strchr(mem->current, '-');
	*second_name++ = 0;
	first_name = mem->current;
	vertex1 = ft_set_get_vertex(vset, first_name);
	vertex2 = ft_set_get_vertex(vset, second_name);
	if (vertex1 == NULL || vertex2 == NULL)
		return (-12);
	if (vertex1 == vertex2)
	{
		*(--second_name) = '-';
		return (1);
	}
	ft_add_edge(vertex1, vertex2, 8);
	*(--second_name) = '-';
	return (1);
}

int				ft_get_edges(t_mem *mem, t_set *vset)
{
	int	res;

	res = 1;
	while (mem->current[0])
	{
		if (mem->current[0] != '#' && ft_strchr(mem->current, ' '))
			res = -11;
		else if (mem->current[0] != '#')
			res = ft_get_new_edge(mem, vset);
		else if (mem->current[1] != '#')
		{
			ft_get_next_pointer(mem);
			continue ;
		}
		else if (!ft_strcmp(START, mem->current) || \
				!ft_strcmp(END, mem->current))
			res = -8;
		if (res <= 0)
			break ;
		ft_get_next_pointer(mem);
	}
	return (res);
}