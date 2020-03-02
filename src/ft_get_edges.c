/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:41 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 19:05:49 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int ft_clear_all(t_hash **edge_hash, int res)
{
	ft_delete_edge_hash(edge_hash, res);
	return (res);
}

t_edgename ft_get_names(char *buf)
{
	t_edgename e_names;

	e_names.name1 = ft_strsub(buf, 0, ft_char_in_str(buf, '-'));
	e_names.name2 = ft_strsub(buf, ft_char_in_str(buf, '-') + 1, \
					ft_strlen(ft_strchr(buf, '-')));
	return (e_names);
}

int			ft_get_edges(t_graph *graph, t_mem *mem, t_hash **htab)
{
	t_edgename	e_names;
	t_hash		**ehash;

	if (!(ehash = ft_init_hash(HASH_SIZE)))
		return (0);
	while (mem->current[0])
	{
		if (mem->current[0] != '#')
		{
			if (ft_count_char(mem->current, '-') != 1)
				return (ft_clear_all(ehash, 0));
			e_names = ft_get_names(mem->current);
			if (!ft_check_n_add_edge(&e_names, ehash, htab))
				return (ft_clear_all(ehash, 0));
		}
		else if (mem->current[1] != '#')
			;
		else if (!ft_strcmp(START, mem->current) || !ft_strcmp(END, mem->current))
			return (ft_clear_all(ehash, 0));
		ft_get_next_pointer(mem);
	}
	return (ft_delete_edge_hash(ehash, 1));
}
