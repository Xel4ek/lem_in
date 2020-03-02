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

static int ft_free_tab(char **tab, int i, int res)
{
	while (i)
	{
		free(tab[--i]);
		tab[i] = NULL;
	}
	free(tab);
	return (res);
}

static int
ft_get_new_vertex(t_graph *graph, char *buf, int *index, t_hptrs *hptrs)
{
	char		**vi;
	t_vertex	*vertex;
	t_coord		coord;

	if (buf[0] == 'L' || ft_count_char(buf, ' ') != 2)
		return (1);
	if (!(vi = ft_strsplit(buf, ' ')))
		return (1);
	if (((coord.x = ft_get_valid_nbr(vi[1])) < 0) ||
		((coord.y = ft_get_valid_nbr(vi[2])) < 0))
		return (ft_free_tab(vi, 3, 1));
	if (ft_find_coord_in_hash(hptrs->chash, &coord))
		return (ft_free_tab(vi, 3, 1));
	if (ft_find_vertex_in_hash(hptrs->vhash, vi[0], ft_hash(vi[0], HASH_SIZE)))
		return (ft_free_tab(vi, 3, 1));
	vertex = ft_new_verex(index[0], vi[0]);
	vertex->x = coord.x;
	vertex->y = coord.y;
	vertex = ft_add_vertex_back(graph, vertex);
	//vertex = ft_add_vertex_by_index(graph, &vertex, index);
	ft_add_to_hash(hptrs->vhash, (void *)vertex, (void *)vertex->name, \
	ft_hash(vertex->name, HASH_SIZE));
	ft_add_to_coord_hash(hptrs->chash, (void *)vertex, &coord);
	return (ft_free_tab(vi, 3, 0));
}

static int
ft_get_start_end(t_graph *graph, char **buf, t_map *map, t_hptrs *hptrs)
{
	int status;

	status = !(ft_strcmp(*buf, START)) ? 0 : 1;
	status = !(ft_strcmp(*buf, END)) ? -2 : status;
	if (status == 1)
		return (0);
	if (status == 0 && ft_find_vertex_by_id(graph, 0))
		return (1);
	if (status == -2 && ft_find_vertex_by_id(graph, -2))
		return (1);
	ft_add_to_map(map, buf, ft_strlen(*buf));
	if (!(get_next_line(map->fd, buf) && **buf))
		return (1);
	status = ft_get_new_vertex(graph, *buf, &status, hptrs);
	return (status);
}

char *ft_get_vertex(t_graph *graph, t_map *map, t_hptrs *hptrs)
{
	char *buf;
	int next_index;
	int err;
	int len;

	next_index = 2;
	err = 0;
	if (!(hptrs->chash = ft_init_hash(HASH_SIZE)))
		return (NULL);
	while (get_next_line(map->fd, &buf) && (len = ft_strlen(buf)) && \
            (buf[0] == '#' || ft_strchr(buf, ' ')))
	{
		if (buf[0] != '#')
			err = ft_get_new_vertex(graph, buf, &next_index, hptrs);
		else if (buf[1] == '#')
				err = ft_get_start_end(graph, &buf, map, hptrs);
		ft_add_to_map(map, &buf, ft_strlen(buf));
		if (err)
//			break ;
			return (NULL);
	}
	//ft_delete_coord_hash(hptrs->chash, 0);
	return (buf);
}


