/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:43:02 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:26 by ayooden          ###   ########.fr       */
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
ft_get_new_vertex(t_graph *graph, char *buf, int index, t_hptrs *hptrs)
{
	char		**vi;
	t_vertex	*vertex;
	t_coord		coord;

	if (buf[0] == 'L' || ft_count_char(buf, ' ') != 2)
		return (-2);
	if (!(vi = ft_strsplit(buf, ' ')))
		return (0);
	if (((coord.x = ft_get_valid_nbr(vi[1])) < 0) ||
		((coord.y = ft_get_valid_nbr(vi[2])) < 0))
		return (ft_free_tab(vi, 3, -4));
	if (ft_find_coord_in_hash(hptrs->chash, &coord))
		return (ft_free_tab(vi, 3, -5));
	if (ft_find_vertex_in_hash(hptrs->vhash, vi[0], ft_hash(vi[0], HASH_SIZE)))
		return (ft_free_tab(vi, 3, -6));
	vertex = ft_new_verex(index, vi[0]);
	vertex->x = coord.x;
	vertex->y = coord.y;
	vertex = ft_add_vertex_back(graph, vertex);
	ft_add_to_hash(hptrs->vhash, (void *)vertex, (void *)vertex->name, \
	ft_hash(vertex->name, HASH_SIZE));
	ft_add_to_coord_hash(hptrs->chash, (void *)vertex, &coord);
	graph->source = (vertex->id == 0) ? vertex : graph->source;
	graph->sink = (vertex->id == -2) ? vertex : graph->sink;
	return (ft_free_tab(vi, 3, 1));
}

static int
ft_get_start_end(t_graph *graph, t_mem *mem, t_hptrs *hptrs)
{
	int status;

	status = !(ft_strcmp(mem->current, START)) ? 0 : 1;
	status = !(ft_strcmp(mem->current, END)) ? -2 : status;
	if (status == 1)
		return (1);
	if (status == 0 && graph->source)
		return (-7);
	if (status == -2 && graph->sink)
		return (-7);
	if (!ft_get_next_pointer(mem))
		return (-8);
	status = ft_get_new_vertex(graph, mem->current, status, hptrs);
	status = (status < 0) ? -8 : status;
	return (status);
}

int	ft_get_vertex(t_graph *graph, t_mem *mem, t_hptrs *hptrs)
{
	int next_index;
	int err;

	next_index = 2;
	err = -15;
	if (!(hptrs->chash = ft_init_hash(HASH_SIZE)))
		return (1);
	while (ft_get_next_pointer(mem) && (mem->current[0]) && \
            (mem->current[0] == '#' || ft_strchr(mem->current, ' ')))
	{
		err = 1;
		if (mem->current[0] != '#')
		{
			err = ft_get_new_vertex(graph, mem->current, next_index, hptrs);
			next_index += 2;
		}
		else if (mem->current[1] == '#')
			err = ft_get_start_end(graph, mem, hptrs);
		if (err <= 0)
			break ;
	}
	ft_delete_coord_hash(hptrs->chash, 0);
	return (err);
}


