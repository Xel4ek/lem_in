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

void		ft_add_to_end(t_list **list, void **content, size_t size)
{
	t_list	*temp;

	if (!(*list))
		*list = ft_lstdnew(*content, size);
	else
	{
		temp = ft_lstdnew(*content, size);
		ft_lstd_push_back(list, temp);
	}
	ft_memdel((void **)content);
}

static int	ft_check_n_add_edge(char *name1, char *name2, t_list **list, \
			t_graph *graph)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;
	char		*concat;
	int			i;

	concat = ft_strjoin(name1, name2);
	i = ft_lstdlen(*list);
	while (i--)
	{
		if (!ft_strcmp(concat, (*list)->content))
		{
			ft_memdel((void **)&concat);
			return (1);
		}
		*list = (*list)->next;
	}
	if (!(vertex1 = ft_find_vertex_by_name(graph, name1)))
		return (0);
	if (!(vertex2 = ft_find_vertex_by_name(graph, name2)))
		return (0);
	ft_add_edge(vertex1, vertex2, 0, 0);
	ft_add_to_end(list, (void **)&concat, ft_strlen(concat));
	concat = ft_strjoin(name2, name1);
	ft_add_to_end(list, (void **)&concat, ft_strlen(concat));
	return (1);
}

int			ft_get_edges(t_graph *graph, char *buf, int fd)
{
	char	*name1;
	char	*name2;
	t_list	*edge_list;

	edge_list = NULL;
	while (buf && ft_strlen(buf))
	{
		if (buf[0] != '#')
		{
			if (ft_count_char(buf, '-') != 1)
				return (0);
			name1 = ft_strsub(buf, 0, ft_char_in_str(buf, '-'));
			name2 = ft_strsub(buf, ft_char_in_str(buf, '-') + 1, \
					ft_strlen(ft_strchr(buf, '-')));
			if (!ft_check_n_add_edge(name1, name2, &edge_list, graph))
				return (0);
		}
		ft_memdel((void **)&name1);
		ft_memdel((void **)&name2);
		ft_memdel((void **)&buf);
		get_next_line(fd, &buf);
	}
	ft_memdel((void **)&buf);
	ft_lstd_del(&edge_list);
	return (1);
}
