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

int			ft_get_edges(t_graph *graph, char *buf, t_map *map, t_hash **hashtab)
{
	char	*name1;
	char	*name2;
	int 	len;
	t_list	*edge_list;

	edge_list = NULL;
	while (buf && (len = ft_strlen(buf)))
	{
		if (buf[0] != '#')
		{
			if (ft_count_char(buf, '-') != 1)
				return (0);
			name1 = ft_strsub(buf, 0, ft_char_in_str(buf, '-'));
			name2 = ft_strsub(buf, ft_char_in_str(buf, '-') + 1, \
					ft_strlen(ft_strchr(buf, '-')));
			if (!ft_check_n_add_edge(&name1, &name2, &edge_list, graph, hashtab))
				return (0);
		}
		ft_add_to_map(map, &buf, len);
		get_next_line(map->fd, &buf);
	}
	ft_add_to_map(map, &buf, len);
	ft_lstd_del(&edge_list);
	return (1);
}
