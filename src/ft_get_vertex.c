/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:43:02 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 19:07:58 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	ft_free_tab(char **tab, int i, int res)
{
	while (i)
	{
		free(tab[--i]);
		tab[i] = NULL;
	}
	free(tab);
	return (res);
}

static void	ft_add_vertex_by_index(t_graph *graph, t_vertex *vertex, int *index)
{
	if (*index == -2 || *index == 0)
		ft_add_vertex_back(graph, vertex);
	else
		ft_add_vertex_front(graph, vertex);
	*index += 2;
}

int	ft_get_new_vertex(t_graph *graph, char *buf, int *index)
{
	char		**v_info;
	t_vertex	*vertex;
	int 		x;
	int 		y;

	if (buf[0] == 'L' || ft_count_char(buf, ' ') != 2)
		return (1);
	if (!(v_info = ft_strsplit(buf, ' ')))
		return (1);
	if (((x = ft_get_valid_nbr(v_info[1])) < 0) || \
		((y = ft_get_valid_nbr(v_info[2])) < 0))
		return (ft_free_tab(v_info, 3, 1));
	if (ft_find_vertex_by_coo(graph, x, y))
		return (ft_free_tab(v_info, 3, 1));
	if (ft_find_vertex_by_name(graph, v_info[0]))
		return (ft_free_tab(v_info, 3, 1));
	vertex = ft_new_verex(index[0], v_info[0]);
	vertex->x = x;
	vertex->y = y;
	ft_add_vertex_by_index(graph, vertex, index);
	return (ft_free_tab(v_info, 3, 0));
}

static int	ft_get_start_end(t_graph *graph, char **buf, int fd, char **map)
{
	int			status;

	status = !(ft_strcmp(*buf, START)) ? 0 : 1;
	status = !(ft_strcmp(*buf, END)) ? -2 : status;
	if (status == 1)
		return (0);
	if (status == 0 && ft_find_vertex_by_id(graph, 0))
		return (1);
	if (status == -2 && ft_find_vertex_by_id(graph, -2))
		return (1);
	ft_add_line(map, buf);
	if (!get_next_line(fd, buf) || !ft_strlen(*buf))
		return (1);
	status = ft_get_new_vertex(graph, *buf, &status);
	return (status);
}

char		*ft_get_vertex(t_graph *graph, int fd, char **map)
{
	char	*buf;
	int		next_index;
	int		err;

	next_index = 2;
	err = 0;
	while (get_next_line(fd, &buf) && \
			ft_strlen(buf) && (buf[0] == '#' || ft_strchr(buf, ' ')))
	{
		if (buf[0] != '#')
			err = ft_get_new_vertex(graph, buf, &next_index);
		else if (buf[0] == '#' && buf[1] != '#')
		{
			ft_add_line(map, &buf);
			continue;
		}
		else
			err = ft_get_start_end(graph, &buf, fd, map);
		ft_add_line(map, &buf);
		if (err)
			return (NULL);
	}
	if (!ft_find_vertex_by_id(graph, 0) || !ft_find_vertex_by_id(graph, -2))
		return (NULL);
	return (buf);
}
