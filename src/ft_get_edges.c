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

static int ft_clear_all(t_hash_old **edge_hash, int res)
{
	ft_delete_edge_hash(edge_hash, res);
	return (res);
}

t_edgename ft_get_names(char *buf)
{
	t_edgename	e_names;
	int 		i;

	i = ft_char_in_str(buf, '-');
	e_names.name1 = NULL;
	e_names.name2 = NULL;
	if (i >= 0)
	{
		e_names.name1 = ft_strsub(buf, 0, i);
		e_names.name2 = ft_strsub(buf, i + 1, ft_strlen(buf + i));
	}
	return (e_names);
}

int			ft_get_edges(t_graph *graph, t_mem *mem, t_hash_old **htab)
{
	t_edgename	e_names;
	t_hash_old		**ehash;

	int 		res;

	if (!(ehash = ft_init_hash(HASH_SIZE)))
		return (0);
	while (mem->current[0])
	{
		if (mem->current[0] != '#')
		{
			if (ft_count_char(mem->current, '-') != 1 || \
				ft_count_char(mem->current, ' ') > 0)
				return (ft_clear_all(ehash, -11));
			e_names = ft_get_names(mem->current);
			if ((res = ft_check_n_add_edge(&e_names, ehash, htab)) <= 0)
				return (ft_clear_all(ehash, res));
		}
		else if (mem->current[1] != '#')
			;
		else if (!ft_strcmp(START, mem->current) || !ft_strcmp(END, mem->current))
			return (ft_clear_all(ehash, -8));
		ft_get_next_pointer(mem);
	}
	return (ft_delete_edge_hash(ehash, 1));
}

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
	ft_add_edge(vertex1, vertex2, 0, 0, 1);
	*(--second_name) = '-';
	return (1);
}


int				ft_get_edges_2(t_mem *mem, t_set *vset)
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