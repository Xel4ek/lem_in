/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:54 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:44:29 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <unistd.h>

int			ft_get_graph(t_graph *graph, t_mem *mem, int fd)
{
	t_set	*vset;
	int 	res;

	vset = NULL;
	res = 1;
	if (fast_read_in_memory(fd, mem) < 0)
		return (-3);
	if (mem->head[0] == 0)
		return (-14);
	if (res > 0)
		res = ft_get_ants_count(mem);
	graph->ants_count = res;
	if (res > 0)
		res = ft_get_vertex(graph, mem, &vset);
	if (!(graph->sink && graph->source) && res > 0)
		res = -10;
	if (!(mem->current[0]) && res > 0)
		res = -9;
	if (res > 0)
		res = ft_get_edges(mem, vset);
	ft_set_destroy(&vset);
	return (res);
}

