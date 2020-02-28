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

static	int ft_clear_all(char **buf, t_hash **edge_hash, int res)
{
	if (!res)
		ft_memdel((void **)buf);
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

int			ft_get_edges(t_graph *graph, char *buf, t_map *map, t_hash **htab)
{
	t_edgename	e_names;
	int 		len;
	t_hash		**ehash;

	if (!(ehash = ft_init_hash(HASHTAB_SIZE)))
		return (0);
	while (buf && (len = ft_strlen(buf)))
	{
		if (buf[0] != '#')
		{
			if (ft_count_char(buf, '-') != 1)
				return (ft_clear_all(&buf, ehash, 0));
			e_names = ft_get_names(buf);
			if (!ft_check_n_add_edge(&e_names, ehash, graph, htab))
				return (ft_clear_all(&buf, ehash, 0));
		}
		else if (buf[1] != '#')
			;
		else if (!ft_strcmp(START, buf) || !ft_strcmp(END, buf))
			return (ft_clear_all(&buf, ehash, 0));
		ft_add_to_map(map, &buf, len);
		get_next_line(map->fd, &buf);
	}
	ft_add_to_map(map, &buf, len);
	return (ft_delete_edge_hash(ehash, 1));
}
